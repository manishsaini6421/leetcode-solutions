class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int result = 0;
        string temp;
        if(x>y){
            
            for(int i=0; i<s.size(); i++){
                if(!temp.empty() && temp.back()=='a' && s[i]=='b'){
                    result+=x;
                    temp.pop_back();
                }
                else temp.push_back(s[i]);
            }
            string remaining;
            for(int i=0; i<temp.size(); i++){
                if(!remaining.empty() && remaining.back()=='b' && temp[i]=='a'){
                    result+=y;
                    remaining.pop_back();
                }
                else remaining.push_back(temp[i]);
            }
        }
        else{
            for(int i=0; i<s.size(); i++){
                if(!temp.empty() && temp.back()=='b' && s[i]=='a'){
                    result+=y;
                    temp.pop_back();
                }
                else temp.push_back(s[i]);
            }
            string remaining;
            for(int i=0; i<temp.size(); i++){
                if(!remaining.empty() && remaining.back()=='a' && temp[i]=='b'){
                    result+=x;
                    remaining.pop_back();
                }
                else remaining.push_back(temp[i]);
            }
        }
        return result;
    }
};