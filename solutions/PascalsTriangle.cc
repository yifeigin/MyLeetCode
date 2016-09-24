class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows==0) return vector<vector<int>>{};
        if (numRows==1) return vector<vector<int>>{{1}};
        vector<vector<int>> result = generate(numRows-1);
        vector<int> last;
        int LastSize = result.back().size();
        int left = 0, right = 0;
        for (int i=0; i<=LastSize; i++) {
            left = right;
            if (i<LastSize) right= result.back()[i];
            else right = 0;
            last.push_back(left+right);
        }
        result.push_back(last);
        return result;
        
    }
};
