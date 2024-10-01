class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(arr.size()==0) return false;
        vector<vector<int>> store(k);
       for(int i=0; i<arr.size(); i++){
            cout<<i<<endl;
            int a;
            if(arr[i]<0){
                if(arr[i]%k==0)
                    a=0;
                else{
                    a=k+(arr[i]%k);
                    
                }  
                store[a].push_back(arr[i]);  
                
            }
            else{
                
                a=arr[i]%k;
                store[a].push_back(arr[i]);
                
            }
       }     
        
        if(store[0].size()%2!=0)
            return false;
        int i=1,j=store.size()-1;    
        while(i<j){
            if(store[i].size()!=store[j].size())
                return false;
            i++;
            j--;    
        }
        if(k%2==0 && (store[k/2].size())%2!=0)
            return false;
       
        return true;
    }
};