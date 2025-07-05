class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> limit(1001,0);
        for(auto trip:trips){
            limit[trip[1]]+=trip[0];
            limit[trip[2]]-=trip[0];
            
        }
        for(int i=0;capacity>=0 && i<=1000; i++){
            capacity-=limit[i];
        }
        return capacity>=0;
    }
};