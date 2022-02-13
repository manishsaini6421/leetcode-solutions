class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size()==1){
            vector<int> result;
            result.push_back(nums[0]*nums[0]);
            return result;
        }
        int mid=0,temp;
        int f=0,r;
        while(f<nums.size()-1){
            temp=abs(nums[f]);
           
            if(temp<abs(nums[f+1])){
                    break;
                }
            f++;
        }
        mid=f;
        cout<<mid;
        vector<int> result;
        result.push_back(nums[mid]*nums[mid]);
        f=mid-1;
        r=mid+1;
        while(f>=0 && r<nums.size()){
        if((nums[f]*nums[f])>(nums[r]*nums[r])){
            result.push_back(nums[r]*nums[r]);
                r++;
        }
        else if((nums[f]*nums[f])<(nums[r]*nums[r])){
            result.push_back(nums[f]*nums[f]);
                f--;
        }
        else{
             result.push_back(nums[f]*nums[f]);
                f--;
        }
        }
        while(f>=0){
            result.push_back(nums[f]*nums[f]);
                f--;
        }
        while(r<nums.size()){
            result.push_back(nums[r]*nums[r]);
                r++;
        }
        return result;
    }
};