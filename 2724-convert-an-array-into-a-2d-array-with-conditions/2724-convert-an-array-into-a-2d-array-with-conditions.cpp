class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto num:nums){
            map[num]++;
        }

        vector<vector<int>> v;
        while(!map.empty()){
            vector<int> x;

            for(auto it=map.begin(); it!=map.end(); ){
                x.push_back(it->first);
                it->second--;
                if(it->second==0){
                   it= map.erase(it);

                }
                else   ++it;
            }
            v.push_back(x);
        }
        return v;
        
    }
};