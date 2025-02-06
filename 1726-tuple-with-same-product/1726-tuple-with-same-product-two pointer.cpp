class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
       

        for(int i=0; i<n; i++){
            for(int j=n-1; j>i; j--){
                int x=nums[i]*nums[j];
            int k=i+1,l=j-1;
            while(k<l && k<n && l>=0){
                if(nums[k]*nums[l]==x){
                    ans+=8;
                    k++;
                    l--;
                }
                else if(nums[k]*nums[l]<x){
                    k++;
                }
                else l--;
            }
            }
            

        }
        return ans;

    }
};