class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') continue;
                if(s.find("row"+to_string(i)+board[i][j])==s.end()){
                    s.insert("row"+to_string(i)+board[i][j]);
                }
                else return false;
                if(s.find("column"+to_string(j)+board[i][j])==s.end()){
                      s.insert("column"+to_string(j)+board[i][j]);
                }
                else return false;
                if(s.find("box"+to_string((i/3)*3+j/3)+board[i][j])==s.end()){
                   s.insert("box"+to_string((i/3)*3+j/3)+board[i][j]);
                  
                }
                else return false;
            }
        }
        return true;
    }
};