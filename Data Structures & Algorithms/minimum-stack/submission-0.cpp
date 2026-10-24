using LL = long long;
class MinStack {
    stack<LL>st;
    LL mini;
public:
    MinStack() { }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            mini = value;
        }
        else if(mini <= value){
            st.push(value);
        }
        else{
            st.push(2LL * value - mini);
            mini = value;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        LL x = st.top();
        st.pop();
        if(x < mini){
            mini = 2LL * mini - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;

        LL x = st.top();
        if(x < mini) return static_cast<int>(mini);
        else return static_cast<int>(x);
    }
    
    int getMin() {
        if(st.empty()) return -1;
        else return static_cast<int>(mini);
    }
};