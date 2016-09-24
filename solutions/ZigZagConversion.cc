class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int j, len=s.size(), pos;
        if (numRows==1 || len<=numRows) return s;
        for (int i=0; i<numRows && i<len; i++) {
            j = i;
            while (j<len) {
                    res += s[j];
                    pos = j+2*(numRows - i - 1);
                    if (pos<len && i!=0 && i!=numRows-1) res += s[pos];
                    j += 2*(numRows - 1);
            }
        }
        return res;
    }
};