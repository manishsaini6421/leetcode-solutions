class NumberContainers {
public:
    unordered_map<int,set<int>> map;
    vector<int> v;
    NumberContainers() {

    }
    
    void change(int index, int number) {
        if(index>=v.size())v.resize(index+1);
        if(v[index]){
            map[v[index]].erase(index);
            if(map[v[index]].size()==0)map.erase(v[index]);
        }
        map[number].insert(index);
        v[index]=number;
    }
    
    int find(int number) {
       if(map.find(number)!=map.end())return *map[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */