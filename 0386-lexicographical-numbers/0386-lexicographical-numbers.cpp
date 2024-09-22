class Solution {
public:
    vector<int> res;
   void fun(int x,int n){
    if(x>n) return;
    res.push_back(x);
    fun(x*10,n);
    if (x % 10 < 9) 
        fun(x + 1, n);
        
    
   }
    vector<int> lexicalOrder(int n) {
        
        fun(1,n);
        return res;
    }
};