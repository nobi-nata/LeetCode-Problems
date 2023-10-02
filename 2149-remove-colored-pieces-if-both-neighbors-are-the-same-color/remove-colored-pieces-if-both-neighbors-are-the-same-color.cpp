class Solution {
public:
    bool winnerOfGame(string colors) {

        // priority_queue<int> cntA;
        // priority_queue<int> cntB;
        int cnt = 0;
        int cntofA = 0;
        int cntofB = 0;
        for(int i = 0; i < colors.size(); i++){
            if(colors[i] == 'A') cnt++;
            else{
                if(cnt){
                    // cout << cnt;
                    if(cnt >= 3){
                        cntofA += cnt-2;
                    }
                    // cntA.push(cnt);
                    cnt = 0;
                }
            }
        }
        if(cnt){
            // cout << cnt;
            if(cnt >= 3){
                cntofA += cnt-2;
            }
            // cntA.push(cnt);
            cnt = 0;
        }
        cnt = 0;
        for(int i = 0; i < colors.size(); i++){
            if(colors[i] == 'B') cnt++;
            else{
                if(cnt != 0){
                    // cout << cnt;
                    // cntB.push(cnt);
                    if(cnt >= 3) cntofB += cnt-2;
                    cnt = 0;
                }
            }
        }
        if(cnt != 0){
            if(cnt >= 3) cntofB += cnt-2;
            cnt = 0;;
        }
        // bool turn = true;
        // while(true){
        //     if(turn){
        //         if(!cntA.empty() && cntA.top() >= 3){ 
        //             int val = cntA.top();
        //             cntA.pop();
        //             cntA.push(val-1);
        //             turn = false;
        //             cout << 'a';
        //         }
        //         else return false;
                
        //     }
        //     else{
        //         if(!cntB.empty() && cntB.top() >= 3){ 
        //             int val = cntB.top();
        //             cntB.pop();
        //             cntB.push(val-1);
        //             turn = true;
        //         }
        //         else return true;
        //         cout << 'a';
        //     }
        // }
        // return true;



        // int cntofA = 0;
        // int cntofB = 0;

        // while(!cntA.empty() && cntA.top() >= 3){
        //     int val = cntA.top();
        //     cntA.pop();
        //     cntofA += val-2;
        // }
        // while(!cntB.empty() && cntB.top() >= 3){
        //     int val = cntB.top();
        //     cntB.pop();
        //     cntofB += val-2;
        // }
        if(cntofA > cntofB) return true;
        return false;
    }
};