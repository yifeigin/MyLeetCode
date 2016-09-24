// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1;
        while (i<n) {
            if (isBadVersion(i+(n-i)/2)) n = i+(n-i)/2;
            else i = i+1+(n-i)/2;
        }
        return i;
    }
};