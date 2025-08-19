class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int n=nums.size();
        if(n<3)return 0;

        int temp=0; int ans=0;
        int diff=nums[1]-nums[0];
        for(int i=2; i<n; i++){
            if(nums[i]-nums[i-1]==diff)temp++;
            else{
                diff=nums[i]-nums[i-1];
                temp=0;
            }
            ans+=temp;
            cout<<ans<<endl;
        }
        return ans;
    }
};