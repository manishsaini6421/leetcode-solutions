class Solution {
public:
    int dfs(int start,string s, unordered_map<string,int>map){
        if(start==s.size()) return 0;
        int maxLength=0;
        for(int i=start+1; i<=s.size(); i++){
            string subs=s.substr(start,i-start);
            if(!map[subs]){
                map[subs]++;
                maxLength=max(maxLength,1+dfs(i,s,map));
                map.erase(subs);
            }
        }
        return maxLength;
    }
    int maxUniqueSplit(string s) {
        unordered_map<string,int>map;
        return dfs(0,s,map);
    }
};