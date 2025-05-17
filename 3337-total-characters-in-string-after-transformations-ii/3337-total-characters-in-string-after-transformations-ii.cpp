#define MOD 1000000007
class Solution {
public:
    vector<vector<int>> matmul(vector<vector<int>> & mt1, vector<vector<int>> & mt2){
        int m=mt1.size();
        int n=mt1[0].size();
        int p=mt2[0].size();

        vector<vector<int>> result(m,vector<int> (p,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<p; j++){
                for(int k=0; k<n; k++){
                    result[i][j]+=mt1[i][k]*mt2[k][j];
                }
            }
        }
        return result;
    }
    vector<vector<int>> exponent(vector<vector<int>> & mt,int n){
        if(n==0){
            vector<vector<int>> I(mt.size(),vector<int> (mt.size(),0));
            for(int i=0; i<mt.size(); i++){
                I[i][i]=1;
            }
            return I;
        }
        if(n==1)return mt;

        vector<vector<int>> result=exponent(mt,n/2);
        result=matmul(result,result);
        if(n%2)result=matmul(result,mt);

        return result;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int n=s.size();
        vector<vector<int>> T(26,vector<int> (26,0));
        for(int i=0; i<26; i++){
            for(int j=1; j<=nums[i]; j++){
                T[(i+j)%26][i]+=1;
            }
        }
        vector<vector<int>> temp(26,vector<int>(1,0));
        for(int i=0; i<s.size(); i++){
            temp[s[i]-'a'][0]++;
        }
        vector<vector<int>> exp=exponent(T,t);
        exp=matmul(exp,temp);

        int ans=0;
        for(int i=0; i<26; i++){
            ans=(ans+exp[i][0])%MOD;
        }
        return ans;
    }
};