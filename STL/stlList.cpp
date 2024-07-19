#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

// 链表
// 链表在物理存储中是非连续的内存空间，它的逻辑顺序是靠链表的指针域控制的。
// STL中的链表是双向链表

// 优点： 
// 1.可以对任意位置进行快速插入和删除元素;修改指针即可
// 2. 采用动态存储分配， 不会造成内存浪费和溢出；
// 缺点： 
// 1.遍历速度没有数组快;
// 2.占用空间比数组大；

// 重要性质：插入和删除不会造成迭代器失效

void printList(const list<int>& l)
{
    for (list<int>::const_iterator i = l.begin(); i != l.end(); i++)
    {
        cout << *i  << " ";
    }
    cout << endl;
    
}

list<int> createList()
{
    list<int> l;
    for (int i = 0; i < 6; i++)
    {
        l.push_back(i);
    }
    return l;
}

// 构造函数
void test01()
{
    list<int> l1 = createList();
    printList(l1);
    list<int> l2(l1.begin(), l1.end());
    printList(l2); 
    list<int> l3(10,100);
    printList(l3);
    list<int> l4(l1);
    printList(l4);
    // 0 1 2 3 4 5 
    // 0 1 2 3 4 5 
    // 100 100 100 100 100 100 100 100 100 100 
    // 0 1 2 3 4 5 
}

// 赋值和交换
void test02()
{
    list<int> l1 = createList();
    list<int> l2;
    l2.assign(l1.begin(), l1.end());
    printList(l2);
    list<int> l3;
    l3.assign(10, 101);
    printList(l3);
    list<int> l4 = l1;
    printList(l4);
    
    l1.swap(l3);
    printList(l1);
    printList(l3);
    // 0 1 2 3 4 5 
    // 101 101 101 101 101 101 101 101 101 101
    // 0 1 2 3 4 5
    // 101 101 101 101 101 101 101 101 101 101
    // 0 1 2 3 4 5
}

// 大小操作
void test03()
{
    list<int> l1 = createList();
    cout << "size = " << l1.size() << endl;
    l1.resize(10);
    printList(l1);
    l1.resize(20,101);
    printList(l1);
    // size = 6
    // 0 1 2 3 4 5 0 0 0 0
    // 0 1 2 3 4 5 0 0 0 0 101 101 101 101 101 101 101 101 101 101
}

// 插入和删除
void test04()
{
    list<int> l1 = createList();
    l1.push_back(101);
    printList(l1);
    l1.pop_back();
    printList(l1);
    l1.push_front(111);
    printList(l1);
    l1.pop_front();
    printList(l1);
    list<int>:: iterator pos = l1.begin();
    pos++;
    cout << *pos << endl;
    l1.insert(pos, 1000);
    printList(l1);
    l1.insert(pos, 3, 1001);
    printList(l1);

    list<int> l2;
    l2.insert(l2.begin(), l1.begin(), l1.end());
    printList(l2);
    l2.clear();
    printList(l2);

    l1.erase(pos);
    printList(l1);
    l1.remove(3);
    printList(l1);
    l1.erase(l1.begin(), l1.end());
    printList(l1);
    // 0 1 2 3 4 5 101 
    // 0 1 2 3 4 5
    // 111 0 1 2 3 4 5
    // 0 1 2 3 4 5
    // 1
    // 0 1000 1 2 3 4 5
    // 0 1000 1001 1001 1001 1 2 3 4 5
    // 0 1000 1001 1001 1001 1 2 3 4 5
    // 
    // 0 1000 1001 1001 1001 2 3 4 5
    // 0 1000 1001 1001 1001 2 4 5
    // 
    
}

// 数据存取
void test05()
{
    list<int> l1 = createList();
    cout << "front = " << l1.front() << endl; // 0
    cout << "back = " << l1.back() << endl; // 5
}

// 排序 & 反转
void test06()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(2);
    l1.push_back(9);
    l1.push_back(4);
    l1.push_back(5);
    l1.sort();// sort里可以加排序规则，是一个函数
    printList(l1);
    l1.reverse();
    printList(l1);
    // 2 4 5 9 10 
    // 10 9 5 4 2
    // sort(l1.begin(), l1.end());
}

int main(){

    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test06();
}