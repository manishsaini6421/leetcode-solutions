class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int result = 0;
        int n=s.size();
        string temp;
        if(x>y){
            
            for(int i=0; i<n; i++){
                if(!temp.empty() && temp.back()=='a' && s[i]=='b'){
                    result+=x;
                    temp.pop_back();
                }
                else temp.push_back(s[i]);
            }
            string remaining;
            int t=temp.size();
            for(int i=0; i<t; i++){
                if(!remaining.empty() && remaining.back()=='b' && temp[i]=='a'){
                    result+=y;
                    remaining.pop_back();
                }
                else remaining.push_back(temp[i]);
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(!temp.empty() && temp.back()=='b' && s[i]=='a'){
                    result+=y;
                    temp.pop_back();
                }
                else temp.push_back(s[i]);
            }
            string remaining;
            int t=temp.size();
            for(int i=0; i<t; i++){
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