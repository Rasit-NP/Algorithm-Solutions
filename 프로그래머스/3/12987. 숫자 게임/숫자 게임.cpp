# include <vector>
# include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int bIdx = 0;
    int res = 0;
    
    for (int aIdx=0; aIdx<n; ++aIdx){
        int a = A[aIdx];
        
        while (bIdx < n && a >= B[bIdx]){
            ++bIdx;
        }

        if (bIdx < n && a < B[bIdx]){
            ++bIdx;
            ++res;
        }
    }
    
    return res;
}