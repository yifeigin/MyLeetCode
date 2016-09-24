class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string, char> strmap;
        map<char, string> patternmap;
        istringstream input(str);
        string token;
        for(int i=0; i<pattern.size();i++) {
            if (!(input >> token)) return false;
            if (patternmap[pattern[i]]=="" && !strmap[token]) {
                patternmap[pattern[i]] = token;
                strmap[token] = pattern[i];
            }
            else if (patternmap[pattern[i]]!=token || strmap[token]!=pattern[i]) return false;
        }
        if (input >> token) return false;
        return true;
    }
};