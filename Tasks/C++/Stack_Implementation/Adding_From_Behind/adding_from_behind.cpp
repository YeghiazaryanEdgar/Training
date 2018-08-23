#include <iostream>
#include <queue>
using namespace std;

template <class T>
class Stack {
public:

    void push(T t) {
        q.push(t);
    }

    void pop() {

        int initalSize = q.size();
        
        if(!initalSize)
            return;

        int i = 0;

        while(++i < initalSize) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }

    void showQ() {
        while(q.size()) {
            cout<< q.front() << " ";
            q.pop();
        }
    }

private:
    queue<T> q;
};

int main() {

    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);

//    st.showQ();
    st.pop();
    st.showQ();
//    st.pop();
//    st.pop();
//    st.showQ();




    return 0;
}