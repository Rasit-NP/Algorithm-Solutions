# include <string>
# include <vector>
using namespace std;

vector<int> check;

int solution(int n) {
    int answer = 0;
    check.assign(n+1, 1);
    check[0] = 0, check[1] = 0;
    
    for (int i=2; i<=n; i++){
        if (check[i]){
            ++answer;
            for (int num=i*2; num<=n; num+=i){
                check[num] = 0;
            }
        }
    }
    return answer;
}