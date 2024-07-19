#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Queue是一种先进先出的数据结构，一端进数据，一端出数据，也不允许遍历
queue<int> createQueue()
{
    queue<int> q1;
    for (int i = 0; i < 5; i++)
    {
        q1.push(i);
    }
    return q1;
}
void test01()
{
    queue<int> q1 = createQueue();
    queue<int> q2 = q1;
    queue<int> q3(q1);

    cout << "q1 size = " << q1.size() << endl;
    cout << "q1 front = " << q1.front() << endl;
    cout << "q1 back = " << q1.back() << endl;

    q1.pop();
    cout << "q1 size = " << q1.size() << endl;
    q1.push(100);
    cout << "q1 front = " << q1.front() << endl;
    cout << "q1 back = " << q1.back() << endl;
    // q1 size = 5  
    // q1 front = 0 
    // q1 back = 4  
    // q1 size = 4  
    // q1 front = 1 
    // q1 back = 100
}
int main()
{

    test01();
    // test02()
    // test03()
}