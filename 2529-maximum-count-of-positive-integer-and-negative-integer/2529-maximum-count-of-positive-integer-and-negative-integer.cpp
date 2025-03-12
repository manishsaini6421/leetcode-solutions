class Solution {
public:
    int searchPos(vector<int>& nums,int i,int j){
        if(i>j)return -1;
        int mid=(i+j)/2;

        if(nums[mid]>0){
            if(mid==0)return 0;
            else if(nums[mid-1]<=0)return mid;
            else return searchPos(nums,i,mid-1);
        }
        return  searchPos(nums,mid+1,j);
        
    }

    int searchNeg(vector<int>& nums,int i,int j){
        if(i>j)return -1;
        int mid=(i+j)/2;

        if(nums[mid]<0){
            if(mid==nums.size()-1)return mid;
            else if(nums[mid+1]>=0)return mid;
            else return searchNeg(nums,mid+1,j);
        }
        return  searchNeg(nums,i,mid-1);
        
    }

    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        return max(n-searchPos(nums,0,n-1),searchNeg(nums,0,n-1)+1);

    }
};