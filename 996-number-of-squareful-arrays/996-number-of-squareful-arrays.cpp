class Solution {
public:
    
    bool isSquare(int n){
        float root=sqrt(n);
        return (ceil((double)sqrt(n)) == floor((double)sqrt(n)));
        return false;
    }
    
    void helper(int &ans, vector<int> &v,vector<int> &nums, map<int,int> &m,int n){
        if(v.size()==n){
            ans++;
            return;
        }
        
        
       
        for(auto x:nums){
            int ct=0; 
             for(int i=0; i<v.size(); i++){
            if(v[i]==x) ct++;
        }
            
            if(ct<m[x]){
                if(v.size()==0){
                    v.push_back(x);
                    helper(ans,v,nums,m,n);
                     v.pop_back();
                }
                else if(isSquare(v.back()+x)){
                    v.push_back(x);
                    helper(ans,v,nums,m,n);
                v.pop_back();
                }
                
            }
           
        }
    }
    
    int numSquarefulPerms(vector<int>& nums) {
        map<int,int> m;
        int ans=0;
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