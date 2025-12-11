# include <iostream>
# include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, c, d;
    vector<int> primes;
    vector<bool> check(1001, true);
    check[0] = false; check[1] = false;
    for (int i=2; i<1001; i++){
        if (check[i]){
            primes.push_back(i);
            for (int num=2*i; num<1001; num += i){
                check[num] = false;
            }
        }
    }

    int cnt_yt = 0, cnt_yj = 0, cnt_overlap = 0;
    cin >> a >> b >> c >> d;
    for (int prime : primes){
        if (prime >= a && prime <= b && prime >= c && prime <= d){
            cnt_overlap++;
        }
        else if (prime >= a && prime <= b){
            cnt_yt++;
        }
        else if (prime >= c && prime <= d){
            cnt_yj++;
        }
        else if (prime > b && prime > d)    break;
    }
    cnt_yt += (cnt_overlap+1)/2;
    cnt_yj += cnt_overlap/2;
    if (cnt_yt > cnt_yj)    cout << "yt\n";
    else                    cout << "yj\n";
}