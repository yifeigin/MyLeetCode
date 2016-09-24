class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int counter1[9][9] = {0};
        int counter2[9][9] = {0};
        int counter3[9][9] = {0};
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j]!='.') {
                    int y = board[i][j] - '0' - 1;
                    int x = i/3 * 3 + j/3;
                    if (counter1[i][y] || counter2[j][y] || counter3[x][y]) return false;
                    counter1[i][y] = 1;
                    counter2[j][y] = 1;
                    counter3[x][y] = 1;
                }
            }
        }
        return true;
    }
};