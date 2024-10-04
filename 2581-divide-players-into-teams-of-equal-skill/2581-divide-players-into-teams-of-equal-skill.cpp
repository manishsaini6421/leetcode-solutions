class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());

        int i=0,j=skill.size()-1,temp=skill[0]+skill[j];
        
        long long res=0;

        while(i<j){
            if(temp!=skill[i]+skill[j]) return -1;
            res+=skill[i]*skill[j];
            i++;
            j--;
        }
        
       
        return res;


    }
};