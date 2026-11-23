class ProductOfNumbers {
public:
    vector<int> pref;
    int size;
    ProductOfNumbers() {
        pref.emplace_back(1);
        size=1;
    }
    
    void add(int num) {
        if(num!=0) { 
            pref.emplace_back(num*pref[size-1]);
            size++;
        } else {
            pref={1};
            size=1;
        }
    }
    
    int getProduct(int k) {
        if(size>k) {
            return pref[size-1]/pref[size-k-1];
        } else {
            return 0;
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */