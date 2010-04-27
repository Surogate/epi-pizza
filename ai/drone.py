import traceback, random
from broadcast import BroadcastOut
import utils

class Drone:

    FOOD_CRITIC = 10
    FOOD_END_CRITIC = 30
    FOOD_OVERDOSE = 150
    _needs_tab = \
    {
            2: {'joueur': 1, 'linemate': 1, 'deraumere': 0, 'sibur': 0, 'mendiane': 0, 'phiras': 0, 'thystame': 0},
            3: {'joueur': 2, 'linemate': 1, 'deraumere': 1, 'sibur': 1, 'mendiane': 0, 'phiras': 0, 'thystame': 0},
            4: {'joueur': 2, 'linemate': 2, 'deraumere': 0, 'sibur': 1, 'mendiane': 0, 'phiras': 2, 'thystame': 0},
            5: {'joueur': 4, 'linemate': 1, 'deraumere': 1, 'sibur': 2, 'mendiane': 0, 'phiras': 1, 'thystame': 0},
            6: {'joueur': 4, 'linemate': 1, 'deraumere': 2, 'sibur': 1, 'mendiane': 3, 'phiras': 0, 'thystame': 0},
            7: {'joueur': 6, 'linemate': 1, 'deraumere': 2, 'sibur': 3, 'mendiane': 0, 'phiras': 1, 'thystame': 0},
            8: {'joueur': 6, 'linemate': 2, 'deraumere': 2, 'sibur': 2, 'mendiane': 2, 'phiras': 2, 'thystame': 1},
            9: {'joueur': 0, 'linemate': 0, 'deraumere': 0, 'sibur': 0, 'mendiane': 0, 'phiras': 0, 'thystame': 0}
    }

    _directions_needs = \
    {
            'go_ahead': (1, 2, 8),
            'turn_left': (3, 4, 5),
            'turn_right': (6, 7),
            'current_box': (0,)
    }

    def __init__(self, protocol, x, y, team):
        self.actions = \
        {
            'go_ahead':
            [
                {'action': 'see',                                       'score_f': lambda: 1}
            ],
            'turn_right':
            [
                {'action': 'see',                                       'score_f': lambda: 1}
            ],
            'turn_left':
            [
                {'action': 'see',                                       'score_f': lambda: 1}
            ],
            'see':
            [
                {'action': 'spell',                                     'score_f': self.spell_score},
                {'action': 'grab_object',   'param': 'nourriture',      'score_f': lambda: self.grab_score('nourriture')},
                {'action': 'go_ahead',                                  'score_f': lambda: self.move_score('go_ahead')},
                {'action': 'turn_right',                                'score_f': lambda: self.move_score('turn_right')},
                {'action': 'turn_left',                                 'score_f': lambda: self.move_score('turn_left')},
                {'action': 'drop_object',   'param': 'linemate',        'score_f': lambda: self.drop_score('linemate')},
                {'action': 'drop_object',   'param': 'deraumere',       'score_f': lambda: self.drop_score('deraumere')},
                {'action': 'drop_object',   'param': 'sibur',           'score_f': lambda: self.drop_score('sibur')},
                {'action': 'drop_object',   'param': 'mendiane',        'score_f': lambda: self.drop_score('mendiane')},
                {'action': 'drop_object',   'param': 'phiras',          'score_f': lambda: self.drop_score('phiras')},
                {'action': 'drop_object',   'param': 'thystame',        'score_f': lambda: self.drop_score('thystame')},
                {'action': 'grab_object',   'param': 'linemate',        'score_f': lambda: self.grab_score('linemate')},
                {'action': 'grab_object',   'param': 'deraumere',       'score_f': lambda: self.grab_score('deraumere')},
                {'action': 'grab_object',   'param': 'sibur',           'score_f': lambda: self.grab_score('sibur')},
                {'action': 'grab_object',   'param': 'mendiane',        'score_f': lambda: self.grab_score('mendiane')},
                {'action': 'grab_object',   'param': 'phiras',          'score_f': lambda: self.grab_score('phiras')},
                {'action': 'grab_object',   'param': 'thystame',        'score_f': lambda: self.grab_score('thystame')},
                {'action': 'cry',           'param': self.census_msg,   'score_f': lambda: self.unit_score('cry')},
                {'action': 'get_inventory',                             'score_f': lambda: self.unit_score('get_inventory')},
                {'action': 'fork',                                      'score_f': lambda: self.unit_score('fork')},
                {'action': 'kick',                                      'score_f': self.kick_score},
            ],
            'get_inventory':
            [
                {'action': 'see',                                       'score_f': lambda: self.unit_score('see')},
            ],
            'fork':
            [
                {'action': 'get_inventory',                             'score_f': lambda: self.unit_score('get_inventory')}
            ],
            'grab_object':
            [
                {'action': 'get_inventory',                             'score_f': lambda: self.unit_score('get_inventory')}
            ],
            'drop_object':
            [
                {'action': 'get_inventory',                             'score_f': lambda: self.unit_score('get_inventory')}
            ],
            'spell':
            [
                {'action': 'get_inventory',                             'score_f': lambda: self.unit_score('get_inventory')}
            ],
            'cry':
            [
                {'action': 'get_inventory',                             'score_f': lambda: self.unit_score('get_inventory')},
                {'action': 'cry',           'param': self.census_msg,   'score_f': lambda: self.unit_score('cry')}
            ],
            'kick':
            [
                {'action': 'see',                                       'score_f': lambda: self.unit_score('see')},
            ]
        }
        (self.protocol, self.x, self.y, self.team) = (protocol, x, y, team)
        self.id = utils.get_id()
        self.level = 1
        self.inventory = {}
        self.last_action = 'get_inventory'
        self.view = [[[]]]
        self.starvation = True
        self.action_count = 0
        self.census = {}
        self.unit_actions = {'cry': 0, 'see': 0, 'fork': 0, 'get_inventory': 0, 'expulse': 0}
        self.volatile_path = []
        self.leader = None

