class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int n=brackets.size();
        double ans=0;
        if(income-brackets[0][0]>=0){
            ans+=(double)brackets[0][0]*(double)brackets[0][1]/(double)100;
            income-=brackets[0][0];
        }
        else{
            ans+=(double)income*(double)brackets[0][1]/(double)100;
            return ans;
        }
        
        for(int i=1; i<n; i++){
            if(income-(brackets[i][0]-brackets[i-1][0])>=0){
                ans+=((double)(brackets[i][0]-brackets[i-1][0])*(double)brackets[i][1]/(double)100);
                income-=(brackets[i][0]-brackets[i-1][0]);
            }
            else {
                ans+=(double)income*(double)brackets[i][1]/(double)100;
                break;

            }
            
        }
        return ans;
    }
};