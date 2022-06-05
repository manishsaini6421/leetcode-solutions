class Solution {
public:
    
    void helper(vector<vector<int>> &ans, vector<int> &v,vector<int> &nums,map<int,int> &m,int n){
        if(v.size()==n){
            ans.push_back(v);
            return;
        }
        
        for(auto x:nums){
            int ct=0;
            for(int i=0; i<v.size(); i++){
                if(v[i]==x) ct++;
            }
            if(ct<m[x]){
                v.push_back(x);
                helper(ans,v,nums,m,n);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int,int> m;
        vector<vector<int>> ans;
        vector<int> v;
        int n=nums.size();
        for(auto x:nums){
            m[x]++;
        }
        vector<int> newNums;
        for(auto y:m){
            newNums.push_back(y.first);
        }
        helper(ans,v,newNums,m,n);
        return ans;
    }
};