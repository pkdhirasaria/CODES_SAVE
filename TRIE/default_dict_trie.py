from collections import defaultdict
from functools import reduce

T = lambda: defaultdict(T)

trie = T()

reduce(dict.__getitem__, 'he', trie)['word'] = 'he'


Output :

trie
Out: 
defaultdict(<function __main__.<lambda>()>,
            {'h': defaultdict(<function __main__.<lambda>()>,
                         {'e': defaultdict(<function __main__.<lambda>()>,
                                      {'word': 'he'})})})
