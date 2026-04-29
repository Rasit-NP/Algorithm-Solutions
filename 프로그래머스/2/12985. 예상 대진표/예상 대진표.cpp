# include<iostream>
using namespace std;

int solution(int n, int a, int b){
    int ans = 0;
    
    --a;
    --b;
    
    a += n, b += n;
    
    while (a != b){
        a >>= 1;
        b >>= 1;
        ++ans;
    }

    return ans;
}