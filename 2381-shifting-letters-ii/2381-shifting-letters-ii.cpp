class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        int m=shifts.size();

        vector<int> arr(n+1,0);
        for(int i=0; i<m; i++){
            if(shifts[i][2]==1){
                arr[shifts[i][0]]+=1;
                arr[shifts[i][1]+1]-=1;
            }
            else{
                arr[shifts[i][0]]-=1;
                arr[shifts[i][1]+1]+=1;
            }
        }
        for(int i=1; i<n; i++){
            arr[i]+=arr[i-1];
        }
        for(int i=0; i<n; i++){
            int shift=arr[i]%26;
            if(shift<0)shift+=26;
            s[i]=((s[i]-'a'+shift)%26)+'a';
        }
        return s;
    }
};