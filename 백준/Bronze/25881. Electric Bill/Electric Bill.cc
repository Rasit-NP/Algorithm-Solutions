# include <iostream>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int f, s;   cin >> f >> s;
    int n;  cin >> n;

    while (n--){
        int usage;  cin >> usage;
        cout << usage << ' ' << min(usage, 1000) * f + (usage-min(usage, 1000)) * s << '\n';
    }
}