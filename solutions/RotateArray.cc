class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int start = 0, curpos=0, count = 0, pre = nums[0], cur = 0;
        while (count<nums.size()) {
            do  {
                curpos = (curpos+k)%nums.size();
                cur = nums[curpos];
                nums[curpos] = pre;
                pre = cur;
                count++;
            } while (start!=curpos);
            start++;
            curpos = start;
            pre = nums[start];
        }
    }
};