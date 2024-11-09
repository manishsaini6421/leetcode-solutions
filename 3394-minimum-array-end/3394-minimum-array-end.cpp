class Solution {
public:
    long long minEnd(int n, int x) {
        
       vector<int> bitX(64,0);
       vector<int> bitN(64,0);

        n--;
        int i=0;
        while(x!=0 || n!=0){
            bitX[i]=x&1;
            bitN[i]=n&1;
            x>>=1;
            n>>=1;
            i++;
        }
        i=0;
        int j=0;
        while(i<64){
            if(bitX[i]==1)i++;
            else{
                bitX[i]=bitN[j];
                i++;
                j++;
            }
            
        }
        long long int ans=0;
        for(int i=0;i<64; i++){
            ans+=bitX[i]*pow(2,i);
        }
        return ans;
    }

};