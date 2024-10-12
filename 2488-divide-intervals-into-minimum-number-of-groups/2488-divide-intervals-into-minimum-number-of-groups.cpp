class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> st;
          vector<int> ed;

        for(auto interval:intervals){
            st.push_back(interval[0]);
            ed.push_back(interval[1]);
        }
        
        sort(st.begin(),st.end());
        sort(ed.begin(),ed.end());
        int res=0,ed_ptr=0;
        
        for(auto stnum:st){
            if(stnum > ed[ed_ptr]){
                ed_ptr++;
            }
            else{
                res++;
            }
            
        }
        return res;

    }
};