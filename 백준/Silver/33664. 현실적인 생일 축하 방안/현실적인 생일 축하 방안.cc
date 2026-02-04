# include <iostream>
# include <string>
# include <unordered_map>
using namespace std;

int main(void){
    long long b;
    int n, m;    cin >> b >> n >> m;
    unordered_map<string, long long> map;
    for (int i=0; i<n; i++){
        string name;
        long long p;    cin >> name >> p;

        map.insert({name, p});
    }
    long long total = 0;
    for (int i=0; i<m; i++){
        string name;    cin >> name;
        total += map[name];
    }

    if (total > b)
        cout << "unacceptable";
    else
        cout << "acceptable";
}