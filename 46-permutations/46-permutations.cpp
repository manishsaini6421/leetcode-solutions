class Solution {
public:
    
    void helper(vector<vector<int>> &ans, vector<int> &v,vector<int>& nums){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        
        for(auto x:nums){
            int ct=0;
            for(int i=0; i<v.size(); i++){
                
                if(v[i]==x) break;
                ct++;
            }
            if(ct==v.size()){
                v.push_back(x);
            helper(ans,v,nums);
                v.pop_back();
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans,v,nums);
        return ans;
    }
};