class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            vector<int> temp;
            temp.push_back(intervals[i][0]);
            int maxVal=intervals[i][1];
            while(i+1<n && intervals[i+1][0]<=maxVal){
                maxVal=max(maxVal,intervals[i+1][1]);
                i++;
            }
            temp.push_back(maxVal);
            ans.push_back(temp);
        }
        return ans;
    }
};