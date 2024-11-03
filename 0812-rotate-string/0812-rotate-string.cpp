class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();

        while(n>0){
            s+=s[0];
            s.erase(s.begin());
            cout<<s<<endl;
            if(s==goal)return true;
            n--;
        }
        return false;
    }
};