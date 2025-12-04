# include <iostream>
# include <vector>
using namespace std;
int main(void){
    int n, ans;
    cin >> n;
    vector<int> face(6, 0);
    face[1] = 7, face[2] = 14, face[3] = 21,
    face[4] = 28, face[5] = 35;

    ans = face[5] + (n-1)*(2*face[4] + face[2]) + (((n-2)*(n-1))/2)*(2*face[1] + face[3]);
    cout << ans << endl;
}