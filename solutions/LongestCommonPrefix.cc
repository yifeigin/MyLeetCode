class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if (strs.empty()) return result;
        for (int j=0; j<strs[0].size(); j++) {
            result = strs[0].substr(0, j+1);
            for (int i = 1; i<strs.size();i++) {
                int len = strs[i].size();
                if (j+1>len) return strs[i].substr(0, j);
                if (j+1==len && strs[i][j]!=result[j]) return result.substr(0, j);
                else if (strs[i][j]!=result[j]) return result.substr(0, j);
            }
        }
        return result;
    }
};