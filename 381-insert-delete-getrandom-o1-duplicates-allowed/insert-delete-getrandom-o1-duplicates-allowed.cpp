class RandomizedCollection {
public:
    unordered_map<int, set<int> > mp;
    vector<int> v;
    int size = 0;
    RandomizedCollection() {
        size = 0;
        v.clear();
        mp.clear();
    }
    
    bool insert(int val) {
        mp[val].insert(size);
        v.push_back(val);
        size++;

        if(mp[val].size() == 1) return true;
        return false;
    }
    
    bool remove(int val) {
        auto it = mp.find(val);

        if(it != mp.end()){
            auto pos = *it->second.begin();
            it->second.erase(it->second.begin());

            v[pos] = v.back();
            mp[v.back()].insert(pos);
            mp[v.back()].erase(size - 1);
            v.pop_back();
            size--;

            if(it->second.size() == 0){
                mp.erase(it);
            }
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int r = rand()%size;
        return v[r];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */