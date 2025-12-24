# include <iostream>
# include <vector>
# include <string>
# include <unordered_map>
using namespace std;


int main(void){
    int n;          cin >> n;
    string word;    cin >> word;
    vector<int> datas = {0, 15, 19, 28, 38, 41, 53, 58};
    vector<int> final;
    unordered_map<int, char> print;
    print[0] = 'A';
    print[15] = 'B';
    print[19] = 'C';
    print[28] = 'D';
    print[38] = 'E';
    print[41] = 'F';
    print[53] = 'G';
    print[58] = 'H';
    for (int i=0; i<n; i++){
        string letter = word.substr(6*i, 6);
        int data = 0, base = 1;
        for (int j=5; j>=0; j--, base *= 2){
            if (letter[j] == '1'){
                data += base;
            }
        }
        if (print.find(data) != print.end()){
            final.push_back(data);
        }
        else {
            int real = -1;
            for (int candidate : datas){
                int diff = candidate ^ data;
                int cnt = 0, ans;
                for (int k=1; k<64; k <<= 1){
                    if (diff&k){
                        cnt += 1;
                        ans = candidate;
                    }
                    if (cnt > 1)    break;
                }
                if (cnt == 1){
                    real = ans;
                }
            }
            if (real >= 0){
                final.push_back(real);
            }
            else {
                cout << i + 1;
                return 0;
            }
        }
    }
    for (int real: final){
        cout << print[real];
    }
}