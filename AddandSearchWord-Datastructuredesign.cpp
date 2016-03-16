class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) 
	{
        
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        
    }
    
	class Trie 
	{
	public: 
		Trie()
		{
			root = new TrieNode();
		}
		
		~Trie()
		{
			delete root;
		}
		
		void insert(string word)
		{
			int i = 0;
			TrieNode* p = root;
			
		}
		//return the index of the first char which can not be matched in the Trie
		//if the whole word is matched, return the size of the word
		int  search(const string& word, int index = 0, TrieNode *p = root)
		{
			
		}
		
		bool find
		class TrieNode
		{
		public:
			map<char,TrieNode*>next;
			bool canFin;
			TrieNode():canFind(false)
			{}	
		};
	private:
		TrieNode *root;
	};
	
private:
	Trie t;		
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
