#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// decltype 用于对表达式的类型进行推导



void* myFunc(int i)
{
    cout << "myFunc(int)" << endl;
}
int main(){
    int a = 1;
    int& b = a;
    // decltype(b) c = 2;
    // int& d = 2;
    int&& e = 2;
    cout << b << endl;
    // cout << c << endl;

    cout << "decltype(myFunc) = " << typeid(decltype(myFunc)).name() << endl;
    cout << "decltype(myFunc(0)) = " << typeid(decltype(myFunc(0))).name() << endl;

    
}