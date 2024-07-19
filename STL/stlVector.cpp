#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int>& v)
{
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

vector<int> createVector(vector<int>& v1)
{
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    return v1;
}

// vector数据结构和数组非常相似，也称为单端数组(前端封闭，后端操作)
// vector和普通数组的区别就是vector可以动态扩展空间

// vector的构造函数
void test01()
{
    vector<int> v1; // 默认构造，无参构造
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1); 
    // 通过区间的方式构造
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    // n个element方式构造
    vector<int> v3(10, 100);
    printVector(v3);

    // 拷贝构造
    vector<int> v4 (v3);
    printVector(v4);

    // Hello World
    // 0 1 2 3 4 5 6 7 8 9
    // 0 1 2 3 4 5 6 7 8 9
    // 100 100 100 100 100 100 100 100 100 100
    // 100 100 100 100 100 100 100 100 100 100
}

// 赋值操作
void test02()
{
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    vector<int> v2 = v1; // operator=
    cout << "v2 = ";
    printVector(v2);

    cout << "v3 = ";
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    cout << "v3 = ";
    v3.assign(10,100);
    printVector(v3);


}

// vector容量和大小
void test03()
{
    vector<int> v1;

    // empty() 判断容器是否为空
    cout << true << endl;
    cout << "empty() :" << (v1.empty() ? "true" : "false") << endl;
    v1 = createVector(v1);
    cout << "empty() :" << (v1.empty() ? "true" : "false") << endl;

    // capacity() 容器的容量 >= size()
    cout << "capacity()" << v1.capacity() << endl;
    // size() 容器中元素的个数
    cout << "size()" << v1.size() << endl;

    // resize(int num) 重新制定容易的长度为num， 若容器变长，则以默认值填充新位置；如果容器变短，则会删除超出长度容器末尾的元素
    v1.resize(10);
    printVector(v1);
    v1.resize(6);
    printVector(v1);

    // resize(int num, elem) 重新制定容易的长度为num， 若容器变长，则以elem填充新位置；如果容器变短，则会删除超出长度容器末尾的元素
    v1.resize(10,100);
    printVector(v1);
    v1.resize(6, 100);
    printVector(v1);
    //     Hello World
    // 1
    // empty() :true
    // empty() :false
    // capacity()6
    // size()6
    // 0 1 2 3 4 5 0 0 0 0
    // 0 1 2 3 4 5
    // 0 1 2 3 4 5 100 100 100 100
    // 0 1 2 3 4 5
    // PS D:\CodeRepo

}

// vector的插入和删除
void test04()
{
    vector<int> v1;
    v1 = createVector(v1);
    cout << "v1 capacity" << v1.capacity() << endl; // 6
    cout << "v1 size" << v1.size() << endl; // 6
    printVector(v1); // 0 1 2 3 4 5

    v1.push_back(10);
    cout << "v1 capacity" << v1.capacity() << endl; // 12
    cout << "v1 size" << v1.size() << endl; // 7
    printVector(v1); // 0 1 2 3 4 5 10

    v1.pop_back();
    cout << "v1 capacity" << v1.capacity() << endl; // 12
    cout << "v1 size" << v1.size() << endl; // 6
    printVector(v1); // 0 1 2 3 4 5
    
    v1.insert(v1.begin(), 10);
    cout << "v1 capacity" << v1.capacity() << endl; // 12
    cout << "v1 size" << v1.size() << endl; // 7
    printVector(v1); // 10 0 1 2 3 4 5

    v1.insert(v1.begin(), 2, 101);
    cout << "v1 capacity" << v1.capacity() << endl; // 12
    cout << "v1 size" << v1.size() << endl; // 9
    printVector(v1); // 101 101 10 0 1 2 3 4 5

    v1.erase(v1.begin());
    cout << "v1 capacity" << v1.capacity() << endl; // 12
    cout << "v1 size" << v1.size() << endl; // 8
    printVector(v1);// 101 10 0 1 2 3 4 5

    // v1.erase(v1.begin(), v1.end());
    // cout << "v1 capacity" << v1.capacity() << endl; // 12
    // cout << "v1 size" << v1.size() << endl; // 0
    // printVector(v1); // ""

    v1.clear();
    cout << "v1 capacity" << v1.capacity() << endl; // 12
    cout << "v1 size" << v1.size() << endl; // 0
    printVector(v1); // ""
}

// vector数据存取
void test05()
{
    vector<int> v1;
    v1 = createVector(v1);
    // at(int idx) 返回索引idx所对应的数据
    cout << "at " << v1.at(2) << endl; // 2
    // operator[] 返回索引idx所对应的数据
    cout << "operator = " << v1[3] << endl;// 2
    // front() 返回容器中第一个元素
    cout << "front = " << v1.front() << endl; // 0
    // back() 返回容器中最后一个元素
    cout << "back = " << v1.back() << endl; // 5
}

// vector互换容器
void test06()
{
    vector<int> v1;
    v1 = createVector(v1);
    cout << "v1 = ";
    printVector(v1);
    // swap(vec)  将vec与本身元素互换
    vector<int> v2(1);
    cout << "v2 = ";
    printVector(v2);

    cout << "swap 后" << endl;
    v1.swap(v2);
    cout << "v1 = ";
    printVector(v1);
    cout << "v2 = ";
    printVector(v2);
    // Hello World
    // v1 = 0 1 2 3 4 5
    // v2 = 0
    // swap 后
    // v1 = 0
    // v2 = 0 1 2 3 4 5


    // swap 可以收缩内存空间
    // capacity 不会在size缩小的时候变小。
    vector<int>(v1).swap(v1);
    // vector<int>(v1) 匿名对象 当这样代码执行完后系统马上回收
    // swap(v1) 容器交换
}

// vector预留空间
void test07()
{
    vector<int> v1;
    v1 = createVector(v1);
    // 减少vector在动态扩展容量时的扩展次数
    // reverve(int len) 容器预留len个元素长度，预留位置不初始化，元素不可访问
    v1.reverve(100000);
}

int main(){
    cout << "Hello World" << endl;
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    test07();
}