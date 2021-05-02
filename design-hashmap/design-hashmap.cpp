class MyHashMap {
        vector<pair<int,int>> m;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        if(get(key) == -1){
            m.push_back(make_pair(key,value));
        } else {
            for(int i = 0; i < m.size(); i++){
                if(m[i].first == key){
                    // update the value
                    m[i] = make_pair(key,value);
                }
            }
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        // let's check if the key exists or not
        for(pair<int,int> & p: m){
            if(p.first == key){
                return p.second;
            }
        }
        // key doesn't exist
        return -1;
        
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        for(int i = 0; i < m.size(); i++){
            if(m[i].first == key){
                m.erase(m.begin() + i);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */