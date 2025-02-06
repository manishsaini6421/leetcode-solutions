class Solution {
public:

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int minele=nums[0],maxele=nums[0];
        int n=nums.size();
        int index=0;
        for(int i=0; i<n; i++){
            if(abs(nums[i]-minele)<=limit || abs(nums[i]-maxele)<=limit){
                maxele=max(nums[i],maxele);
                minele=min(minele,nums[i]);
            }
            else{
                
                sort(nums.begin()+index,nums.begin()+i);
                minele=nums[i];
                maxele=nums[i];
                index=i;
            }
        }
        sort(nums.begin()+index,nums.end());
        return nums;
    }
};