#### SCORES

    def unit_score(self, action):
        return self.unit_actions[action]

    def grab_score(self, item):
        if item == 'nourriture' and 'nourriture' in self.view[0][0] and self.inventory.get('nourriture', 0) < self.FOOD_OVERDOSE:
            return 100
        if not item in self.view[0][0] or self.starvation:
            return None
        if item in ('linemate', 'deraumere', 'sibur', 'mendiane', 'phiras', 'thystame'):
            if self.has_capacity_to_spell():
                if self.item_spell_needs[item] < 0 and not self.leader:
                    return 90
            else:
                if self.inventory.get(item, 0) < self._needs_tab[self.next_lvl][item] and not self.leader:
                    return 90
        return None

    def drop_score(self, item):
        if self.has_capacity_to_spell():
            if self.item_spell_needs[item] > 0 and not self.leader:
                return 90
        return None

    def spell_score(self):
        if self.inventory.get('nourriture', 0) < self.FOOD_CRITIC:
            return None
        if self.can_spell_now():
            return 100
        return None

    def move_score(self, request):
        if self.starvation:
            if self.volatile_path and request == self.volatile_path[0]:
                return 90
            if request == 'go_ahead':
                return 90
            return None
        if self.leader:
            if self.census[self.leader]['direction'] == 0:
                return None
            if self.census[self.leader]['direction'] in self._directions_needs[request]:
                return 99
        else:
            if self.leader_factor >= 0:
                return None
        if self.has_capacity_to_spell():
            return None
        if self.can_spell_now():
            return None
        return random.randint(10, 30)

    def kick_score(self):
        if self.has_capacity_to_spell() and self.item_spell_needs['joueur'] < 0:
            self.unit_actions['kick'] += 20
        else:
            self.unit_actions['kick'] = 0
        if self.unit_actions['kick']:
            return self.unit_actions['kick']
        return None

#### EVENTS

    def on_forced_move(self, data):
        pass

    def on_elevation(self, data):
        pass

    def on_levelup(self, lvl):
        self.level = lvl
        self.protocol.print_action('level up!')

    def on_fail(self):
        pass

    def on_incoming_message(self, msg):
        self.protocol.print_action('<<< [%s] from %d' % (utils.get_colored_text('cyan', str(msg.value)), msg.direction))
        if msg.team != self.team:
            return
        drone_info = \
        {
            'direction': msg.direction,
            'level': msg.level,
            'leader_factor': msg.leader_factor,
            'food': msg.food,
            'age': msg.age
        }
        self.census[msg.source_id] = drone_info
        self.bootstrap_set_leader()

