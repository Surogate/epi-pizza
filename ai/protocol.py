import socket, traceback, os, sys, utils, pprint
from drone import Drone
from broadcast import BroadcastIn

class Protocol:

    _ACTIONS = \
    {
        # id | cmd | description # time
        'go_ahead': ('avance', 'going ahead', 7),
        'turn_right': ('droite', 'turning right', 7),
        'turn_left': ('gauche', 'turning left', 7),
        'get_inventory': ('inventaire', 'inventory ?', 1),
        'see': ('voir', 'opening eyes', 7),
        'grab_object': ('prend %s', 'grabbing %s', 7),
        'drop_object': ('pose %s', 'dropping %s', 7),
        'kick': ('expulse', 'kicking', 7),
        'cry': ('broadcast %s', 'crying "%s"', 7),
        'spell': ('incantation', 'hoyo... hoyo... hoyo...', 300),
        'fork': ('connect_nbr', 'forking (maybe)', 42),
        'real_fork': ('fork', 'forking (real)', 0),
    }

    def __init__(self, host, port, team):
        self.host = host
        self.port = port
        self.team = team
        (self.nbconnect, self.map_x, self.map_y) = (-1, -1, -1)
        self.drone = None
        self.real_fork_timer = None
        self.s = socket.socket()

    def print_action(self, desc):
        info = '[%s]' % utils.get_colored_text('lpurple', utils.get_id())
        if self.drone:
            info += ' [level=%s]' % utils.get_colored_text('yellow', str(self.drone.level))
            if self.drone.leader:
                info += ' [leader=%s]' % utils.get_colored_text('yellow', self.drone.leader)
            if self.drone.starvation:
                info += ' [%s]' % utils.get_colored_text('lblue', 'starvation')
            info += ' [health=%s]' % utils.get_colored_text('lred', str(self.drone.inventory.get('nourriture', 0)))
            if self.real_fork_timer:
                info += ' [birth t=-%s]' % utils.get_colored_text('lgreen', str(self.real_fork_timer))
        print('%s %s' % (info, desc))

    def send_msg(self, msg):
        #print('> %s' % msg)
        self.s.send('%s\n' % msg)

    def recv_line(self):
        filesocket = self.s.makefile()
        for line in filesocket:
            line = line.strip()
            #print('< %s' % line)
            yield line

    def do_action(self, id, data=None):
        assert(id in Protocol._ACTIONS)
        self.last_cmd = id
        (cmd, desc, t) = Protocol._ACTIONS[id]
        if self.real_fork_timer is not None:
            self.real_fork_timer -= t
            if self.real_fork_timer <= 0:
                self.real_fork_timer = None
                args = sys.argv
                if utils.term:
                    args = [utils.term, '-e'] + args
                os.spawnv(os.P_NOWAIT, args[0], args)
        if data:
            desc %= data
        self.print_action(desc)
        msg = cmd if data is None else cmd % data
        self.send_msg(msg)

    def connect(self):
        print('[+] Connection')
        self.s.settimeout(3)
        self.s.connect((self.host, self.port))
        next_cmd = 'waiting_welcome'
        for line in self.recv_line():
            print(' |-- %s' % line)
            if next_cmd == 'waiting_welcome':
                if line == 'BIENVENUE':
                    self.send_msg(self.team)
                    next_cmd = 'waiting_nbconnect'
                    continue
                raise Exception('It seems we are not welcome... :(')
            if next_cmd == 'waiting_nbconnect':
                if line != 'ko':
                    self.nbconnect = int(line)
                    next_cmd = 'waiting_mapinfo'
                    continue
                raise Exception('Invalid team')
            if next_cmd == 'waiting_mapinfo':
                (self.map_x, self.map_y) = [int(i) for i in line.split()]
                self.drone = Drone(self, self.map_x, self.map_y, self.team)
                break
        assert(self.drone)
        self.s.settimeout(None)
        print(' `-- Connection OK\n')

    def run(self):
        self.connect()
        self.drone.do_something()
        for line in self.recv_line():

            # Unespected events
            if line.startswith('mort'):
                self.print_action("I'm dead. :-(")
                if utils.term:
                    raw_input('--- Press Enter to end ---')
            if line.startswith('deplacement'):
                self.drone.on_forced_move(line.split()[1:])
                continue
            if line.startswith('message'):
                data = line.split(',')
                (key, K) = data[0].split()
                msg = BroadcastIn(data[1].lstrip(), K)
                if msg.direction is not None:
                    self.drone.on_incoming_message(msg)
                continue
            if line.startswith('elevation'):
                self.drone.on_elevation(line.split()[1:])
                continue
            if line.startswith('niveau actuel :'):
                lvl = int(line.split()[-1])
                self.drone.on_levelup(lvl)
                self.drone.do_something()
                continue

            # Command return
            if line in ('ok', 'ko'):
                if line == 'ko':
                    self.drone.on_fail()
                if self.last_cmd in ('get_inventory' 'see'):
                    continue
                    #raise Exception('Fork?')

            # Inventory
            if self.last_cmd == 'get_inventory':
                inventory = self.drone.inventory
                for i in line[1:-1].split(','):
                    item, num = i.split()
                    inventory[item] = int(num)

            # Fork
            elif self.last_cmd == 'fork':
                if int(line) == 0:
                    self.do_action('real_fork')
                    self.real_fork_timer = 600
                    continue
                else:
                    self.real_fork_timer = 0

            # View
            elif self.last_cmd == 'see':
                view = []
                boxes = line[1:-1].split(',')
                i = 0
                box_to_insert = 1
                while i + box_to_insert <= len(boxes):
                    view.append([data.split() for data in boxes[i:i + box_to_insert]])
                    i += box_to_insert
                    box_to_insert += 2
                self.drone.view = view
                level = len(view) - 1
                if level != self.drone.level:
                    self.drone.level = level

            self.drone.do_something()
