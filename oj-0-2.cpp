// #pragma once
#include <iostream>
#include <string>
using namespace std;
class Queue
{
private:
    // 使用链表实现，示例
    struct Node
    {
        int val;
        Node *next;
        Node(int x) : val(x), next(nullptr) {} // 实现Node的构造函数
    };
    Node *head; // 队首指针
    Node *tail; // 队尾指针
public:
    Queue();  // 构造函数
    ~Queue(); // 析构函数
    void push(int x);
    void pop();
    void query() const;
    void size() const;
};

// 构造函数
Queue::Queue()
{
    head = nullptr;
    tail = nullptr;
}

// TODO: 实现 Queue 的析构函数
Queue::~Queue()
{
    Node *p = head;
    while (p != nullptr)
    {
        Node *q = p->next;
        delete p;
        p = q;
    }
    head = nullptr;
    tail = nullptr;
}

// 实现 push 操作
void Queue::push(int x)
{
    Node *p = new Node(x);
    if (head == nullptr)
    {
        head = p;
        tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
}

// TODO: 实现 pop 操作
void Queue::pop()
{
    if (head != nullptr)
    {
        Node *p = head;
        head = head->next;
        delete p;
    }
    else
    {
        cout << "ERR_CANNOT_POP" << endl;
    }
}

// TODO: 实现 query 操作
void Queue::query() const
{
    Node *p = head;
    if (p != nullptr)
    {
        cout << p->val << endl;
    }
    else
    {
        cout << "ERR_CANNOT_QUERY" << endl;
    }
}

// TODO: 实现 size 操作
void Queue::size() const
{
    int cnt = 0;
    Node *p = head;
    while (p != nullptr)
    {
        cnt++;
        p = p->next;
    }
    cout << cnt << endl;
}

// 可以使用这个main函数在本地进行调试，但提交时请把这段内容注释
int main()
{
    int T, m;
    std::cin >> T;
    while (T--)
    {
        Queue q;
        std::cin >> m;
        while (m--)
        {
            std::string op;
            std::cin >> op;
            if (op == "push")
            {
                int x;
                std::cin >> x;
                q.push(x);
            }
            else if (op == "pop")
            {
                q.pop();
            }
            else if (op == "query")
            {
                q.query();
            }
            else if (op == "size")
            {
                q.size();
            }
        }
        std::cout << std::endl;
    }
    return 0;
}