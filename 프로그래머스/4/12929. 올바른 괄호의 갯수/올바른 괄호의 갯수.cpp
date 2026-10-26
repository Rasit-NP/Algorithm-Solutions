# include <vector>
using namespace std;

int n;
int res;
int left;
int right;

void backTrack(){
    if (left == n && right == n){
        ++res;
        return;
    }
    
    if (left < n){
        ++left;
        backTrack();
        --left;
    }
    
    if (right < n){
        if (left > right){
            ++right;
            backTrack();
            --right;
        }
    }
}

int solution(int N) {
    n = N;
    res = 0;
    left = 0;
    right = 0;
    
    backTrack();
        
    return res;
}