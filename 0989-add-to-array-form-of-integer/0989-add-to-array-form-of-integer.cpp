class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> arrayK;
        while(k>0){
            arrayK.push_back(k%10);
            k/=10;
        }
         reverse(arrayK.begin(),arrayK.end());
        while(arrayK.size()!=num.size()){
            if(arrayK.size()>num.size()){
                num.insert(num.begin(),0);
            }
            else arrayK.insert(arrayK.begin(),0);
        }
        
        int c=0;

        for(int i=num.size()-1; i>=0; i--){
            int x=num[i]+arrayK[i]+c;
            num[i]=x%10;
            c=x/10;
        }
        if(c!=0)num.insert(num.begin(),c);
        return num;
    }
};