#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        vector<vector<int>> temp(board);
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = updatedValue(temp, i, j, m - 1, n - 1);
    }
    int updatedValue(vector<vector<int>>& board, int& i, int& j,const int& m, const int& n) {
        int oneCount = 0;
        if (i > 0 && j > 0 && board[i - 1][j - 1] == 1)
            oneCount++;
        if (i > 0 && board[i - 1][j] == 1)
            oneCount++;
        if (i > 0 && j < n && board[i - 1][j + 1] == 1)
            oneCount++;
        if (j < n && board[i][j + 1] == 1)
            oneCount++;
        if (i < m && j < n && board[i + 1][j + 1] == 1)
            oneCount++;
        if (i < m && board[i + 1][j] == 1)
            oneCount++;
        if (i < m && j > 0 && board[i + 1][j - 1] == 1)
            oneCount++;
        if (j > 0 && board[i][j - 1] == 1)
            oneCount++;
        return (oneCount == 3 || (oneCount == 2 && board[i][j] == 1)) ? 1 : 0;
    }
};