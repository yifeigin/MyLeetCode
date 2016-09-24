class Solution {
public:
    // using KMP algorithm
    int strStr(string haystack, string needle) {
        if (needle=="") return 0;
        // Fail Array
        vector<int> F(needle.size(), 0);
        int i=1, j=0;
        while (i<needle.size()) {
            if (needle[i]==needle[j]) {
                F[i] = j+1;
                i++;
                j++;
            }
            else if (j>0) j = F[j-1];
            else {
                F[i] = 0;
                i++;
            }
        }
        i=0; j=0;
        while (i<haystack.size()) {
            if (haystack[i]==needle[j]) {
                if (j == needle.size()-1)  return i - j;
                else {
                    i++;
                    j++;
                }
            }
            else {
                if (j>0) j = F[j-1];
                else i++;
            }
        }
        return -1;
    }
};