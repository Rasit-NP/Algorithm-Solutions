# include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    if (n > s)
        return {-1};
    vector<int> res(n, s/n);
    for (int i=n-s%n; i<n; i++){
        res[i]++;
    }
    
    return res;
}