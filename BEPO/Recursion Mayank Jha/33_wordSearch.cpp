class Solution {
public:
    // define the moves..
    int dx[4] {0, -1, 0, 1};
    int dy[4] { -1, 0, 1, 0};

    bool solve(vector<vector<char>>& board, int rows, int cols, int i, int j, string& word, int k) {

        if (k == word.size()) {
            return true;
        }

        // save the current character
        char temp = board[i][j];
        // mark current position as visited
        board[i][j] = '#';


        // check for other moves..
        for (int move = 0; move < 4; move++) {
            int x_crdnt = i + dx[move];
            int y_crdnt = j + dy[move];

            if (x_crdnt >= 0 and x_crdnt < rows and y_crdnt >= 0 and y_crdnt < cols and board[x_crdnt][y_crdnt] == word[k] and board[x_crdnt][y_crdnt] != '#') {
                if (solve(board, rows, cols, x_crdnt, y_crdnt, word, k + 1)) {
                    return true;
                }
            }
        }

        board[i][j] = temp;

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        if (rows == 0 or word.size() == 0) return false;

        // find first equal index with board
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, rows, cols, i, j, word, 1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};