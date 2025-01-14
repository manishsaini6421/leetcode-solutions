class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n=A.size();
        vector<int> v(n+1,0);
        vector<int> C(n,0);
        int ans=0;
        for(int i=0; i<n; i++){
            v[A[i]]++;
            v[B[i]]++;
            if(v[A[i]]>1)ans++;
            if(A[i]!=B[i] && v[B[i]]>1)ans++;
            C[i]=ans;
        }
        return C;
    }
};