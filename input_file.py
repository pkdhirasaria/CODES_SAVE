from time import time
from tabulate import tabulate

inp = open(r'C:\Users\I505412\PycharmProjects\CP\input.txt', mode='r')
out = open(r'C:\Users\I505412\PycharmProjects\CP\output.txt', mode='w')
ass = open(r'C:\Users\I505412\PycharmProjects\CP\assert.txt', mode='r')

def input():
    return inp.readline()[:-1]

def assert_file():
    return ass.readline()[:-1]

def printf(*args):
    print(*args, file=out)
