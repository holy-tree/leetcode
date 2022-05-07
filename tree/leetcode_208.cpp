class Trie {
public:
    set<string> st;
    set<string> prest;
    Trie() {

    }
    
    void insert(string word) {
        st.insert(word);
        for(int i = 1; i <= word.size(); i++){
            prest.insert(word.substr(0,i));
        }
    }
    
    bool search(string word) {
        if(st.count(word) == 0)
            return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        if(prest.count(prefix) == 0)
            return false;
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
