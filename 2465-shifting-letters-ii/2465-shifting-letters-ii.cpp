class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=shifts.size();
        int m=s.size();
        int arr[m+1];
        for(int i=0; i<=m; i++){
            arr[i]=0;
        }
        for(int i=0; i<n; i++){
            if(shifts[i][2]==0){
                arr[shifts[i][0]]-=1;
                arr[shifts[i][1]+1]+=1;
            }
            else{
                arr[shifts[i][0]]+=1;
                arr[shifts[i][1]+1]-=1;
            }
            
        }
        int sum=0;
        for(int i=0; i<m; i++){
            sum+=arr[i];
            arr[i]=sum;
        }
        for(int i=0; i<m; i++){
            int shift=arr[i]%26;
            if(shift<0)shift+=26;
            s[i]='a'+(s[i]-'a'+shift)%26;
            
        }
        return s;
    }
};