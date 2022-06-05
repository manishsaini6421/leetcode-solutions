class Solution {
public:
    
    void helper(vector<vector<int>> &ans, vector<int>& candidates, vector<int> &v,int target,int i){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0) return;
        
        while(i<candidates.size()){
            v.push_back(candidates[i]);
            helper(ans,candidates,v,target-candidates[i],i);
            i++;
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans,candidates,v,target,0);
        return ans;
    }
};