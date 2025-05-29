class Solution {
public:
    pair<int,int> BFS(unordered_map<int,unordered_set<int>> &adj,vector<int> &levels){
        int n=adj.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int level=0;
        int odd=0,even=0;

        while(!q.empty()){
            int size=q.size();
            if(level%2)odd+=size;
            else
                even+=size;

            for(int i=0; i<size; i++){
                int top=q.front();
                q.pop();
                levels[top]=level;
                for(int neighbour:adj[top]){
                    if(!visited[neighbour]){
                        visited[neighbour]=true;
                        q.push(neighbour);
                    }
                }
            }   
            level++;
        }
        return {even,odd};
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,unordered_set<int>> adj1,adj2;
        for(auto &edge:edges1){
            adj1[edge[0]].insert(edge[1]);
             adj1[edge[1]].insert(edge[0]);
        }
       
        for(auto &edge:edges2){
            adj2[edge[0]].insert(edge[1]);
             adj2[edge[1]].insert(edge[0]);
        }
        vector<int> levels1(adj1.size(),0);
        vector<int> levels2(adj2.size(),0);

        auto tree1=BFS(adj1,levels1);
        auto tree2=BFS(adj2,levels2);

        vector<int> ans;

        for(int i=0; i<adj1.size(); i++){
            ans.push_back(levels1[i]%2?(tree1.second + tree2.second):(tree1.first+tree2.second));
        }

        return ans;
    }
};