#include<iostream>
#include<map>
#include<string>
using namespace std;

class TrieNode {
public:
	map<char,TrieNode*>next;
	bool canFin;
    // Initialize your data structure here.
    TrieNode() 
	{
        canFin = false;
    }
};

class Trie {
public:
    Trie() 
	{
        root = new TrieNode();
    }

	~Trie()
	{
		delete root;
	}
    // Inserts a word into the trie.
    void insert(string word) 
	{
		TrieNode* p = root;
    	int i = 0;
    	while(i < word.size())
    	{
    		auto& m = p->next;
    		if(m.find(word[i]) == m.end())
    			m[word[i]] = new TrieNode();
			p = m[word[i]];
    		i++;
		}
		
		p->canFin = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) 
	{
        int i = 0;
        TrieNode *p = root;
        while(i < word.size())
        {
        	auto& m = p->next;
        	if(m.find(word[i]) != m.end())
        		p = m[word[i]];
        	else return false;
        	i++;
		}
		return p->canFin;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) 
	{
        int i = 0;
        string& word = prefix;
        TrieNode* p = root;
        while(i < word.size())
        {
        	auto& m = p->next;
        	if(m.find(word[i]) != m.end())
        		p = m[word[i]];
        	else return false;
        	i++;
		}
		return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
	Trie t;
	cout<<(t.search("")?"true":"false");
	t.insert("apple");
	cout<<(t.startsWith("a")?"true":"false");
	
}
