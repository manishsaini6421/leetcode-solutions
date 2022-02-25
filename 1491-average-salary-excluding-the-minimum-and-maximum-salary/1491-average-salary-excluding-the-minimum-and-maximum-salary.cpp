class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size();
        int minSal=INT_MAX;
        int maxSal=INT_MIN;
        for(int i=0; i<n; i++){
            minSal=min(minSal,salary[i]);
            maxSal=max(maxSal,salary[i]);
        }
        double sum=0;
        for(int i=0; i<n; i++){
            sum+=salary[i];
        }
        return (sum-minSal-maxSal)/(n-2);
    }
};