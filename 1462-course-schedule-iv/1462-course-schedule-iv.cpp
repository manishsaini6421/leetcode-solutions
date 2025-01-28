class Solution {
public:
    bool bfs(vector<vector<int>> &adj,int node,int target,vector<int> &visited){
        visited[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int top=q.front();

            q.pop();
            for(auto val:adj[top]){
                if(!visited[val]){
                    if(val==target)return true;
                    visited[val]=1;
                    q.push(val);
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,        vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            
        }

        vector<bool> ans;
        for(int i=0; i<queries.size(); i++){
            vector<int> visited(numCourses,0);
            if(bfs(adj,queries[i][1],queries[i][0],visited))ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};