# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <map>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;
    map<int, vector<string>> nums;
    while (n--){
        string word;    cin >> word;
        string res = "";
        for (const char& let : word){
            if (let >= '0' && let <= '9'){
                if (res == "0"){
                    res.clear();
                }
                res.push_back(let);
            }
            else if (res.size() > 0){
                nums[res.size()].push_back(res);
                res = "";
            }
        }
        if (res.size() > 0){
            nums[res.size()].push_back(res);
        }
    }

    for (auto& [len, vec] : nums){
        sort(vec.begin(), vec.end());

        for (string num : vec){
            cout << num << '\n';
        }
    }

}