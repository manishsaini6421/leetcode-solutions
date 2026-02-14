class Solution {
public:
    bool isPrime(int num){
        if(num==1)return false;
        for(int i=2; i*i<=num; i++){
            if(num%i==0)return false;
        }
        return true;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> s;
        for(int num:nums){
            for(int i=1; i*i<=num; i++){
                if(num%i==0){
                    cout<<i<<" "<<num/i<<endl;
                    if(isPrime(i) && i!=1)s.insert(i);
                    if(isPrime(num/i))s.insert(num/i);
                }
                
            }
            
        }
        return s.size();
    }
};