// Yifei Wang
// LeetCode Question 171

class Solution {
public:
    int titleToNumber(string s) {
        int output = 0;
        for (int i=0; i<s.length(); i++) output += (s[i] - 'A' + 1)*pow(26, s.length()-1-i);
        return output;
    }
};
