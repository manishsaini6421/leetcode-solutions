class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int> q;
        vector<bool>visited(n+1,false);
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int y=q.front();
            vector<int> temp=rooms[y];
            q.pop();
            for(auto x:temp){                
                if(!visited[x]){
                    q.push(x);
                    visited[x]=true;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(!visited[i])
                return false;
        }
        return true;
    }
};