class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
       int i=0, j=len-1;
       while (i<j) {
           while (i<len &&!isalnum(s[i])) i++;
           while (j>=0 &&!isalnum(s[j])) j--;
           if (i>=len && j<0) return true;
           if (i>=len || j<0) return false;
           if (tolower(s[i])!=tolower(s[j])) return false;
           i++;
           j--;
       }
       return true;
    }
};