class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (n==0) return 0;
            if (n%2==1) return 1+hammingWeight(n/2);
            return hammingWeight(n/2);
    }
};