class Solution {
public:
    // int maximumProduct(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     int n=nums.size()-1;
    //     return max(nums[n]*nums[n-1]*nums[n-2],nums[0]*nums[1]*nums[n]);
    // }
    int maximumProduct(vector<int>& nums) {
        vector<int> v(5);
       v[0]=INT_MAX;
       v[1]=INT_MAX;
       v[2]=INT_MIN;
       v[3]=INT_MIN;
       v[4]=INT_MIN;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=v[0]){
                v[1]=v[0];
                v[0]=nums[i];
            }
            else if(nums[i]<=v[1]){
                v[1]=nums[i];
            }
           
            if(nums[i]>=v[4]){
                v[2]=v[3];
                v[3]=v[4];
                v[4]=nums[i];
            }
            else if(nums[i]>=v[3]){
                v[2]=v[3];
                v[3]=nums[i];
            }
            else if(nums[i]>=v[2]){
                v[2]=nums[i];
            }
            

        }
       
       return max(v[0]*v[1]*v[4],v[2]*v[3]*v[4]);
        
    }
};