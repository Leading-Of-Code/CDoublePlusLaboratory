#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// stack是一种先进后厨的数据结构，只有一个出口
// 只有栈顶的数据可以被外界使用，因此栈不允许有遍历行为

stack<int> createStack()
{
    stack<int> s1;
    for (int i = 0; i < 5; i++)
    {
        s1.push(i);
    }
    return s1;
}

void test01()
{
   stack<int> s1 = createStack();
   stack<int> s2 = s1;
   stack<int> s3(s1);

   cout << "s1 size" << s1.size() << endl;
   s1.pop();
   cout << "s1 size" << s1.size() << endl;
   cout << "s1 top" << s1.top() << endl;

}

int main(){
    cout << "Hello World" << endl;
    test01();
}