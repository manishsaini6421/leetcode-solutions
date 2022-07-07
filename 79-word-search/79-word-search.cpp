class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int x){
        
       if(x==word.size())
           return true;
       else if(i==-1 || j==-1 || i==board.size() || j==board[0].size() || board[i][j]!=word[x])
           return false;
        char temp=board[i][j];
        board[i][j]='*';
        bool found= dfs(board,word,i,j+1,x+1) ||
            dfs(board,word,i,j-1,x+1) ||
            dfs(board,word,i-1,j,x+1)||
            dfs(board,word,i+1,j,x+1);
         
       
            board[i][j]=temp;
        
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
               if(dfs(board,word,i,j,0))
                   return true;
            }
        }
       return false;
    }
};