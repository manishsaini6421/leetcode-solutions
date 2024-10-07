class Solution {
public:
    int minLength(string s) {
        int i=0;
        while(i<s.size()){
            if(i==0 && ((s[i]=='A' && s[i+1]=='B') || (s[i]=='C' && s[i+1]=='D'))){
                s.erase(i,2);
                cout<<"hii"<<endl;
                continue;
            }
            else if(s[i]=='A' && s[i+1]=='B'){
                s.erase(i,2);
                i--;
                cout<<"hello"<<endl;
                
            }
            else if(s[i]=='C' && s[i+1]=='D'){
                cout<<"hii"<<endl;
                s.erase(i,2);
                i--;
            }
           else i++;
            cout<<i<<" ";
            cout<<s.size()<<endl;
            
        }
        return s.size();
    }
};