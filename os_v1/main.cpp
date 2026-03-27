#include "stack.h"
#include <iostream>
#include <thread>
using namespace std;

// 全局栈
ThreadSafeStack st;

// 测试函数：压入 3 个数
void testPush(int a, int b, int c) {
    st.Push(a);
    st.Push(b);
    st.Push(c);
}

// ======================
// 1. 单线程测试
// ======================
void testSingleThread() {
    cout << "\n=== Single Thread Test ===" << endl;
    st.Clear(); // 清空栈

    testPush(10, 20, 30);
    st.Print();
    cout << "Size: " << st.Size() << endl;
}

// ======================
// 2. 多线程测试
// ======================
void testMultiThread() {
    cout << "\n=== Multi Thread Test ===" << endl;
    st.Clear(); // 清空栈

    // 线程1压 1,2,3
    thread t1(testPush, 1, 2, 3);
    // 线程2压 100,200,300
    thread t2(testPush, 100, 200, 300);

    t1.join();
    t2.join();

    st.Print();
    cout << "Size: " << st.Size() << endl;
}

// ======================
// 主函数
// ======================
int main() {
    cout << "=== Program Start ===" << endl;

    // 先跑单线程
    testSingleThread();

    // 再跑多线程
    testMultiThread();

    cout << "\n=== All Test Success ===" << endl;
    return 0;
}