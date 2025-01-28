class Solution {
public:
    static bool custom(vector<int> v1,vector<int> v2){
        return v1[0]<v2[0];
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,        vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        sort(prerequisites.begin(),prerequisites.end(),custom);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            for(auto num:adj[prerequisites[i][0]]){
                adj[prerequisites[i][1]].push_back(num);
            }
        }

        vector<bool> ans;
        for(int i=0; i<queries.size(); i++){
            if(find(adj[queries[i][1]].begin(),adj[queries[i][1]].end(),queries[i][0])!=adj[queries[i][1]].end())ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};