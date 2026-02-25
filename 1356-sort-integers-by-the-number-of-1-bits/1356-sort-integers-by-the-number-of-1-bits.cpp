class Solution {
public:
   static bool comp(int a, int b){
        int c1=0,c2=0,a1=a,b1=b;
        while(a){
            c1+= 1&a;
            a>>=1;
        }
        while(b){
            c2+= 1&b;
            b>>=1;
        }
        if(c1<c2) return true;
        else if(c1==c2 && a1<b1)return true;
        return false;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};