class Solution {
public:
   
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,        vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses,vector<int> (numCourses,0));
        for(auto pre:prerequisites){
            adj[pre[0]][pre[1]]=1;
        }

        for(int k=0; k<numCourses; k++){
            for(int i=0; i<numCourses; i++){
                for(int j=0; j<numCourses; j++){
                    if(adj[i][k] & adj[k][j])
                        adj[i][j]=1;
                }
            }
        }
        vector<bool> ans;
        for(auto query:queries){
            if(adj[query[0]][query[1]])ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};