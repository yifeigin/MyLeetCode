// Yifei Wang
// LeetCode QUestion 283

//First solution (less runtime):
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> counter;
        for(int i=0; i<nums.size();i++) {
            if (nums[i]!=0) {
                counter.push_back(nums[i]);
            }
        }
        for (int i=0; i<counter.size();i++) {
            nums[i]=counter[i];
        }
        for (int i=counter.size(); i<nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

//Second solution (more runtime, but should have less runtime actually):
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
