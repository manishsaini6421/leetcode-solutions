class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<vector<int>> v(n);
        vector<int> indegree(n,0);

        for(int i=0; i<n; i++){
            for(auto node:graph[i]){
                v[node].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(!indegree[i])q.push(i);
        }
        vector<int> ans;
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            if(!indegree[p])ans.push_back(p);
            for(auto node:v[p]){
                indegree[node]--;
                if(!indegree[node])q.push(node);
            }
        }
        sort(ans.begin(),ans.end());

        return ans;
    }
};