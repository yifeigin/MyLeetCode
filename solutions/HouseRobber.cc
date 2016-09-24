class Solution {
public:
    int rob(vector<int>& nums) {
        int pre = 0;
        int cur = 0;
        for (int i=0; i<nums.size(); i++) {
            int temp = 0;
            if (nums[i]+pre>cur) {
                temp = pre;
                pre = cur;
                cur = temp + nums[i];
            }
            else pre = cur;
        }
        if (cur>pre) return cur;
        return pre;
    }
};