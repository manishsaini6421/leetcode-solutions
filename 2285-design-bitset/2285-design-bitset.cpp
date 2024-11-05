class Bitset {
public:
    string bits="";
    string rev="";
    int count1=0;
    int flipp=0;
    int n;

    Bitset(int size) {
        for(int i=0; i<size; i++){
            bits+='0';
            rev+='1';
        }
        n=size;
    }
    
    void fix(int idx) {
        if(flipp%2==0){
            if(bits[idx]=='0')count1++;
                bits[idx]='1';
                rev[idx]='0';
            
        }
        else{
            if(bits[idx]=='1') count1--;
                bits[idx]='0';
                rev[idx]='1';
            
        }
    }
    
    void unfix(int idx) {
        if(flipp%2==0){
            if(bits[idx]=='1') count1--;
                bits[idx]='0';
                rev[idx]='1';
            
        }
        else{
            if(bits[idx]=='0') count1++;
                bits[idx]='1';
                rev[idx]='0';
            
        }
    }
    
    void flip() {
        flipp++;
    }
    
    bool all() {
        int temp=(flipp%2)?(n-count1):count1;
        return n==temp;
    }
    
    bool one() {
        int temp=(flipp%2)?(n-count1):count1;
        return temp>0;
        
    }
    
    int count() {
        if(flipp%2==0) return count1;
        else return n-count1;
    }
    
    string toString() {
        if(flipp%2==0)return bits;
        else return rev;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */