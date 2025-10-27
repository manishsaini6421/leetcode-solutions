class Solution {
public:
    // int numberOfBeams(vector<string>& bank) {
    //     int m=bank.size();
    //     int n=bank[0].size();

    //     vector<int> count(m,0);
    //     for(int i=0; i<m; i++){
    //         int temp=0;
    //         for(int j=0; j<n; j++){
    //             if(bank[i][j]-'0'==1)temp++;
    //         }
    //         count[i]=temp;
    //     }
       
    //     int ans=0;
    //     for(int i=0; i<m-1; i++){
    //         int j=i+1;
    //         while(j<m-1 && count[j]==0){
    //             j++;
    //         }
    //         ans+=(count[i]*count[j]);
    //     }
    //     return ans;
    // }


    //Optimized
    int numberOfBeams(vector<string>& bank) {
        int m=bank.size();
        int n=bank[0].size();

        int next=0;
        int ans=0;
        for(int i=m-1; i>=0; i--){
            int temp=0; 
            for(int j=0; j<n; j++){
                if(bank[i][j]-'0'==1)temp++;
            }
            ans+=(temp*next);
            next=temp?temp:next;
            cout<<next<<" "<<ans<<endl;
        }
        return ans;
    }
};