# include <iostream>
# include <vector>
# include <string>
using namespace std;

vector<int> price_dolor = {350, 230, 190, 125, 180};
vector<int> price_cents = {34, 90, 55, 30, 90};

void run(void){
    int res_dolor=0, res_cents = 0;
    int n;
    for (int i=0; i<5; i++){
        cin >> n;
        res_dolor += n * price_dolor[i];
        res_cents += n * price_cents[i];
    }
    res_dolor += res_cents/100;
    res_cents %= 100;

    cout << '$' << res_dolor << '.';
    if (res_cents >= 10)
        cout << res_cents << '\n';
    else if (res_cents > 0)
        cout << '0' << res_cents << '\n';
    else
        cout << "00\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t;  cin >> t;
    while (t--){
        run();
    }
}