#### BOOTSTRAP

    def bootstrap(self):
        self.bootstrap_check_starvation()
        self.bootstrap_set_volatile_path()
        self.item_spell_needs = self.bootstrap_get_item_spell_needs()
        self.bootstrap_set_leader()
        self.unit_actions['see'] += 15
        self.unit_actions['cry'] += 8
        if self.has_capacity_to_spell() and not self.starvation:
            self.unit_actions['cry'] += 20
        if len(self.census.keys()) < 8:
            self.unit_actions['fork'] += 0.3
        else:
            self.unit_actions['fork'] = 0
        self.unit_actions['get_inventory'] += 5
        if self.last_action in self.unit_actions:
            self.unit_actions[self.last_action] = 0

    def bootstrap_set_volatile_path(self):
        if self.last_action in ('go_ahead', 'turn_right', 'turn_left'):
            if self.volatile_path and self.last_action == self.volatile_path[0]:
                self.volatile_path = self.volatile_path[1:]
            else:
                self.volatile_path = []
            return
        if not self.starvation or self.volatile_path or len(self.view) < 2:
            return
        if not 'nourriture' in self.view[0][0]:
            self.volatile_path = ['go_ahead']
            food_left = self.view[1][0].count('nourriture')
            food_right = self.view[1][2].count('nourriture')
            if not food_left and not food_right:
                return
            if food_left > food_right:
                self.volatile_path += ['turn_left']
            else:
                self.volatile_path += ['turn_right']
            self.volatile_path += ['go_ahead']

    def bootstrap_set_leader(self):
        self.leader_factor = self.bootstrap_get_leader_factor()
        self.census[self.id] = \
        {
            'direction': 0,
            'level': self.level,
            'leader_factor': self.leader_factor,
            'food': self.inventory.get('nourriture', 0),
            'age': self.action_count
        }
        leader = None
        for (drone_id, data) in self.census.items():
            if data['level'] != self.level or data['leader_factor'] is None:
                if self.leader == drone_id:
                    self.leader = None
                continue
            if data['leader_factor'] >= 0:
                if leader:
                    if data['food'] < self.census[leader]['food']:
                        continue
                    if data['age'] < self.census[leader]['age']:
                        continue
                leader = drone_id
        if leader:
            if leader == self.id:
                self.leader = None
            else:
                self.leader = leader

    def bootstrap_check_starvation(self):
        actual = self.inventory.get('nourriture', 0)
        if actual < self.FOOD_CRITIC:
            self.starvation = True
        if actual >= self.FOOD_END_CRITIC:
            self.starvation = False

    def bootstrap_get_leader_factor(self):
        if self.starvation:
            return None
        if self.has_capacity_to_spell():
            return self.item_spell_needs['joueur']
        return None

    def bootstrap_get_item_spell_needs(self):
        item_spell_needs = {}
        for item_name in self._needs_tab[self.next_lvl].keys():
            nb_item_on_box = self.view[0][0].count(item_name)
            need = self._needs_tab[self.level + 1][item_name]
            spell_need = need - nb_item_on_box
            item_spell_needs[item_name] = spell_need
        return item_spell_needs

#### ACTION ENGINE

    def do_something(self):
        self.bootstrap()
        next = None
        for action in self.actions[self.last_action]:
            score = action['score_f']()
            if score is not None and (next is None or score >= next['score']):
                next = {'action': action['action'], 'score': score}
                next['param'] = action.get('param', None)
                if callable(next['param']):
                    next['param'] = next['param']()
        assert(next)
        self.do_action(next['action'], next['param'])

    def do_action(self, action, data=None):
        self.protocol.do_action(action, data)
        self.last_action = action
        self.action_count += 1

#### MISC

    @property
    def next_lvl(self):
        return self.level + 1

    def census_msg(self):
        msg = BroadcastOut()
        msg.source_id = self.id
        msg.team = self.team
        msg.level = self.level
        msg.leader_factor = self.leader_factor
        msg.food = self.inventory.get('nourriture', 0)
        msg.age = self.action_count
        return msg.format_from_data()

    def can_spell_now(self):
        for (item, need) in self.item_spell_needs.items():
            if need != 0:
                return False
        return True

    def has_capacity_to_spell(self):
        for (item, need) in self.item_spell_needs.items():
            if item == 'joueur':
                continue
            if need - self.inventory.get(item, 0) > 0:
                return False
        return True
