import sys
class Node:
 
    def __init__(self):
        self.children = dict()
        self.isEnd = False
        self.keyname = str
        self.minlength = sys.maxsize
 
    def insert(self, root, webname):
        current_node = root
        if current_node.minlength > len(webname):
            current_node.minlength = len(webname)
 
        #print(webname)
        for key in webname:
            if key not in current_node.children:
                current_node.children[key] = Node()
 
            current_node = current_node.children[key]
            if current_node.minlength > len(webname):
                current_node.minlength = len(webname)
            #print("CUrrent for key %s : %d" % (key, current_node.minlength))
        current_node.isEnd = True
        current_node.keyname = webname
 
    def find_prefix(self, root, invalidpassword):
        current_node = root
        count = 0
        flag = 0
        ans = sys.maxsize
        #print(invalidpassword)
        for i in range(len(invalidpassword)):
            if invalidpassword[i] not in current_node.children:
                # print(current_node.minlength, end=" ")
                # print(count)
                ans = min(len(invalidpassword) + current_node.minlength - 2 * count, ans)
                flag = 1
                break
            count += 1
            current_node = current_node.children[invalidpassword[i]]
            ans = min(len(invalidpassword) + current_node.minlength - 2 * count, ans)
        #
        # if flag == 0:
        #     print(len(invalidpassword) + current_node.minlength - 2 * count)
        # else:
        print(ans)
 
 
    def traverse(self, current_node, count, ans):
 
        #current_node = root
        if current_node.isEnd:
            ans = min(count, len(current_node.keyname))
            return ans
 
        for key in current_node.children.keys():
            ans = self.traverse(current_node.children[key], count+1, ans)
 
        return ans
 
def main():
    N = int(input())
    root = Node()
    #print("INSERT ():")
    for _ in range(N):
        root.insert(root, input())
    N = int(input())
    #print("QUERY() :")
    for _ in range(N):
        root.find_prefix(root, input())
 
 
if __name__ == "__main__":
    main()
 
