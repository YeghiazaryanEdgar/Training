#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Stack {

public:
    void push(T elem);

    void pop();

    void showQ();

    int size();

    int empty();

private:
    void reverse() {
        if(q.empty()) return;
        int num = q.front();
        q.pop();
        reverse();
        q.push(num);
    }
    queue<T> q;
};

template <typename T>
void Stack<T>::push(T elem) {
    q.push(elem);
}

template <typename T>
void Stack<T>::pop() {
    reverse();
    q.pop();
    reverse();
}

template <typename T>
void Stack<T>::showQ() {
    while(!q.empty()) {
        cout<< q.front() << ", ";
        q.pop();
    }
}

template <typename T>
int Stack<T>::size() {
    return q.size();
}

template <typename T>
int Stack<T>::empty() {
    return q.empty();
}

int main() {
    Stack<int> st;
    st.push(118);
    st.push(225);
    st.push(888);
    st.push(22);
    st.push(8);
    st.push(2);
    st.push(66);
    st.push(11);


    //st.pop();
    //st.push(223);

    st.showQ();




    return 0;
}

