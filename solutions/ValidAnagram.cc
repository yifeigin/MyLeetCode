// Yifei Wang
// LeetCode Question 242

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> counter;
        for (int i=0; i<s.length(); i++) {
            counter[s[i]]++;
        }
        for (int i=0; i<t.length(); i++) {
            counter[t[i]]--;
        }
        for (map<char, int>::iterator it = counter.begin(); it != counter.end(); it++) {
            if (it->second != 0) return false;
        }
        return true;
    }
};
