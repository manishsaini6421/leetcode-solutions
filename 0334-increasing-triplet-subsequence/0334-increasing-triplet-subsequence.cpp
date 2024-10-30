class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> v;
        int count=0;
        for(auto num:nums){
            auto it=lower_bound(v.begin(),v.end(),num);
            if(it==v.end()){
                v.push_back(num);
                count++;
                if(count==3)return true;
            }
            else{
                *it=num;
            }    
            
        }
        return false;
    }
};