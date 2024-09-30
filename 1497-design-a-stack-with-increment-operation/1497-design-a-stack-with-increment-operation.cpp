class CustomStack {
public:
    int top=-1;
    int size;
    int a[1000];
    CustomStack(int maxSize) {
        
        size=maxSize;
        
    }
    
    void push(int x) {
        top++;
    
        if(top==size){
            top--;
            return;
        }
        a[top]=x;
    }
    
    int pop() {
        if(top==-1) return -1;
        int x=a[top];
        top--;
        return x;
    }
    
    void increment(int k, int val) {
        for(int i=0; (i<k && i<=top); i++){
            a[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */