#include <iostream>
#include <queue>
using namespace std;

template <class T>
class Stack {
public:

    void push(T t) {
        q1.push(t);
    }

    void pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        if(!q1.size()) return;

        q1.pop();
        while(q2.size()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void showQ1() {
        while (q1.size()){
            cout<< q1.front();
            q1.pop();
        }
    }

private:
    queue<T> q1;
    queue<T> q2;
};

int main() {

    Stack<int> st;
    st.push(10);
    st.push(23);
    st.push(1);
    st.push(3);
    st.push(67);
    st.push(33);

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
//    st.pop();
//    st.pop();

    st.showQ1();









    return 0;
}