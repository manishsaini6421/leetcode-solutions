class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(int i=0; i<details.size(); i++){
            int t=(details[i][11]-'0')*10+(details[i][12]-'0');
            if(t>60) res++;
        }
        return res;
    }
};