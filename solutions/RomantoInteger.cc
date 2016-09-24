class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        string preread = s.substr(1, 1);
        if(s.length()>1) {
            result = result = romanToInt(s.substr(1));
        }
        if (s[0] == 'I') {
            if (preread!="I" && result>1) return result - 1;
            else return 1+result;
        }
        else if (s[0]=='X') {
            if (preread!="X" && result>10) return result - 10;
            else return 10+result;
        }
        else if (s[0]=='V') {
            if (preread!="V" && result>5) return result - 5;
            else return 5+result;
        }
        else if (s[0]=='L') {
            if (preread!="L" && result>50) return result - 50;
            else return 50+result;
        }
        else if (s[0]=='C') {
            if (preread!="C" && result>100) return result - 100;
            else return 100+result;
        }
        else if (s[0]=='D') {
            if (preread!="D" && result>500) return result - 500;
            else return 500+result;
        }
        else if (s[0]=='M') {
            if (preread!="M" && result>1000) return result - 1000;
            else return 1000+result;
        }
        return 0;
    }
};