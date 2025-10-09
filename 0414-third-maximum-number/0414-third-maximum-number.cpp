class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        int n=nums.size();
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
       vector<int> v;
       for(auto num:s){
            v.push_back(num);
       }
       if(v.size()>2)return v[v.size()-3];
       return v[v.size()-1];
        
    }
};