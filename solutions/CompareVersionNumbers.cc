class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream vs1(version1), vs2(version2);
        char temp = '.';
        int v1 = 0, v2 = 0;
        while (vs1 || vs2) {
            v1 = 0;
            v2 = 0;
            if (vs1) vs1 >> v1 >> temp;
            if (vs2) vs2 >> v2 >> temp;
            if (v2>v1) return -1;
            if (v1>v2) return 1;
        }
        return 0;
    }
};