# include <iostream>
# include <set>
# include <unordered_map>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;

    multiset<int> nums;
    unordered_map<long long, int> gapCount;

    auto addGap = [&](long long d){
        ++gapCount[d];
    };
    auto removeGap = [&](long long d){
        auto it = gapCount.find(d);
        if (--(it->second) == 0) gapCount.erase(it);
    };

    for (int i=0; i<n; ++i){
        int num;    cin >> num;

        auto it = nums.insert(num);
        auto nx = next(it);
        bool hasPrev = (it != nums.begin());
        bool hasNext = (nx != nums.end());

        if (hasPrev && hasNext){
            long long a = *prev(it);
            long long b = *nx;
            removeGap(b - a);
            addGap(num - a);
            addGap(b - num);
        }
        else if (hasPrev){
            addGap((long long)num - *prev(it));
        }
        else if (hasNext){
            addGap((long long)*nx - num);
        }

        cout << (gapCount.size() <= 1 ? 1 : 0) << '\n';
    }
}