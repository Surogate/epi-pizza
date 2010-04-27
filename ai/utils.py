import os, socket, traceback, sys

def get_id():
    return '%s-%s' % (os.getpid(), socket.gethostname())

term = False

colors = \
{
    'black': '\033[0;30m',
    'red': '\033[0;31m',
    'green': '\033[0;32m',
    'brown': '\033[0;33m',
    'blue': '\033[0;34m',
    'purple': '\033[0;35m',
    'cyan': '\033[0;36m',
    'gray': '\033[1;30m',
    'yellow': '\033[1;33m',
    'white': '\033[1;37m',
    'lgray': '\033[0;37m',
    'lblue': '\033[1;34m',
    'lgreen': '\033[1;32m',
    'lcyan': '\033[1;36m',
    'lred': '\033[1;31m',
    'lpurple': '\033[1;35m',
    'def': '\033[0m'
}

def get_colored_text(id, text, clean=True):
    text = colors[id] + text
    if clean:
        text += colors['def']
    return text
