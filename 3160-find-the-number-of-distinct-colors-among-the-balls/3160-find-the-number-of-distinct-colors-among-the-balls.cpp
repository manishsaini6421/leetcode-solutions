class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> map1;
        unordered_map<int,int>map2;
        int n=queries.size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            
            if(map1.find(queries[i][0])!=map1.end()){
                map2[map1[queries[i][0]]]--;
                
                if(map2[map1[queries[i][0]]]==0){
                    map2.erase(map1[queries[i][0]]);
                }
            }         
            map1[queries[i][0]]=queries[i][1];
            map2[queries[i][1]]++;
            ans.push_back(map2.size());
        }
        return ans;
    }
};