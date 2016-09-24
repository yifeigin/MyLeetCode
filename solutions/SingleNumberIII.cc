class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = nums[0];
        for (int i=1; i<nums.size(); i++) a ^= nums[i];
        a &= -a;
        vector<int> res(2, 0);
        for (int i=0; i<nums.size(); i++) {
            if ((nums[i] & a) == 0) res[0] ^= nums[i];
            else res[1] ^= nums[i];
        }
        return res;
    }
};