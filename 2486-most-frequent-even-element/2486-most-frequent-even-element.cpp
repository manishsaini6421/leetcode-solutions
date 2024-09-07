class Solution {
public:
    
    int mostFrequentEven(vector<int>& nums) {
       unordered_map<int, int> umap;
       for(int i=0; i<nums.size(); i++){
        if(nums[i]%2!=0)
        continue;
        else{
           umap[nums[i]]+=1;
        }
       }
        int num=-1;
        int count=0;
       for(auto it:umap){
            if(it.second>count){
                num=it.first;
                count=it.second;
            }
            else if(it.second==count && num>it.first){
                num=it.first;
                count=it.second;
            }
       }
      
       return num;
       
    }
};