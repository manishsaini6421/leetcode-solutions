class Solution {
public:
     
    int countVowelStrings(int n) {
     vector<vector<int>> dp;
        vector<int> temp(5,1);
        dp.push_back(temp);
        if(n==1)
            return arrSum(dp[n-1]);
        else{
            for(int i=0; i<n-1; i++){
                vector<int> temp(5);
                temp[4]=1;
                for(int j=3; j>=0; j--){
                    temp[j]=dp[i][j]+temp[j+1];
                }
                dp.push_back(temp);
            }
            
        }
        return arrSum(dp[n-1]);
    }
    
    int arrSum(vector<int> arr){
        int sum=0;
        for(int i=0; i<5; i++){
            sum+=arr[i];
        }
        return sum;
    }
};