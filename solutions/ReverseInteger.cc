class Solution {
public:
    int reverse(int x) {
      long int n = 0;
      while (x) {
          n = n*10 + x%10;
          if (n>INT_MAX || n<INT_MIN) return 0;
          x /= 10;
      }
      if (n>INT_MAX || n<INT_MIN) return 0;
      return n;
    }
};