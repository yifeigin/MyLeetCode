class Solution {
public:
    int lengthOfLastWord(string s) {
        bool word = false;
        int counter = 0;
        for (int i=s.size()-1; i>=0; i--) {
            if (!word && s[i]!=' ') {
                counter = i+1;
                word = true;
            }
            if (word && s[i]==' ') {
                return counter - i - 1;
            }
        }
        return counter;
    }
};