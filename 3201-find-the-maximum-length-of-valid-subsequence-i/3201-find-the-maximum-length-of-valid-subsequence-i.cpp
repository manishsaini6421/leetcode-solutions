class Solution {
public:
    
    
    int maximumLength(vector<int>& nums) {
        int odd=0,even=0;
        for(int num:nums){
            if(num%2)odd++;
            else even++;
        }

        int flag=0,count=1;
        if(nums[0]%2){
            flag=1;
        }

        
        for(int num:nums){
            if(num%2==0 && flag==1){
                flag=0;
                count++;
                
            }
            else if(num%2==1 && flag==0){
                flag=1;
                count++;
            }
        }
        cout<<count;
        return max(count,max(odd,even));
    }
};