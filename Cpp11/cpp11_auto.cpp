#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// auto 关键字的使用
// 1. auto 必须初始化
// 2. auto 不能在函数参数中使用auto
// 3. auto 不能定义数组
int main(){
    // vector<int> v{1,2,3,4,5,6,7,8,9,10};
    // for(auto i : v){
    //     cout << *&i << " ";
    // }
    // cout << endl;
    // for(auto &i : v){
    //     i *= 2;
    //     cout << "&i = " << i << endl;
    // }
    // for(auto i : v){
    //     cout << i << " ";
    // }
    // cout << endl;
    // return 0;

   int in = 100;
   cout << typeid(in).name() << endl;

    auto i = 10;
    // 打印出i的类型
    cout << typeid(i).name() << endl;
    auto d = 3.14;
    cout << typeid(d).name() << endl;
    auto p = &i;
    cout << typeid(p).name() << endl;
    vector<int>::iterator it;
    cout << typeid(it).name() << endl;
    cout << &it << endl;
    auto p1 = it;
    cout << typeid(p1).name() << endl;
    cout << &p << endl;

    auto str = "hello world";
    cout << typeid(str).name() << endl;
    cout << str << endl;
    
    
    cout << "-----------------" << endl;

    vector<int> v1 {1,2,3,4,5};
    for (vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    for(auto i : v1){
        cout << i << " ";
    }

    return 0;
}