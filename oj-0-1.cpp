#include <iostream>
#include <stack>
using namespace std;

class MonotonicStack {
 private:
  stack<int> s;

 public:
  int size();
  void pop();
  int top();
  int push(int element);
  int function(int const* arr, int n);
};
/*
其中成员变量s是stl中的stack类型的变量，是已经封装实现好的数据结构。
你可以使用它，使用s.size()将返回s内元素数量，使用s.push(int)将一个int型值入栈s，
s.top()返回s的栈顶元素，而s.pop()将弹出s的栈顶元素。
提示：在使用stack s时，进行s.pop()和s.top()前，应当检查s内是否有元素，否则容易引发段错误。

push的返回值在用例中不会进行测试（你可以返回任何值），这个返回值是一个保留接口：
你可以思考如何利用这个返回值巧妙地解决Part-2的问题 :)

需要你补充的内容已在MonotonicStack.cpp中用TODO标出！
需要你补充的内容已在MonotonicStack.cpp中用TODO标出！
需要你补充的内容已在MonotonicStack.cpp中用TODO标出！
*/
int MonotonicStack::size() {
  // TODO
  return s.size();
}

void MonotonicStack::pop() {
  // TODO
  if (!s.empty()) {
    s.pop();
  }
}

int MonotonicStack::top() {
  // TODO
  if (!s.empty()) {
    return s.top();
  }
  return -1;
}

int MonotonicStack::push(int element) {
  // 寻找栈中第一个小于当前元素的元素
  while (!s.empty() && s.top() > element) {
    s.pop();
  }

  // 计算价值
  int value;
  if (s.empty()) {
    value = element;  // 如果没有更小的元素，价值就是元素本身
  } else {
    value = element - s.top();  // 否则是元素与更小元素的差值
  }

  s.push(element);
  return value;  // 返回价值
}

int MonotonicStack::function(int const* arr, int n) {
  // 清空栈，确保开始时栈是空的
  while (!s.empty()) {
    s.pop();
  }

  int sum = 0;

  // 从右向左遍历数组
  for (int i = n - 1; i >= 0; i--) {
    sum += push(arr[i]);  // 直接使用push返回的价值
  }

  return sum;
}

int main() {
  MonotonicStack* ms = new MonotonicStack;
  int arr[]          = {8, 4, 6, 2, 3};
  cout << ms->function(arr, 5) << endl;
  delete ms;
}
