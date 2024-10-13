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

            int val=temp.first.first;
            int index=temp.first.second;
            int column=temp.second;
            pq.pop();
            
            if(diff>maxVal-val){
                diff=maxVal-val;
                end=maxVal;
                start=val;
            }
            if(column+1<nums[index].size()){
                
            pq.push({{nums[index][column+1],index},column+1});
            maxVal=max(maxVal,nums[index][column+1]);
            }
        }
       
        return {start,end};
    }
};