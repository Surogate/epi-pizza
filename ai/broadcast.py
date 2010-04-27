class Broadcast:

    def __init__(self):
        self.source_id = ''
        self.team = ''
        self.level = 0
        self.leader_factor = None
        self.food = 0
        self.age = 0
        self.value = None

class BroadcastOut(Broadcast):

    def format_from_data(self):
        leader_factor = 'x' if self.leader_factor is None else str(self.leader_factor)
        self.value = '%s|%s|%d|%s|%d|%d' % (self.source_id, self.team, self.level, leader_factor, self.food, self.age)
        return self.value

class BroadcastIn(Broadcast):

    def __init__(self, msg, direction):
        Broadcast.__init__(self)
        self.direction = int(direction)
        self.value = msg
        try:
            v = msg.split('|')
            self.source_id = v[0]
            self.team = v[1]
            self.level = int(v[2])
            self.leader_factor = None if v[3] == 'x' else int(v[3])
            self.food = int(v[4])
            self.age = int(v[5])
        except:
            self.direction = None
