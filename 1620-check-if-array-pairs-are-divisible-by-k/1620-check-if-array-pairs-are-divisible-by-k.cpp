class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k,0);
       for(auto num :arr){
            int rem=((num%k)+k)%k;
            freq[rem]++;          
            
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