class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int counter = 0;
        for (int i=1;i<nums.size();i++) {
            if (nums[i]!=nums[counter]) {
                counter++;
                nums[counter]=nums[i];
            }
        }
        return counter+1;
    }
};