class Solution {
public:
    int search(vector<int>& stones, int x, int i, int j) {
        int mid;
        while (i <= j) {
            mid = i+ (j-i)/2;
            if (stones[mid] == x)
                return mid;
            else if (stones[mid] > x) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return -1;
    }
    bool solve(vector<int>& stones, int index, int k) {
        int n=stones.size();
        if (index == n-1)
            return true;
        bool first = false;
        int idx1=search(stones,stones[index] + k - 1,index,n-1);
        if (k - 1 > 0 && idx1!=-1) {
            first= solve(stones, idx1,k-1);
        }
        bool second=false;
        int idx2=search(stones,stones[index] + k,index,n-1);
        if(idx2!=-1){
            second= solve(stones,idx2,k);
        }
        bool third=false;
        int idx3=search(stones,stones[index] + k+1,index,n-1);
        if(idx3!=-1){
            third= solve(stones,idx3,k+1);
        }
        return first || second || third;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)return false;
        return solve(stones,1,1);
    }
};