class Solution {
public:

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        for(int i=1; i<=n; i++){
            result.push_back(i);
        }
        int temp=1;
        for(int i=0; i<n; i++){
            result[nums[i]-1]=0;
        }
        for(auto it=result.begin(); it!=result.end();){
            if(*it==0)it=result.erase(it);
            else it++;
        }
        return result;
    }
};