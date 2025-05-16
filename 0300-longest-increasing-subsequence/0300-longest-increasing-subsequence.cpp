class Solution {
public:
    int solve(vector<int>& arr,int currIndex,int prevIndex){
        if(currIndex==arr.size())
            return 0;
        
        int include=0;
        if(prevIndex==-1 || arr[prevIndex]<arr[currIndex]){
            include=1+solve(arr,currIndex+1,currIndex);
        }
        int exclude=solve(arr,currIndex+1,prevIndex);
        
        return max(include,exclude);
    }
    
     int solveMem(vector<int>& arr,int currIndex,int prevIndex,vector<vector<int>> &dp){
        if(currIndex==arr.size())
            return 0;
            
        if(dp[currIndex][prevIndex+1]!=-1)
            return dp[currIndex][prevIndex+1];
            
        int include=0;
        
        if(prevIndex==-1 || arr[prevIndex]<arr[currIndex]){
            include=1+solveMem(arr,currIndex+1,currIndex,dp);
        }
        
        int exclude=solveMem(arr,currIndex+1,prevIndex,dp);
        
        return dp[currIndex][prevIndex+1]=max(include,exclude);
    }
    
    int solveTab(vector<int>& arr){
        int n=arr.size();
        
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        for(int currIndex=n-1; currIndex>=0; currIndex--){
            for(int prevIndex=currIndex-1; prevIndex>=-1; prevIndex--){
                int include=0;
        
                if(prevIndex==-1 || arr[prevIndex]<arr[currIndex]){
                    include=1+dp[currIndex+1][currIndex+1];
                }
        
                int exclude=dp[currIndex+1][prevIndex+1];
                
                dp[currIndex][prevIndex+1]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
    
     int solveOpt(vector<int>& arr){
        int n=arr.size();
        
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        
        for(int currIndex=n-1; currIndex>=0; currIndex--){
            for(int prevIndex=currIndex-1; prevIndex>=-1; prevIndex--){
                int include=0;
        
                if(prevIndex==-1 || arr[prevIndex]<arr[currIndex]){
                    include=1+next[currIndex+1];
                }
        
                int exclude=next[prevIndex+1];
                
                curr[prevIndex+1]=max(include,exclude);
            }
            next=curr;
        }
        return curr[0];
    }
    
   
    int solveMostOpt(vector<int>& arr){
        if(arr.size()==0)
            return 0;
        vector<int> ans;
        int n=arr.size();
        ans.push_back(arr[0]);
        
        for(int i=1; i<n; i++){
           if(ans.back()<arr[i]){
                ans.push_back(arr[i]);
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
                ans[index]=arr[i];
            }
        }
        return ans.size();
    }
    int x(vector<int>& nums){
        int n=nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(ans.back()<nums[i]){
                ans.push_back(nums[i]);
            }
            else{
                auto it=lower_bound(ans.begin(),ans.end(),nums[i]);
                *it=nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        //return solve(nums,0,-1);
       
    //   int n=nums.size();
    //   vector<vector<int>> dp(n,vector<int> (n+1,-1));
    //   return solveMem(nums,0,-1,dp);
    
    //return solveTab(nums);
    
    //return solveOpt(nums);
    
    //return solveMostOpt(nums);

    return x(nums);
    }
};