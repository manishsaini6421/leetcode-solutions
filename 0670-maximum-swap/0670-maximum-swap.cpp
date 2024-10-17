class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        int maxIndex=n-1,swap1=-1,swap2=-1;
        for(int i=n-1; i>=0; i--){
            if(s[i]>s[maxIndex])maxIndex=i;
            else if(s[i]<s[maxIndex]){
                swap1=i;
                swap2=maxIndex;
            }
        }
        if(swap1==-1 && swap2==-1) return stoi(s);
        char temp=s[swap1];
        s[swap1]=s[swap2];
        s[swap2]=temp;
        return stoi(s);
    }
};