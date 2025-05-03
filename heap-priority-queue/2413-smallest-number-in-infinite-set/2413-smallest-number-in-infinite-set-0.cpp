class SmallestInfiniteSet {
public:
    int l;
    set<int>st;
    SmallestInfiniteSet() {
       l = 1; 
    }

    // [1 , inf]

    // [2 , inf]

    // [1 , inf]

    // [3 , inf]

    // [4 , inf]

    // [1 , 4 , inf]
    
    int popSmallest() {
        int to_return = -1;
        if(!st.empty() and *st.begin() < l){
            to_return = *st.begin();
            st.erase(st.begin());
        }
        else{
            to_return = l;
            ++l;
        }
        return to_return;
    }
    
    void addBack(int num) {
        if(num < l) st.insert(num); 
    }
    // l = 5 , st = {}
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */