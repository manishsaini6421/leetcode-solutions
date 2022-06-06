class Solution {
public:
    
    
    void helper( vector<vector<int>> &ans ,vector<int> &v, vector<int>& candidates, int target, int index){
        if(target==0){
            ans.push_back(v);
            return ;
        }
        
        if(target<0) return;
        
       
     for(int i=index; i<candidates.size(); i++){
         if(i >index && candidates[i]==candidates[i-1]) continue;
         v.push_back(candidates[i]);
         helper(ans,v,candidates,target-candidates[i],i+1);
         v.pop_back();
        }
           
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
             sort(candidates.begin(),candidates.end());
     
              helper(ans,v,candidates,target,0);
        
      
        return ans;
    }
};