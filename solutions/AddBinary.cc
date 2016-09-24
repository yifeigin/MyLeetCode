class Solution {
public:
    string addBinary(string a, string b) {
        string s, l;
        if (a.size()>b.size()) {
            s = b;
            l = a;
        }
        else {
            s = a;
            l =b;
        }
        bool addone = false;
        int dif = l.size() - s.size();
        for (int i=s.size()-1; i>=0; i--) {
            int lpos = i+dif;
            if (!addone && s[i]=='1' && l[lpos]=='1') {
                l[lpos]='0';
                addone = true;
            }
            else if (!addone && (s[i]=='0' || l[lpos]=='0') && s[i]!=l[lpos]) l[lpos]='1';
            else if (addone && s[i]=='0' && l[lpos]=='0') {
                l[lpos]='1';
                addone = false;
            }
            else if (addone && (s[i]=='0' || l[lpos]=='0') && s[i]!=l[lpos]) l[lpos]='0';
        }
        int i = l.size()-s.size() - 1;
        while (addone && i >= 0) {
             if (l[i]=='1') l[i]='0';
             else if (l[i]=='0') {
                l[i]='1';
                addone = false;
             }
             i--;
        }
        if (addone) return "1" + l;
        return l;
    }
};