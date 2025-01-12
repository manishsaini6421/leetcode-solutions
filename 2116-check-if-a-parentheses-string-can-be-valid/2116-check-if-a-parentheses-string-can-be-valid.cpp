class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2!=0)return false;
        vector<int> v1;
        vector<int> v2;

        for(int i=0; i<s.size(); i++){
           if(locked[i]=='0')v1.push_back(i);
           else{
            if(s[i]=='(')v2.push_back(i);
            else{
                if(v2.size()>0)v2.pop_back();
                else if(v1.size()>0) v1.pop_back();
                else return false;
            }
           }
        }
        while(!v2.empty()){

            if(v1.size()>0 && v2[v2.size()-1]<v1[v1.size()-1]){
                    v1.pop_back();
                    v2.pop_back();
                
            }
            else return false;
        }
        
        return true;
    }
};