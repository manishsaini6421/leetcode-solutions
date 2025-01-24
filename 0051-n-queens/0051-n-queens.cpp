class Solution {
public:
    void copyans(vector<vector<int>> &board,vector<vector<string>> &ans){
        vector<string> v;
        for(int i=0; i<board.size(); i++){
            string s="";
            for(int j=0; j<board.size(); j++){
                if(board[i][j])s+='Q';
                else s+='.';
            }
            v.push_back(s);
        }
        ans.push_back(v);

    }
    bool isSafe(vector<vector<int>> &board,int row, int col){
        int n=board.size();
        for(int i=0; i<row; i++){
            if(board[i][col])return false;
        }
        int i=row,j=col;
        while(i>=0 && j<n){
            if(board[i][j])return false;
            i--;
            j++;
        }
        int k=row,l=col;
        while(k>=0 && l>=0){
            if(board[k][l])return false;
            k--;
            l--;
        }
        return true;

    }

    void fun(vector<vector<int>> &board,vector<vector<string>> &ans, int row){
        if(row==board.size()){
            copyans(board,ans);
            return;
        }

        for(int i=0; i<board.size(); i++){
            if(isSafe(board,row,i)){
                board[row][i]=1;
                fun(board,ans,row+1);
                board[row][i]=0;

            }
                
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n,vector<int> (n,0));
        fun(board,ans,0);
        return ans;
    }
};