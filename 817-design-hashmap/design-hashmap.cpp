class MyHashMap {
public:
    // int num = 5;
    vector<int> v = vector<int> (1e6+1, -1);
    MyHashMap() {
        // vector<int> k(1e6+1, -1);
        
    }
    
    void put(int key, int value) {
        // k[key] = 1;
        v[key] = value;
    }
    
    int get(int key) {
        return v[key];
    }
    
    void remove(int key) {
        if(v[key] != -1) v[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */