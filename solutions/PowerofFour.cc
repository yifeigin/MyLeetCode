// Yifei Wang
// LeetCode Question 342
Submission 10

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num<1) return false;
        if (num >> 1 & 0x55555555) return false;
        num &= 0x55555555;
        return (!(num & (num - 1)));
    }
};

