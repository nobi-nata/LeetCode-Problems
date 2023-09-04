class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        stack<int> m;
        int n = s.size();
        string ans = "";
        int i = 0;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch >= '0' && ch <= '9'){
                int num = 0;
                while(ch >= '0' && ch <= '9'){
                    num = num*10 + (ch - '0');
                    cout << num << ' ';
                    i++;
                    ch = s[i]; 
                }
                cout << num << ' ';
                m.push(num);
            }
            ch = s[i];
            if(ch == ']'){
                string temp = "";
                while(st.top() != '['){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                int no = m.top();
                m.pop();
                while(no){
                    for(auto i : temp){
                        st.push(i);
                    }
                    no--;
                }
            }
            else st.push(ch);
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
        //  stack<char> st;
        // stack<int> m;
        // string str;
        // string ans;
        // string  temp2;

        // for(int i=0;i<s.size();i++){
        //     char c = s[i];
        //     if(c >= '0' && c<='9'){
        //         temp2.push_back(c);
        //         for(int j=i+1;j<s.size();j++){
        //             char ch = s[j];
        //             if(ch >= '0' && ch<='9'){
        //                 temp2.push_back(ch);
        //             }
        //             else{
        //                 i=j-1;
        //                 break;
        //             }
        //         }
        //         int num = stoi(temp2);
        //         cout<<num<<endl;
        //         m.push(num);
        //         temp2.clear();
        //     }
        //     else if(c == ']'){
        //         int top = m.top();

        //         while(st.top()!='['){
        //             char c = st.top();
        //             str.push_back(c);
        //             st.pop();
        //         }
        //         st.pop();
        //         reverse(str.begin(),str.end());
        //         string temp = str;
        //         for(int i=1;i<top;i++){
        //             str = str + temp;
        //         }

        //         if(!st.empty()){
        //             for(int i=0;i<str.size();i++){
        //                 st.push(str[i]);
        //             }
        //         }
        //         else{
        //             ans = ans + str;
        //         }
        //         str.clear();
        //         m.pop();
        //     }
        //     else{
        //         st.push(c);
        //     }
        // }

        // string rest;
        // while(!st.empty()){
        //     char c = st.top();
        //     rest.push_back(c);
        //     st.pop();
        // }
        // reverse(rest.begin(),rest.end());
        
        // ans = ans + rest;

        // return ans;
    }
};