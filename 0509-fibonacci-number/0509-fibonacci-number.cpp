class Solution {
public:
    vector<vector<int>> matmul(vector<vector<int>> &mt1,vector<vector<int>> &mt2){
        int m=mt1.size();
        int n=mt1[0].size();
        int p=mt2[0].size();

        vector<vector<int>> ans(m,vector<int> (p,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<p; j++){
                for(int k=0; k<n; k++){
                    ans[i][j]+=mt1[i][k]*mt2[k][j];
                }
                
            }
        }
        return ans;
    }
    vector<vector<int>> matrixExpo(vector<vector<int>> &mt,int n){
        if(n==0){
            vector<vector<int>> temp(mt.size(),vector<int>(mt.size(),0));
            for(int i=0; i<mt.size(); i++){
                temp[i][i]=1;

            }
            return temp;
        }
        if(n==1)return mt;
        vector<vector<int>> ans=matrixExpo(mt,n/2);
        ans=matmul(ans,ans);
        if(n%2)ans=matmul(ans,mt);
        return ans;
        
    }
    int fib(int n) {
        // if(n<=1)return n;
        // int temp1=0,temp2=1;
        // for(int i=2; i<=n; i++){
        //     int temp=temp2;
        //     temp2=temp2+temp1;
        //     temp1=temp;
        // }
        // return temp2;

        if(n<=1)return n;
        vector<vector<int>> mt(2,vector<int> (2,0));
        mt[0][0]=1;
        mt[0][1]=1;
        mt[1][0]=1;

        vector<vector<int>> temp(2,vector<int>(1,0));
        temp[0][0]=1;

        mt=matrixExpo(mt,n-1);
        vector<vector<int>> ans=matmul(mt,temp);
        return ans[0][0];
    }
};