class RandomizedSet {
public:
    unordered_set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val) != st.end()){
            return false;
        }
        else{
            st.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(st.find(val) != st.end()){
            st.erase(val);
            return true;
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        int r = rand()%st.size();
        auto it = st.begin();
        advance(it, r);
        return *(it);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */