class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> currlevel(1, poured);

        for(int i = 0; i < query_row; i++){
            vector<double> nextlevel(i+2, 0);

            for(int j = 0; j < currlevel.size(); j++){
                double rem = (currlevel[j] - 1)/2;

                if(rem > 0){
                    nextlevel[j] += rem;
                    nextlevel[j+1] += rem;
                }
            }

            currlevel = nextlevel;
        }

        return min(1.0, currlevel[query_glass]);
    }
};