class Solution {
public:
    bool isCycle(unordered_map<int,vector<int>> &m,vector<int> &visited,int curr){
           if(visited[curr]==1)
               return true;
          if(visited[curr]==0)
          {
           visited[curr]=1;
        for(auto x:m[curr]){
            if(isCycle(m,visited,x))
                return true;
        }
          }
       visited[curr]=2;
          return false;      
            
 
        }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> m;
        for(int i=0; i<prerequisites.size(); i++){
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int> visited(numCourses,0);
        
        
        for(int i=0; i<numCourses; i++){
            if(isCycle(m,visited,i))
                return false;
        }
        return true;
    }
};