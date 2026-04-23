# include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int s, ma, f, mb;   cin >> s >> ma >> f >> mb;
    if (s <= 240 || s <= ma+f+mb){
        cout << "high speed rail";
    }
    else {
        cout << "flight";
    }
}