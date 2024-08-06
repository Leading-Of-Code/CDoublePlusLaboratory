#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
using namespace std;

void doit()
{
    cout << "Thread!" << endl;
}
void test01()
{
    thread a([]
             { cout << "Hello, " << endl; }),
        b(doit);
    a.join();
    b.join();
}

// -------------
void countnumber(int id, unsigned int n)
{
    for (unsigned int i = 0; i <= n; i++)
    {
        cout << "Thread " << id << " finished!" << endl;
    }
}

void test02()
{
    thread th[10];
    for (int i = 0; i < 10; i++)
    {
        th[i] = thread(countnumber, i, 100000000);
    }
    for (int i = 0; i < 10; i++)
    {
        th[i].join();
    }
}
void test03()
{
}
int main()
{

    // test01();
    test02();
    // test03();
}