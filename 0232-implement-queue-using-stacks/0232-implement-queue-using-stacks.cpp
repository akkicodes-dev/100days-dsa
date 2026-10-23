class MyQueue {
public:
    stack<int> s1, s2; // why  wee need to chnage  the  order of the  elements
    MyQueue() {
        
    }
    
    void push(int x) {
        //s1 ke saree elements s2 me daloo
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        //naya element sabse nechhe (s1 maine pehle)
        s1.push(x);

        //wapas s2 se s1main dalo
         while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int front = s1.top();
        s1.pop();
        return front;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */