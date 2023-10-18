class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> v;
    int ind = 0;
    RandomizedSet() {
        ind = 0;
        v.clear();
        mp.clear();
    }
    
    bool insert(int val) {
        // if(st.find(val) != st.end()){
        //     return false;
        // }
        // else{
        //     st.insert(val);
        //     return true;
        // }

        if(mp.find(val) != mp.end()) return false;

        mp[val] = ind++;
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        // if(st.find(val) != st.end()){
        //     st.erase(val);
        //     return true;
        // }
        // else{
        //     return false;
        // }


        if(mp.find(val) == mp.end()) return false;

        int i = mp[val];
        swap(v[i], v[ind-1]);
        mp[v[i]] = i;

        v.pop_back();
        ind--;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        // int r = rand()%st.size();
        // auto it = st.begin();
        // advance(it, r);
        // return *(it);

        int r = rand()%ind;
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */