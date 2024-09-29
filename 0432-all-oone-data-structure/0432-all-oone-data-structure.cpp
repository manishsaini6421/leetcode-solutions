class AllOne {
public:
   string s1,s2;
   int count1,count2;
    unordered_map<string, int> map;
    AllOne() {
        count1=0;
        count2=INT_MAX;
    }
    
    void inc(string key) {
        map[key]++;
        if(key==s2){
            count2=INT_MAX;
            for(auto &pair:map){
                if(count2>pair.second){
                    count2=pair.second;
                    s2=pair.first;
                }
            }
        }
       if(count1<map[key]){
        count1=map[key];
        s1=key;
       }
       if(count2>map[key]){
        count2=map[key];
        s2=key;
       }

    }
    
    void dec(string key) {
        map[key]--;
        if(key==s1){
            count1=0;
            for(auto& pair:map){
                if(count1<pair.second){
                    count1=pair.second;
                    s1=pair.first;
                }
            }
        }
        if(map[key]==0 && key==s2){
            auto iter = map.find(key);
            map.erase(iter);
          
        
            count2=INT_MAX;
            for(auto& pair:map){
                if(count2>pair.second){
                    count2=pair.second;
                    s2=pair.first;
                }
            }
        }
        else if(map[key]==0){
             auto iter = map.find(key);
            map.erase(iter);
        }
        else if(map[key]<count2){
            s2=key;
            count2=map[key];
        }

    }
    
    string getMaxKey() {
        return s1;
    }
    
    string getMinKey() {
        return s2;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */