class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans=0;
        int n=citations.size();
        for(int i=0; i<n; i++){
            if(n-i<=citations[i]){
                cout<<i<<endl;
                ans=n-i;
                break;
            }
        }
        return ans;
    }
};