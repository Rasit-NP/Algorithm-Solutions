# include <queue>
using namespace std;

bool cmp(queue<char> a, queue<char> b){
    while (a.size() && b.size()){
        if (a.front() != b.front()){
            return false;
        }
        a.pop();
        b.pop();
    }
    return true;
}

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()){
            return false;
        }
        bool res = false;
        queue<char> q, ans;
        for (char let : s){
            q.push(let);
        }

        for (char let : goal){
            ans.push(let);
        }

        int sz = s.size();

        while (sz--){
            if (cmp(q, ans)){
                res = true;
                break;
            }
            char front = q.front(); q.pop();
            q.push(front);
        }
        return res;
    }
};