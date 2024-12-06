class Solution {
public:
bool find(vector<int>& nums,int x,int i,int j){
    while(i<=j){
        int mid=(i+j)/2;
        if(nums[mid]==x)return true;
        if(nums[mid]>x)j=mid-1;
        else i=mid+1;
    }
    return false;
}
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> result;
        for(int i=1; i<=n; i++){
            if(!find(nums,i,0,n-1))result.push_back(i);
        }
        return result;
    }
};