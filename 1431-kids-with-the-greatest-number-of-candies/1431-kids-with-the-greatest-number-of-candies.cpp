class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int max_num=0;
        for(int i=0; i<candies.size(); i++){
            if(candies[i]>max_num){
                max_num=candies[i];
            }
        }
        
        for(int i=0; i<candies.size(); i++){
            if(candies[i]+extraCandies >=max_num){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};