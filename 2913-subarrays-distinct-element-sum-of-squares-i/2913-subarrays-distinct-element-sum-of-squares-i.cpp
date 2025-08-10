class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        map<array<int,2>,int> result; 
        for(int i=0; i<n; i++){
            map<int,int> count;
            for(int j=i; j<n; j++){
                count[nums[j]]++;
                result[{i,j}]=count.size();

            }
        }
        int ans=0;
        for(auto pair:result){
            ans+=(pair.second*pair.second);
        }
        return ans;
    }
};