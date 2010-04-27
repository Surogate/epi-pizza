#!/usr/bin/env python

import sys, optparse, utils, os, socket
from protocol import Protocol

class Core:

    def _getopts(self):
        parser = optparse.OptionParser()
        parser.add_option('-a', '--host', dest='host', help='host to connect', default='localhost')
        parser.add_option('-p', '--port', dest='port', type='int', help='port to use')
        parser.add_option('-n', '--team', dest='team', help='the team name')
        parser.add_option('-t', '--term', dest='term', help='set a terminal path (will be open for each new drone)', default=False)
        opts, args = parser.parse_args()
        if not (opts.host and opts.port and opts.team):
            parser.print_help()
            print('\nError: missing options.')
            print sys.exit(0)
        utils.term = opts.term
        return (opts.host, opts.port, opts.team)

    def run(self):
        (host, port, team) = self._getopts()
        try:
            self.protocol = Protocol(host, port, team)
            self.protocol.run()
        except (socket.error, socket.gaierror), (value, message):
            print('Connection error: %s (%d)' % (message, value))
        except Exception, e:
            print('Error: %s' % e)

if __name__ == '__main__':
    try:
        os.chdir(os.path.dirname(__file__))
        c = Core()
        c.run()
    except KeyboardInterrupt:
        print('\nQuitting...')
