class Solution {
public:
    bool isPowerOfThree(int n) {
        // since the upper bound of int-32 is 2147483647, thus the max power of 3 is 1162261467
        return n>0 && 1162261467%n==0;
    }
};