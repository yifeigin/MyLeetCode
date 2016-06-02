// Yifei Wang
// LeetCode Question 349

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> counter;
        vector<int> output;
        for (int i=0; i<nums1.size();i++) {
            counter[nums1[i]]++;
        }
        for (int i=0; i<nums2.size();i++) {
            if (counter[nums2[i]]>0) {
                output.push_back(nums2[i]);
                counter[nums2[i]] = -1;
            }
        }
        return output;
    }
};
