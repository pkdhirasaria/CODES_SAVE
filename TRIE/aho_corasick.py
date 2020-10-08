"""Aho Corasik Algorithm"""

from collections import deque


class Node:

    def __init__(self) -> object:
        self.children = dict()
        self.isEND = False
        self.fail = None


class Trie:

    def __init__(self):
        self.root = Node()

    def insert(self, words):
        current_node = self.root
        for w in words:
            if current_node.children.get(w, None) is None:
                current_node.children[w] = Node()
            current_node = current_node.children[w]

        current_node.isEND = True

    def built_failover(self):

        q = deque()
        current = self.root
        for ch in self.root.children:
            self.root.children[ch].fail = self.root
            q.append(self.root.children[ch])
        while q:
            node = q.popleft()
            for ch in node.children:
                q.append(node.children[ch])
                failover = node.fail
                while True:
                    if failover is None:
                        node.children[ch].fail = self.root
                        break
                    if ch in failover.children:
                        node.children[ch].fail = failover.children[ch]
                        break
                    else:
                        failover = failover.fail

    def substring(self, word):
        output = set()
        current = self.root
        n = len(word)
        i = 0
        while i < n:
            if word[i] in current.children:
                current = current.children[word[i]]
                if current.isEND:
                    output.add(current.word)
                    print(current.word, end=" ")
                    print(i - len(current.word) + 1)
                # if current.fail.isEND:
                #     output.add(current.fail.word)
                #     print(current.fail.word, end=" ")
                #     print(i - len(current.fail.word) + 1)
                i += 1
            else:
                if current.fail.isEND:
                    output.add(current.fail.word)
                    print(current.fail.word, end=" ")
                    print(i - len(current.fail.word))
                current = current.fail
                if word[i] not in current.children:
                    i += 1
            # if current.fail.isEND:
            #     output.add(current.fail.word)
            #     print(current.fail.word, end=" ")
            #     print(i - len(current.fail.word) + 1)

        print(output)

    def print(self, current_node):

        if current_node.isEND:
            print(current_node.word)

        for key in current_node.children.keys():
            self.print(current_node.children[key])
        return


trie = Trie()
words = ["his", "her", "she", "he", 'a']
for word in words:
    trie.insert(word)
trie.built_failover()
trie.root.fail = trie.root
trie.substring("ahishers")
