class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1 = v1.size();
        int n2 = v2.size();

        int i = 0;
        int j = 0;

        while(i < n1 || j < n2){
            string s1 = "";
            string s2 = "";

            while(i < n1 && v1[i] != '.'){
                // if(v1[i] != '0')
                s1 += v1[i];
                i++;
            }
            i++;
            while(j < n2 && v2[j] != '.'){
                // if(v2[j] != '0')
                s2 += v2[j];
                j++;
            }
            j++;
            if(s1.size() == 0) s1 = "0";
            if(s2.size() == 0) s2 = "0";
            int c1 = stoi(s1);
            int c2 = stoi(s2);
            cout << c1 <<" " << c2 << " ";
            if(c1 > c2) return 1;
            if(c1 < c2) return -1;
            cout << "i";

        }

        return 0;
    }
};