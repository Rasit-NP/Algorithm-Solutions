# include <iostream>
# include <vector>
# include <climits>
# include <algorithm>
using namespace std;

struct Data{
    int x, a;

    Data(const int& x, const int& a){
        this->x = x;
        this->a = a;
    }

    bool operator<(Data data){
        if (this->x < data.x){
            return true;
        }
        return false;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    vector<Data> datas;
    long long total = 0;
    for (int i=0; i<n; i++){
        int x, a;   cin >> x >> a;
        datas.emplace_back(x, a);

        total += a;
    }

    sort(datas.begin(), datas.end());

    long long l = -1'000'000'000, r = 1'000'000'001;
    int ans = 0;

    while (r-l>1){
        int mid = (r+l)/2;
        long long diffX = 0, diffX_1 = 0;
        for (const Data& data : datas){
            diffX += llabs(mid - data.x) * data.a;
            diffX_1 += llabs(mid-1 - data.x) * data.a;
        }
        if (diffX < diffX_1){
            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout << l;
}