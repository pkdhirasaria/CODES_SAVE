#include <bits/stdc++.h>
#define fr(a,b) for(i=a;i<b;i++)
#define rep(a,b) for(i=a;i>=b;i--)
#define f first
#define s second
#define input(a,n) fr(i,n) cin>>a[i]
//#define print(a,n) fr(i,n) {cout << a[i] << " ";} cout << endl
#define lli long long
#define ull unsigned long long
#define MOD 1000000007
using namespace std;

struct Trie
{
    struct Trie *children[26];
    bool isEndofWord;
    string word;
};
typedef struct Trie* TRIE;
struct Trie * getNode()
{
    struct Trie *temp = new Trie;
    temp->isEndofWord = false;
    temp->word = "";
    for(int i  = 0;i<26;i++)
    {
        temp->children[i] = NULL;
    }
    return temp;
}

void Insert(TRIE root,string key)
{
    TRIE temp = root;
    for(int i = 0;i<key.length();i++)
    {
        int index = key[i]-'a';
        if(!temp->children[index])
        {
            temp->children[index] = getNode();
        }
        temp= temp->children[index];
    }
    temp->isEndofWord = true;
    temp->word = key;
}

bool Search(TRIE root,string key)
{
    TRIE temp = root;
    for(int i = 0;i<key.length();i++)
    {
        int index = key[i] - 'a';
        if(!temp->children[index])
            return false;
        temp = temp->children[index];
    }
    return (temp!= NULL && temp->isEndofWord);
}

void print(TRIE root)
{
     TRIE temp = root;
    if(root->isEndofWord)
        cout<<root->word<<endl;
    for(int i= 0;i<26;i++)
    {
        if(temp->children[i])
            print(temp->children[i]);
    }

}

void Delete(TRIE root,)

int main()
{
   string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    TRIE root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        Insert(root, keys[i]);

    print(root);
    // Search for different keys
    Search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    Search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
    return 0;
	return 0;
}
