#include "stack.h"
#include <iostream>

using namespace std;

// 构造函数
ThreadSafeStack::ThreadSafeStack() {
    top = nullptr;
    count = 0;
}

// 析构函数
ThreadSafeStack::~ThreadSafeStack() {
    Clear();
}

// 入栈
void ThreadSafeStack::Push(int x) {
    lock_guard<mutex> lock(mtx);

    Node* node = new Node;
    node->data = x;
    node->next = top;
    top = node;
    count++;
}

// 出栈
bool ThreadSafeStack::Pop(int &x) {
    lock_guard<mutex> lock(mtx);

    if (top == nullptr) {
        return false;
    }

    Node* temp = top;
    x = temp->data;
    top = top->next;
    delete temp;
    count--;

    return true;
}

// 查找
bool ThreadSafeStack::Find(int x) {
    lock_guard<mutex> lock(mtx);

    Node* cur = top;
    while (cur != nullptr) {
        if (cur->data == x) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

// 打印
void ThreadSafeStack::Print() {
    lock_guard<mutex> lock(mtx);

    Node* cur = top;
    cout << "Stack: ";
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

// 清空
void ThreadSafeStack::Clear() {
    lock_guard<mutex> lock(mtx);

    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    count = 0;
}

// 返回大小
int ThreadSafeStack::Size() {
    lock_guard<mutex> lock(mtx);
    return count;
}