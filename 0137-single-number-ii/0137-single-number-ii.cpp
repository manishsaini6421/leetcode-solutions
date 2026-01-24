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
        int A[32]={0};
        int n=nums.size();
        for(int i=0; i<32; i++){
            for(int j=0; j<n; j++){
                A[31-i]+=(nums[j]&1);
                nums[j]>>=1;
            }
        }
        int num=0;
        long pow=1;
        for(int i=31; i>=0; i--){
            num+=(A[i]%3)*pow;
            pow*=2;
        }
        return num;
    }

};