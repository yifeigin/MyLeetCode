class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1, 0);
        result[0]=1;
        for (int i=0; i<=rowIndex; i++) {
            for (int n=i; n>=1; n--) result[n] += result[n-1];
        }
        return result;
    }
};