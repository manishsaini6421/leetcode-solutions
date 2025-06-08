class Solution {
public:
    int solve(vector<int>& nums,int index){
        if(index>=nums.size()-1)return 0;

        int ans=INT_MAX;
        for(int i=1; i<=nums[index]; i++){
            int temp=solve(nums,index+i);
            if(temp!=INT_MAX)
            ans=min(ans,1+temp);
        }
        return ans;
    }

    int jump(vector<int>& nums) {
        return solve(nums,0);
    }
};