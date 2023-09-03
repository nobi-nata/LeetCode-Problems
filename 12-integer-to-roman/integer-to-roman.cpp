class Solution {
public:
    string intToRoman(int num) {
        
        string ans = "";
        while(num){
            if(num >= 1 && num <5){
                if(num < 4){
                    ans += 'I';
                    num -= 1;
                }
                else{
                    ans += "IV";
                    num -= 4;
                }
            }
            else if(num >= 5 && num < 10){
                if(num < 9){
                    ans += 'V';
                    num -= 5;
                }
                else{
                    ans += "IX";
                    num -= 9;
                }
            }
            else if(num >= 10 && num < 50){
                if(num < 40){
                    ans += 'X';
                    num -= 10;
                }
                else{
                    ans += "XL";
                    num -= 40;
                }
            }
            else if(num >= 50 && num <100){
                if(num < 90){
                    ans += 'L';
                    num -= 50;
                }
                else{
                    ans += "XC";
                    num -= 90;
                }
            }
            else if(num >=100 && num < 500){
                if(num < 400){
                    ans += 'C';
                    num -= 100;
                }
                else{
                    ans += "CD";
                    num -= 400;
                }
            }
            else if(num >= 500 && num < 1000){
                if(num < 900){
                    ans += 'D';
                    num -= 500;
                }
                else{
                    ans += "CM";
                    num -= 900;
                }
            }
            else if(num >= 1000){
                ans += 'M';
                num -= 1000; 
            }
        }
        return ans;
    }
};