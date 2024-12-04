class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int n=spaces.size();
        int x=0;
        for(int i=0; i<n; i++){
            spaces[i]+=x;
            x++;
        }
        int i=0,j=0,k=0;
        while(i<n){
            if(k==spaces[i]){
                ans+=' ';
                i++;
            }
            else{
                ans+=s[j];
                j++;
            }
            k++;
        }
        while(j<s.size()){
            ans+=s[j];
                j++;
        }
        return ans;
    }
};