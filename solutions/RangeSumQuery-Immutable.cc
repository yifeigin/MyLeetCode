class NumArray {
    vector<int> count;
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        for (int i=0; i<nums.size();i++) {
            sum += nums[i];
            count.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (!i) return count[j];
        return count[j] - count[i-1]; 
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);