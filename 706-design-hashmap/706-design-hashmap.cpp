class MyHashMap {
public:
    int *arr;
    int bucket;
    MyHashMap() {
        bucket = 1000000;
        arr = new int[bucket];
        fill_n(arr, 1000000, -1);
    }
    
    int hash(int key) {
        return key % bucket;
    }
    
    void put(int key, int value) {
        int i = hash(key);
        arr[i] = value;
    }
    
    int get(int key) {
        int i = hash(key);
        return arr[i];
    }
    
    void remove(int key) {
        int i = hash(key);
        arr[i] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */