# include <iostream>
# include <set>
using namespace std;

int main(void){
    int n, ans = 0;    cin >> n;
    set<char> sets = {'a', 'e', 'i', 'o', 'u'};
    while (n--){
        char c;    cin >> c;
        if (sets.find(c) != sets.end())
            ans++;
    }
    cout << ans;
}