class Solution {
public:

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
       
        int n=nums.size();
        vector<int> sortedCopy(nums);
        sort(sortedCopy.begin(),sortedCopy.end());
       unordered_map<int,int> map;
       unordered_map<int,vector<int>> List;
       int group=0;
       map[sortedCopy[0]]=0;
        List[0].push_back(sortedCopy[0]);
        for(int i=1; i<n; i++){
            if(sortedCopy[i]-sortedCopy[i-1]<=limit){
                map[sortedCopy[i]]=group;
                
            }
            else{
                group++;
                map[sortedCopy[i]]=group;
                
            }
            List[group].push_back(sortedCopy[i]);
        }
        for(auto elements:List){
            sort(elements.second.begin(),elements.second.end());
        }
        for(int i=0; i<n; i++){
            int group=map[nums[i]];
            nums[i]=*List[group].begin();
            List[group].erase(List[group].begin());
        }


        return nums;
    }
};