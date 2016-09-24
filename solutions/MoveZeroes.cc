class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int counter = 0;
        for(int i=0; i<nums.size();i++) {
            if (nums[i]!=0) {
                nums[counter] = nums[i];
                counter++;
            }
        }
        for (int i=counter; i<nums.size(); i++) {
            nums[i] = 0;
        }
    }
};