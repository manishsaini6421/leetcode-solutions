class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> v,int n, int k,int index){
        if(v.size()==k){
            ans.push_back(v);
            return ;
        }
        
        for(int  i=index; i<=n; i++){
            v.push_back(i);
            helper(ans,v,n,k,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
         helper(ans,v,n,k,1);
        return ans;
    }
};