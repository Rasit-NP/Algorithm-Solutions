# include <vector>
# include <iostream>
using namespace std;

vector<bool> isPrime;

int solution(vector<int> nums) {
    int answer = 0;
    
    int sz = nums.size();

    isPrime.assign(3000, true);
    isPrime[0] = false, isPrime[1] = false;
    
    for (int i=2; i<=3000; i++){
        if (!isPrime[i])
            continue;
        for (int j=2*i; j<=3000; j+=i){
            isPrime[j] = false;
        }
    }
    
    for (int i=0; i<sz; i++){
        for (int j=i+1; j<sz; j++){
            for (int k=j+1; k<sz; k++){
                if (isPrime[nums[i] + nums[j] + nums[k]]){
                    answer += 1;
                }
            }
        }
    }

    return answer;
}