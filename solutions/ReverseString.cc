// Yifei Wang
// LeetCode Question 344
// Write a function to reverse a string

class Solution {
public:
  string reverseString(string s) {
    int length = s.length() - 1;
    int start = 0;
    while (length > start) {
      char temp = s[length];
      s[length] = s[start];
      s[start] = temp;
      length --;
      start ++;
    }
    return s;
  }
};

// Possible solution could be using swap or string.reverse()
