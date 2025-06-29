#define MOD 1000000007
class Solution {
public:
    int pow(int a,int b){
        if(b==0)return 1;

        int temp=pow(a,b/2);
        if(b%2)return (temp*1l*temp*a)%MOD;
        return (temp*1l*temp)%MOD;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int i=0,j=nums.size()-1;
        int ans=0;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                ans= (ans + pow(2 ,j-i))%MOD;
                i++;
            }
            else j--;
        }
        return ans;
    }
};