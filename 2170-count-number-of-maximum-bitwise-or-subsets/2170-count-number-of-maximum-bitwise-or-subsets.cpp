class Solution {
public:
    
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR=0,ans=0;
        int n=nums.size();
        for(auto num:nums){
            maxOR|=num;
        }
        for(int i=0; i<pow(2,n); i++){
            vector<int> v;
            for(int j=0; j<n; j++){
                if(i & (1<<j)) v.push_back(nums[j]);
            }
            int temp=0;
            for(auto val:v){
                temp|=val;
            }
            if(temp==maxOR)ans++;
        }
        cout<<maxOR<<endl;
        return ans;
    }
};