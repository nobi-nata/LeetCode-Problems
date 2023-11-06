class SeatManager {
public:
    // vector<int> v;
    int s;

    priority_queue<int, vector<int> , greater<int> > pq;
    SeatManager(int n) {
        // v.resize(n, 0);
        pq.push(1);
        s = n;
    }
    
    int reserve() {
        // for(int i = 0; i < s; i++){
        //     if(v[i] == 0){
        //         v[i] = 1;
        //         return i+1;
        //     }
        // }
        int r = pq.top();
        pq.pop();
        if(pq.size() == 0){
            pq.push(r+1);
        }
        return r;
    }
    
    void unreserve(int seatNumber) {
        // v[seatNumber-1] = 0;
        pq.push(seatNumber);
        return;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */