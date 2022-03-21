class Solution {
public:
    void toposort(unordered_map<int,vector<int>> &m,stack<int> &st,vector<bool> &vis,int curr){
        vis[curr]=true;
        for(auto x:m[curr]){
            if(!vis[x])
                toposort(m,st,vis,x);
        }
        st.push(curr);
        
    }
    bool isCycle(unordered_map<int,vector<int>> &m,vector<int> &visited,int curr){
        if(visited[curr]==1)
            return true;
        if(visited[curr]==0){
            visited[curr]=1;
            for(auto x:m[curr]){
                if(isCycle(m,visited,x))
                    return true;
            }
        }
        visited[curr]=2;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> m;
        for(int i=0; i<prerequisites.size(); i++){
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> visited(numCourses,0);
        vector<bool> vis(numCourses,false);
        stack<int> st;
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(isCycle(m,visited,i)){
                vector<int> temp;
                return temp;
            }
             
        }
        for(int i=0; i<numCourses; i++){
            if(!vis[i])
                toposort(m,st,vis,i);
            
        }
        while(!st.empty()){
            ans.push_back(st.top());
            cout<<st.top();
            st.pop();
        }
        return ans;
    }
};