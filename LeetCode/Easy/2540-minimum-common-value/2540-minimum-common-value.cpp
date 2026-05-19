# include <vector>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int ans = -1;
        int i1 = 0, i2 = 0;
        while (i1<n1 && i2<n2){
            if (nums1[i1] < nums2[i2]){
                ++i1;
                continue;
            }
            else if (nums1[i1] > nums2[i2]){
                ++i2;
                continue;
            }
            else {
                ans = nums1[i1];
                break;
            }
        }

        return ans;
    }
};