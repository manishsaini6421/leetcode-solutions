class Solution {
public:
   /* int singleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=1,x=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]!=x){
                if(count==1)
                    return x;
                x=nums[i];
                count=1;    
            }
            else count++;
        }
        return nums[n-1];

    } */
     

    //Using Bit Manipulation 
    //at every place in binary representation 1's count should be k(i.e. 3)
    //if k%3!=0 then relsut bit set to 1 on that place.
    // T(n)=N*32
    //SC=O(1)
    /* int singleNumber(vector<int>& nums) {
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
    } */
    
    //Using Sorting
    //TC=NlogN <= N*32 because logN=32 when N is 2^32
    //SC = O(1)
    //So this is better solution
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1; i<n; i+=3){
            if(nums[i]!=nums[i-1])return nums[i-1];
            if(i<n-1 && nums[i]!=nums[i+1])return nums[i+1];
        }
        return nums[n-1];
    }



};