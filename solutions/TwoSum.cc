class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> count;
        vector<int> result(2, 0);
        for (int i=0; i<nums.size(); i++) {
            if (count.find(target-nums[i])!=count.end()) {
                result[0] = count[target-nums[i]];
                result[1] = i;
                return result;
            }
            count[nums[i]] = i;
        }
        return result;
    }
};