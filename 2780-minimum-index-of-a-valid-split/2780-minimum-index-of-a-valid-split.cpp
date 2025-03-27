class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int count=1,num=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]==num)count++;
            else if(nums[i]!=num && count>0)count--;
            else{
                num=nums[i];
                count=1;
            }
        }
        count=0;
        vector<int> v(n,0);

        if(nums[0]==num){
            v[0]=1;
            count++;
        }

        for(int i=1; i<n; i++){
            if(nums[i]==num){
                v[i]=1;
                count++;
            }
                
            v[i]+=v[i-1];
        }

        for(int i=0; i<n; i++){
            cout<<v[i]<<" ";
            if(v[i]>(i+1)/2 && count-v[i]>(n-i-1)/2)return i;
        }
        return -1;
    }
};