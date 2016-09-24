class Solution {
public:
    int climbStairs(int n) {
        if (n<=0) return 0;
        if (n==1) return 1;
        if (n==2) return 2;
      int base1 = 1;
      int base2 = 2;
      int result = 0;
      for (int i=2; i<n; i++) {
          result = base1 + base2;
          base1 = base2;
          base2 = result;
      }
      return result;
    }
};