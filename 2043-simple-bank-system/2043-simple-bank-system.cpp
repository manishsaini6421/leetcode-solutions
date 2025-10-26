class Bank {
public:
    vector<long long> balances;
    
    Bank(vector<long long>& balance) {
       
        balances=balance;
    }
    bool valid(int account){
        return account>=1 && account<=balances.size();
    }
    bool transfer(int account1, int account2, long long money) {
        if(valid(account1) && valid(account2) && money<=balances[account1-1]){
            balances[account1-1]-=money;
            balances[account2-1]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(valid(account)){
            balances[account-1]+=money;
        return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(valid(account) && money<=balances[account-1]){
            balances[account-1]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */