#ifndef STACK_H
#define STACK_H

#include <mutex>

/// 栈结点，数据和指针
struct Node {
    int data;
    Node* next;
};

//线程安全栈
class ThreadSafeStack {
private:
    Node* top;//栈顶指针
    int count;//当前元素个数
    std::mutex mtx;//互斥信号量

public:
    ThreadSafeStack();//构造函数，初始化栈
    ~ThreadSafeStack();//析构函数，释放栈内存

    void Push(int x);//入栈
    bool Pop(int &x);//出栈，返回是否成功
    bool Find(int x);//查找元素是否存在
    void Print();//打印栈内元素
    void Clear();//清空栈
    int Size();//返回栈内元素个数
};

#endif