class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
       vector<int> v;
       for(auto num:nums){
        auto it=lower_bound(v.begin(),v.end(),num);

        if(it==v.end()){
            v.push_back(num);
        }
        else{
            *it=num;
        }
       }
        return v.size();
    }
};