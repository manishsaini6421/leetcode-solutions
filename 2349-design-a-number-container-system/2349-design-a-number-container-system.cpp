class NumberContainers {
public:
    unordered_map<int,set<int>> map1;
    unordered_map<int,int> map2;
    NumberContainers() {

    }
    
    void change(int index, int number) {
        if(map2.find(index)!=map2.end()){
            map1[map2[index]].erase(index);
            if(map1[map2[index]].size()==0)map1.erase(map2[index]);
        }
        map1[number].insert(index);
        map2[index]=number;
    }
    
    int find(int number) {
       if(map1.find(number)!=map1.end())return *map1[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */