class Solution {
public:
    bool isPrime(int n){
        if(n==1)return false;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0)return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
       
        vector<int> v;
        for(int i=left; i<=right; i++){
             if(isPrime(i)){
                v.push_back(i);
             }
        }
        if(v.size()<=1)return {-1,-1};
        int first=v[0],second=v[1],diff=v[1]-v[0];

        for(int i=1; i<v.size()-1; i++){
            if(v[i+1]-v[i]<diff){
                first=v[i];
                second=v[i+1];
                diff=v[i+1]-v[i];
            }
        }
        return {first, second};
    }
};