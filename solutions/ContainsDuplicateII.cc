class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> counter;
        for (int i=0; i<nums.size(); i++) {
            if (counter.count(nums[i]) && i-counter[nums[i]]<=k) return true;
            else counter[nums[i]] = i;
        }
        return false;
    }
};