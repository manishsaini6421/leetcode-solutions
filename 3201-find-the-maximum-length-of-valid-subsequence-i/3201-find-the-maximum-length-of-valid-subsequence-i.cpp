class Solution {
public:
    
    
    int maximumLength(vector<int>& nums) {
        int odd=0,even=0;
        
        int flag=0,count=1;
        if(nums[0]%2){
            odd++;
            flag=1;
        }
        else{
            even++;
        }

        int n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]%2==0){
                even++;
                if(flag==1){
                    flag=0;
                    count++;
                }
                
                
            }
            else if(nums[i]%2==1){
                odd++;
                if(flag==0){
                     flag=1;
                count++;
                }
               
            }
        }
        return max(count,max(odd,even));
    }
};