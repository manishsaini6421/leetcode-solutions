class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first=LLONG_MIN,second=LLONG_MIN,third=LLONG_MIN;
        for(int num:nums){
            if(num==first || num==second || num==third)continue;
            if(num>first){
                third=second;
                second=first;
                first=num;
            }
            else if(num>second){
                third=second;
                second=num;
            }
            else third=num;
        }
        return third==LLONG_MIN ? first:third;
        
    }
};