class Solution {
public:
    int myAtoi(string str) {
        string s = "";
        istringstream (str) >> s;
        if (s=="") return 0;
        bool neg = false;
        int i=0;
        if (s[0]=='-') neg = true;
        if (s[0]=='-' || s[0]=='+') {
            i++;
            if (i>=s.size()) return 0;
        }
        long res = 0;
        int j = s.find_first_not_of("0123456789", i);
        s=s.substr(i, j-i);
        istringstream (s) >> res;
        if (neg) res = 0 - res;
        if (res >= INT_MAX) return INT_MAX;
        else if (res <= INT_MIN) return INT_MIN;
        else return res;
    }
};