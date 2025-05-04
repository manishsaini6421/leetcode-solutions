class Solution {
public:
    static bool manual(vector<int> a,vector<int> b){
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
         int n = dominoes.size();
        for(int i=0; i<n; i++){
            if(dominoes[i][0]>dominoes[i][1]){
                int temp=dominoes[i][0];
                dominoes[i][0]=dominoes[i][1];
                dominoes[i][1]=temp;
            }
        }
        sort(dominoes.begin(), dominoes.end());

        for(auto nums:dominoes){
            cout<<nums[0]<<" "<<nums[1]<<endl;
        }
       
        int a = dominoes[0][0], b = dominoes[0][1];

        int ans = 0;
        int count=1;
        for (int i = 1; i < n; i++) {
            if ((dominoes[i][0] == a && dominoes[i][1] == b) ||
                (dominoes[i][0] == b && dominoes[i][1] == a))
                count++;
            else {
                ans += (count * (count - 1) / 2);
                count = 1;
                a = dominoes[i][0];
                b = dominoes[i][1];
            }
        }
        ans += (count * (count - 1) / 2);
        return ans;
    }
};