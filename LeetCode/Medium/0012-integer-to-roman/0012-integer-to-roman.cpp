# include <string>

class Solution {
public:
    string intToRoman(int num) {
        string ans;

        for (int i=0; i<num/1000; i++){
            ans.push_back('M');
        }
        num %= 1000;

        if (num/100 == 9){
            ans.push_back('C');
            ans.push_back('M');
            num %= 100;
        }
        else if (num/100 >= 5){
            ans.push_back('D');
            num -= 500;
        }
        
        if (num/100 == 4){
            ans.push_back('C');
            ans.push_back('D');
            num %= 100;
        }
        else {
            for (int i=0; i<num/100; i++){
                ans.push_back('C');
            }
            num %= 100;
        }

        if (num/10 == 9){
            ans.push_back('X');
            ans.push_back('C');
            num %= 10;
        }
        else if (num/10 >= 5){
            ans.push_back('L');
            num -= 50;
        }
        
        if (num/10 == 4){
            ans.push_back('X');
            ans.push_back('L');
            num %= 10;
        }
        else {
            for (int i=0; i<num/10; i++){
                ans.push_back('X');
            }
            num %= 10;
        }

        if (num == 9){
            ans.push_back('I');
            ans.push_back('X');
            num = 0;
        }
        else if (num >= 5){
            ans.push_back('V');
            num -= 5;
        }

        if (num == 4){
            ans.push_back('I');
            ans.push_back('V');
        }
        else {
            for (int i=0; i<num; i++){
                ans.push_back('I');
            }
        }

        return ans;
    }
};