class MinStack {
public:
    vector<pair<int,int>> v;
    MinStack() {
    }
    
    void push(int val) {
        //stack  is  empty
        if(v.empty()){
            v.push_back({val,val});
            return;
        }
        // More  than 1 Element
        auto top = v.back();
        int min_till_now = min(val, top.second);
        v.push_back({val, min_till_now});
    }
    //A, B. C,D
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */