# include <vector>
# include <deque>
using namespace std;

class Solution {
private:
    int n;
    bool myTurn;
    int scores[2] = {0, 0};
    deque<int> dq;
    vector<int> nums;

    bool foo(){
        if (dq.empty()){
            if (scores[1] >= scores[0])
                return true;
            else
                return false;
        }
        int idx[2] = {dq.front(), dq.back()};
        bool res[2];
        for (int i=0; i<2; i++){
            if (i)
                dq.pop_back();
            else
                dq.pop_front();
            int score = nums[idx[i]];
            
            scores[myTurn] += score;
            myTurn ^= 1;
            res[i] = foo();
            myTurn ^= 1;
            scores[myTurn] -= score;

            if (i)
                dq.push_back(idx[i]);
            else 
                dq.push_front(idx[i]);
        }
        if (myTurn){
            return res[0] | res[1];
        }
        else {
            return res[0] && res[1];
        }
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;

        for (int i=0; i<n; i++){
            dq.emplace_back(i);
        }

        myTurn = true;
        bool res = foo();
        
        return res;
    }
};