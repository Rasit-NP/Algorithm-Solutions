# include <iostream>
# include <vector>
# include <string>
# include <queue>
# include <climits>
# include <unordered_set>
# include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int n;  cin >> n;   cin.ignore();
    int m = 0;
    unordered_set<int> nowDelete;
    vector<int> ans;
    vector<string> candidates(n+1, "");
    vector<queue<int>> votes;
    vector<vector<int>> counts(n+1, vector<int>(0));

    for (int i=1; i<=n; i++){
        getline(cin, candidates[i]);
    }
    string input;
    while (getline(cin, input)){
        m++;
        queue<int> vote;
        for (int i=0, idx = 0; i<input.size(); i++){
            if (input[i] == ' '){
                vote.push(stoi(input.substr(idx, i-idx)));
                idx = i+1;
            }
            if (i == input.size()-1){
                vote.push(stoi(input.substr(idx, i-idx+1)));
            }
        }
        counts[vote.front()].push_back(votes.size());
        votes.push_back(vote);
    }
    while (true){
        for (const int& candidate : nowDelete){
            for (const int& num : counts[candidate]){
                queue<int>& q = votes[num];
                while (nowDelete.find(q.front()) != nowDelete.end()){
                    q.pop();
                }
                counts[q.front()].push_back(num);
            }
            counts[candidate].clear();
        }

        int maxCnt=0, minCnt=INT_MAX;
        vector<int> maxIdx, minIdx;
        for (int i=1; i<=n; i++){
            int cnt = counts[i].size();
            if (cnt == 0){
                continue;
            }
            if (cnt > maxCnt){
                maxCnt = cnt;
                maxIdx.clear();
                maxIdx.push_back(i);
            }
            else if (cnt == maxCnt){
                maxIdx.push_back(i);
            }
            if (cnt < minCnt){
                minCnt = cnt;
                minIdx.clear();
                minIdx.push_back(i);
            }
            else if (cnt == minCnt){
                minIdx.push_back(i);
            }
        }
        if (maxCnt * 2 > m){
            ans = maxIdx;
            break;
        }
        else if (minIdx.size() == n - nowDelete.size()){
            ans = minIdx;
            break;
        }
        else {
            for (int& num : minIdx){
                nowDelete.insert(num);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int& candidate : ans){
        cout << candidates[candidate] << '\n';
    }
}