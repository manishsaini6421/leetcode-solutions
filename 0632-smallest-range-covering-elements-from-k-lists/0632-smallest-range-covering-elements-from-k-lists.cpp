class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;

        int maxVal=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            pq.push({{nums[i][0],i},0});
            if(nums[i][0]>maxVal)maxVal=nums[i][0];

        }
        
        int start=0,end=INT_MAX,diff=INT_MAX;
        
        while(pq.size()==nums.size()){
            pair<pair<int,int>,int> temp;
            temp=pq.top();
            pq.pop();
            
            if(diff>maxVal-temp.first.first){
                diff=maxVal-temp.first.first;
                end=maxVal;
                start=temp.first.first;
            }
            if(temp.second+1<nums[temp.first.second].size()){
                
            pq.push({{nums[temp.first.second][temp.second+1],temp.first.second},temp.second+1});
            maxVal=max(maxVal,nums[temp.first.second][temp.second+1]);
            }
        }
       
        return {start,end};
    }
};