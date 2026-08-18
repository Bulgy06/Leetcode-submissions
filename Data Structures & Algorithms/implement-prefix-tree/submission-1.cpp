class PrefixTree {
private:
    struct TrieNode{
        TrieNode* children[26]={nullptr};
        bool isEnd=false;
    };
    TrieNode* root;
public:
    PrefixTree() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr=root;
        for(char c: word){
            int idx=c-'a';
            if(!curr->children[idx]) curr->children[idx]=new TrieNode();
            curr=curr->children[idx];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(char c: word){
            int idx=c-'a';
            if(!curr->children[idx]) return false;
            curr=curr->children[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(char c: prefix){
            int idx=c-'a';
            if(!curr->children[idx]) return false;
            curr=curr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */