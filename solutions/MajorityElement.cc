// Yifei Wang
// LeetCode 169

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int length = nums.size();
        map<int, int> counter;
        for (int i=0; i<length; i++) {
            counter[nums[i]]++;
            if (counter[nums[i]]>(length/2)) return nums[i];
        }
        return 0;
    }
};
