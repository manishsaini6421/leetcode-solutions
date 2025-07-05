class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> limit(1001,0);
        for(auto trip:trips){
            for(int i=trip[1]; i<=trip[2]; i++){
                limit[i]+=trip[0];
            }
        }
        for(int i=0; i<=1000; i++){
            if(limit[i]>capacity)return false;
        }
        return true;
    }
};