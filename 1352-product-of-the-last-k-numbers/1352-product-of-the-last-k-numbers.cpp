class ProductOfNumbers {
public:
    vector<int> pref;
    ProductOfNumbers() {
        pref.emplace_back(1);
    }
    
    void add(int num) {
        if(num!=0) { 
            pref.emplace_back(num*pref.back());
        } else {
            pref.erase(pref.begin()+1,pref.end());
        }
    }
    
    int getProduct(int k) {
        int n=pref.size();
        if(n>k) {
            return pref.back()/pref[n-k-1];
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