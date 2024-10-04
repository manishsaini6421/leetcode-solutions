class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0,j=skill.size()-1,temp=skill[0]+skill[j];
        vector<vector<int>> a;
        while(i<j){
            if(temp!=skill[i]+skill[j]) return -1;
            vector<int> x;
            x.push_back(skill[i]);
            x.push_back(skill[j]);
            a.push_back(x);
            i++;
            j--;
        }
        long long res=0;
        for(auto val:a){
            res+=val[0]*val[1];
        }
        return res;


    }
};