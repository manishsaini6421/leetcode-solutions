class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int ans=0,j=0,k=0;
        int arr[3]={0};
        for(int i=0; i<n; i++){
            arr[s[i]-'a']++;
            if(arr[0] && arr[1] && arr[2]){
                while(arr[0] && arr[1] && arr[2]){
                    arr[s[j]-'a']--;
                    j++;
                }
                ans+=(n-i+j-k-1 + (j-k-1)*(n-i-1));
                k=j;
            }
           
            
        }
        return ans;
    }
};