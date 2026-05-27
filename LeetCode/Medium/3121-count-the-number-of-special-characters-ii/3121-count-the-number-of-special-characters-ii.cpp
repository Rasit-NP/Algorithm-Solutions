# include <string>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {

        int res = 0;
        int* state = (int*) malloc(26*sizeof(int));

        for (int i=0; i<26; i++){
            state[i] = 0;
        }
        
        for (char let : word){
            if (let < 'a'){
                int idx = let - 'A';
                if (state[idx] == 1){
                    state[idx] = 2;
                    ++res;
                }
                else if (state[idx] == 0){
                    state[idx] = 3;
                }
            }
            else {
                int idx = let - 'a';
                if (state[idx] == 0){
                    state[idx] = 1;
                }
                else if (state[idx] == 2){
                    state[idx] = 3;
                    --res;
                }
            }
        }

        return res;
    }
};