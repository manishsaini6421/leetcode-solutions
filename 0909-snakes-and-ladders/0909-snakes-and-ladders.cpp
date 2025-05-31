class Solution {
public:
    pair<int,int> getCoordinates(int n,int v){
        int row=n-1-(v-1)/n;
        int col=(n-row)%2==1?(v-1)%n:n-(v-1)%n-1;

        return {row,col};
    }
    int BFS(vector<vector<int>>& board){
        int n=board.size();
        vector<bool> visited(n*n+1,false);

        queue<int> q;
        q.push(1);
        visited[1]=true;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0; i<size; i++){
                int top=q.front();
                cout<<top<<endl;
                if(top==n*n)return level;
                q.pop();
                for(int i=1; i<=6; i++){
                    int newVal=min(n*n,top+i);

                    pair<int,int> coordinate=getCoordinates(n,newVal);
                    int row=coordinate.first;
                    int col=coordinate.second;

                    if(!visited[newVal] && board[row][col]==-1){
                        visited[newVal]=true;
                        q.push(newVal);
                    }
                  
                    
                    if(board[row][col]!=-1 && !visited[board[row][col]]){
                        q.push(board[row][col]);
                        visited[board[row][col]]=true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {

        
        return BFS(board);
    }
};