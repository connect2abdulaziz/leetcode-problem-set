#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        vector<string> mpRow(9,""), mpCol(9,""), mpSubBox(9,"");
        for (int i =0; i< 9; i++)
            for (int j =0; j<9; j++){
                char ch = board[i][j];
                if (ch != '.'){
                    if (check(ch, mpRow[i]))
                        return false;
                    if (check(ch, mpCol[j]))
                        return false;
                    if (check(ch,mpSubBox[(i / 3) * 3 + j / 3]))
                        return false;
                }
            }
        return true;
    }
    bool check(char & ch, string & mp){
        if (mp != ""){
            if (mp.find(ch) != string::npos){
                return true;
            }
        }
        mp.push_back(ch);
        return false;
    }
};

//Method 2
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        vector<bool> mp(9, false);
        int j, pos; char ch;
        for (int i =0; i< 9; i++){
            for (j =0; j<9; j++){
                if (board[i][j] == '.') continue;
                pos = board[i][j] - '0' - 1;
                if (mp[pos]) return false;
                mp[pos] = true;
            }
            fill(mp.begin(),mp.end(),false);
            for (j =0; j<9; j++){
                if (board[j][i] == '.') continue;
                pos = board[j][i] - '0' - 1;
                if (mp[pos]) return false;
                mp[pos] = true;
            }
            fill(mp.begin(),mp.end(),false);
            for (j =0; j<9; j++){
                ch = board[(i/3 * 3) + j/3][(i%3 * 3) + (j%3)];
                if (ch == '.') continue;
                if (mp[(ch - '0') - 1]) return false;
                mp[(ch - '0') - 1] = true;
            }
            fill(mp.begin(),mp.end(),false);
        }
        return true;
    }
};