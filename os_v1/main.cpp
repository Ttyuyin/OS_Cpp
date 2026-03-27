#include "stack.h"
#include <iostream>
#include <thread>
using namespace std;

void thread1(ThreadSafeStack &st) {
    st.Push(10);
    st.Push(20);
    st.Push(30);
    cout << "[thread 1] done" << endl;
}

void thread2(ThreadSafeStack &st) {
    st.Push(100);
    st.Push(200);
    cout << "[thread 2] done" << endl;
}

int main() {
    // 🔥 全程英文，永不乱码
    cout << "=== main thread start ===" << endl;

    ThreadSafeStack st;

    thread t1(thread1, ref(st));
    thread t2(thread2, ref(st));

    t1.join();
    t2.join();

    cout << endl;
    cout << "final stack:" << endl;
    st.Print();

    cout << "stack size: " << st.Size() << endl;
    cout << "=== program run success ===" << endl;

    return 0;
}