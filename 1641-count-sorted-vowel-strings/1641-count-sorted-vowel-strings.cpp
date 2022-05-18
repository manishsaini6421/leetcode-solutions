class Solution {
public:
    int a=1,e=1,i=1,o=1,u=1;
    int countVowelStrings(int n) {
        for(int j=1; j<n; j++){
            increment();
        }
        return a+e+i+o+u;
    }
    void increment(){
        a+=e+i+o+u;
        e+=i+o+u;
        i+=o+u;
        o+=u;
        
    }
};