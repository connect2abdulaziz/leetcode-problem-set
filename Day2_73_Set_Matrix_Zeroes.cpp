#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> row(m,false), col(n,false);
        for (int i =0; i<m; i++)
            for (int j=0; j<n; j++){
                if (matrix[i][j] != 0) continue;
                row[i] = true;
                col[j] = true;
            }    
        for (int i = 0; i < m; i++){
            if(!row[i]) continue;
            fill(matrix[i].begin(), matrix[i].end(), 0);
        }
        for (int i = 0; i<n; i++){
            if (!col[i]) continue;
            for (int j = 0; j< m; j++)
                matrix[j][i] = 0;
        }
    }
};