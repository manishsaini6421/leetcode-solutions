class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        for(int i=n-2; i>=0; i--){
            shifts[i]+=shifts[i+1];
        }
        // reverse(shifts.begin(),shifts.end());

        // cout<<shifts[0]<<" "<<shifts[1]<<" "<<shifts[2]<<endl;
        for(int i=0; i<n; i++){
            s[i]=((s[i]-'a'+shifts[i])%26)+'a';
        }
        return s;

    }
};