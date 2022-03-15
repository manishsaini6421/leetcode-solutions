class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        map<int,vector<int>> m;
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected[0].size(); j++){
                if(isConnected[i][j]==1)
                {
                    m[i].push_back(j);
                    m[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int> visited(m.size(),0);
        for(int i=0; i<visited.size(); i++){
            if(visited[i]==0){
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int temp=q.front();
                    q.pop();
                    for(auto x:m[temp]){
                        if(!visited[x]){
                            visited[x]=1;
                            q.push(x);
                        }
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};