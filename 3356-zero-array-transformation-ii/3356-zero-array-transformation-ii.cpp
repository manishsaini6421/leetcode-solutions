class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int count=0;
         int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<=0)count++;
        }
       
        if(count==n)return 0;
        int m=queries.size();
        int k=-1,a=0,b=m-1;
        while(a<=b){
            int mid=(a+b)/2;
            vector<int> arr(n+1,0);
            for(int i=0; i<=mid; i++){
                arr[queries[i][0]]-=queries[i][2];
                arr[queries[i][1]+1]+=queries[i][2];
            }
            for(int i=1; i<n; i++){
                arr[i]+=arr[i-1];
            }
            int flag=0;
            for(int i=0; i<n; i++){
                
                if(nums[i]+arr[i]>0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                k=mid+1;
                b=mid-1;
            }
            else{
                a=mid+1;
            }
        }
        return k;
    }
};