class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1;
        int multi = 9;
        for (int i=1; i<=n && i<10; i++) {
            res += multi;
            multi *= (10 - i);
        }
        return res;
    }
};