class Solution {
public:
    bool isValid(string s) {
        vector<char> data;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='(' || s[i]=='{' || s[i]=='[') data.push_back(s[i]);
            else {
                if (data.empty()) return false;
                else if (s[i]==')' && data.back()!='(') return false;
                else if (s[i]=='}' && data.back()!='{') return false;
                else if (s[i]==']' && data.back()!='[') return false;
                else data.pop_back();
            }
        }
        if (!data.empty()) return false;
        return true;
    }
};