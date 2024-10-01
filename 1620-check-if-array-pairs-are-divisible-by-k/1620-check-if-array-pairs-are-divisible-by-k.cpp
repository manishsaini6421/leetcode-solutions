class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k,0);
       for(int i=0; i<arr.size(); i++){
            cout<<i<<endl;
            int a;
            if(arr[i]<0){
                if(arr[i]%k==0)
                    a=0;
                else
                    a=k+(arr[i]%k);

            }
            else                
                a=arr[i]%k;

            freq[a]++;
                
            
       }     
        
        if(freq[0]%2 !=0)
            return false;

        int i=1,j=k-1;    
        while(i<j){
            if(freq[i]!=freq[j])
                return false;
            i++;
            j--;    
        }
        if(k%2==0 && freq[k/2]%2!=0)
            return false;
       
        return true;
    }
};