class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);
        for (int i=0;i<=num;i++) result[i] = result[i/2]+i%2;
        return result;
    }
};