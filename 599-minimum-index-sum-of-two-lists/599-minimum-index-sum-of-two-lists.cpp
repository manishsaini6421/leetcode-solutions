class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,pair<int,int>> m;
        for(int i=0; i<list1.size(); i++){
            m[list1[i]].first++;
            m[list1[i]].second=i;
        }
        for(int i=0; i<list2.size(); i++){
           m[list2[i]].first++;
            m[list2[i]].second+=i;
        }
        
        vector<string> ans;
        int min=2001;
        for(auto x:m){
            if(x.second.first >1 && x.second.second <min) min=x.second.second;
        }
        for(auto y:m){
            if(y.second.first >1 && y.second.second==min) ans.push_back(y.first);
        }
        return ans;
    }
};