class Solution {
public:
    int dfs(int start,string s, unordered_set<string>set){
        if(start==s.size()) return 0;
        int maxLength=0;
        int n=s.size();
        for(int i=start+1; i<=n; i++){
            string subs=s.substr(start,i-start);
            if(set.find(subs)==set.end()){
                set.insert(subs);
                maxLength=max(maxLength,1+dfs(i,s,set));
                set.erase(subs);
            }
        }
        return maxLength;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>map;
        return dfs(0,s,map);
    }
};