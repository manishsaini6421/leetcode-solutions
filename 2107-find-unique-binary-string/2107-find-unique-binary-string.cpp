class Solution {
public:
string binary(int x,int n){
    string s="";
    for(int i=0; i<n; i++){
        s+='0';
    }
    int i=n-1;
    while(x>0){
        if(x%2)s[i]='1';
        else s[i]='0';
        x/=2;
        i--;
    }
    return s;
}
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n=nums.size();
        
        for(int i=0; i<pow(2,n); i++){
            
            if(find(nums.begin(),nums.end(),binary(i,n))==nums.end())return binary(i,n);
        }
        return "0";
    }
};