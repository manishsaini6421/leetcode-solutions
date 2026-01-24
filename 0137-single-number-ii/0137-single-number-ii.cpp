class Solution {
public:
    // int singleNumber(vector<int>& nums) {
    //     int n=nums.size();
    //     sort(nums.begin(),nums.end());
    //     int count=1,x=nums[0];
    //     for(int i=1; i<n; i++){
    //         if(nums[i]!=x){
    //             if(count==1)
    //                 return x;
    //             x=nums[i];
    //             count=1;    
    //         }
    //         else count++;
    //     }
    //     return nums[n-1];

    // }
     

    //Using Bit Manipulation 
    int singleNumber(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        int num=0;
        for(int i=0; i<32; i++){
            for(int j=0; j<n; j++){
                count+=(nums[j]>>i & 1);
               
            }
            if(count%3==1)num|=(1<<i);
            count=0;
        }
      
        
        return num;
    }

};