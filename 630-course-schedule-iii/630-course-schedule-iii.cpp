class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[this](auto &p ,auto &q){return p[1]<q[1];});
       int sum=0;
        priority_queue<int> q;
        for(auto x:courses){
            sum+=x[0];
            q.push(x[0]);
            if(sum>x[1]){
                sum-=q.top();
                q.pop();
            }
        }
        return q.size();
    }
};