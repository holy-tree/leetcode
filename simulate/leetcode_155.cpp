class MinStack {
public:
    stack<int> st;
    stack<int> ass_st;
    MinStack() {

    }
    
    void push(int val) {
        if(st.empty())
            ass_st.push(val);
        else
            ass_st.push(min(ass_st.top(), val));
        st.push(val);
    }
    
    void pop() {
        st.pop();
        ass_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ass_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
