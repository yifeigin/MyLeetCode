class Solution {
public:
    int integerBreak(int n) {
        if (n==2) return 1;
        if (n==3) return 2;
        if (n==4) return 4;
        return max(2*max(n-2, integerBreak(n-2)), 3*max(n-3,integerBreak(n-3)));
    }
};