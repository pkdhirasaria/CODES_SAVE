class Trie:

    def __init__(self):
        self.children = [None]*26
        self.isEnd = False
        self.keyname = str
        self.tweetCount = 0

    def insert(self, root, userName):
        currentNode = root

        for key in userName:
            index = ord(key) - ord('a')
            if not currentNode.children[index]:
                currentNode.children[index] = Trie()
            currentNode = currentNode.children[index]
        currentNode.keyname = userName
        currentNode.isEnd = Trie
        currentNode.tweetCount += 1

    def find_max_tweet(self, root, value):

        if root.tweetCount == value:
            print("%s %d" % (root.keyname, root.tweetCount))
            return

        for i in range(26):
            if root.children[i]:
                self.find_max_tweet(root.children[i], value)


for _ in range(int(input())):
    N = int(input())
    tweet = dict()
    maximumTweetValue = 0
    root = Trie()
    for i in range(N):
        s = input().split()
        tweet[s[0]] = tweet.get(s[0], 0) + 1
        if tweet[s[0]] > maximumTweetValue:
            maximumTweetValue = tweet[s[0]]
        root.insert(root, s[0])
    root.find_max_tweet(root, maximumTweetValue)
