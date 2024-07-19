#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
// deque 双端队列，双端数组，可以对头端进行插入删除
// deque 和 vector的区别
// 1. vector对头部的插入删除效率低，数据量越大，效率越低
// 2. deque相对而言， 对头端的插入删除比vector快
// 3. vector访问元素的速度比deque快， 这和两者的内部实现有关


// deque内部工作原理
// 内部维护着一个中控器，中控器中有每一段缓冲区的地址，往缓冲区前端插入数据超范围时，会再申请一段缓冲区记录数据
// 如果向后端插入数据时超范围时，会再申请一段缓冲区插向中控器的后端，这样就使得deque像一段连续的内存空间

void printDeque(const deque<int>& d)
{
    // 遍历deque
    for (deque<int>::const_iterator i = d.begin(); i != d.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}
deque<int> createDeque(deque<int>& d)
{
    for (int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    return d;
}

deque<int> createDeque()
{
    deque<int> d;
    for (int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    return d;
}

// deque容器的构造函数
void test01()
{
    deque<int> d1;
    printDeque(d1);
    createDeque(d1);
    printDeque(d1);

    deque<int> d2 = createDeque();
    printDeque(d2);

    deque<int> d3(d2);
    printDeque(d3);
    deque<int> d4(10, 100);
    printDeque(d4);
    deque<int> d5(d2.begin(), d2.end());
    printDeque(d5);
}

// deque赋值操作
void test02(){
   deque<int> d1 = createDeque();
   
   deque<int> d2 = d1;
   printDeque(d2);
   
   deque<int> d3;
   d3.assign(d1.begin(), d1.end());
   printDeque(d3);

   deque<int> d4;
   d4.assign(10, 100);
   printDeque(d4);
   // Hello World
   // 0 1 2 3 4 5 6 7 8 9
   // 0 1 2 3 4 5 6 7 8 9
   // 100 100 100 100 100 100 100 100 100 100
}

// deque 大小操作
void test03()
{
   deque<int> d1 = createDeque();
   cout << "empty = " << (d1.empty() ? "true" : "false") << endl;
   cout << "size = " << d1.size() << endl;
   d1.resize(15);
   printDeque(d1);
   d1.resize(20, 100);
   printDeque(d1);
   // Hello World
   // empty = false
   // size = 10
   // 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0
   // 0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 100 100 100 100 100
}

// deque 插入和删除
void test04()
{
    deque<int> d1 = createDeque();
    // 插入
    d1.push_back(1000);
    printDeque(d1);
    d1.push_front(100);
    printDeque(d1);
    // 删除
    d1.pop_back();
    printDeque(d1);
    d1.pop_front();
    printDeque(d1);

    // 指定位置操作
    deque<int> d2;
    d2.insert(d2.begin(), 101);
    printDeque(d2);
    d2.insert(d2.begin(), 2, 100);
    printDeque(d2);

    d2.insert(d2.begin(), d2.begin(),d2.end());
    printDeque(d2);

    d1.clear();
    printDeque(d1);

    printDeque(d2);

    d2.erase(d2.begin());
    printDeque(d2);
    d2.erase(d2.begin(), d2.end());
    printDeque(d2);
    // Hello World
    // 0 1 2 3 4 5 6 7 8 9 1000
    // 100 0 1 2 3 4 5 6 7 8 9 1000
    // 100 0 1 2 3 4 5 6 7 8 9
    // 0 1 2 3 4 5 6 7 8 9
    // 101
    // 100 100 101
    // 100 100 101 100 100 101
    // 
    // 100 100 101 100 100 101
    // 100 101 100 100 101
    // 

    deque<int> d3 = createDeque();
    deque<int>::iterator i3 = d3.begin();
    i3++;
    cout << *i3 << endl; // 1
}


// deque 数据存取
void test05()
{
    deque<int> d1 = createDeque();
    cout << "operator[] =  " << d1[1] << endl; // 1
    cout << "at = " << d1.at(2) << endl; // 2
    cout << "front = " << d1.front() << endl; // 0
    cout << "end = " << d1.back() << endl; // 9
}

// deque 排序
void test06()
{
    deque<int> d1;
    d1.push_back(9);
    d1.push_back(3);
    d1.push_back(2);
    d1.push_back(4);
    d1.push_back(8);
    printDeque(d1);
    // 对于随机访问的迭代器都可以利用algorithm.sort进行排序；比如vector
    sort(d1.begin(), d1.end());
    printDeque(d1);
    // 9 3 2 4 8
    // 2 3 4 8 9
}

int main(){
    cout << "Hello World" << endl;
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test06();
}