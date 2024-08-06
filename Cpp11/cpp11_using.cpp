#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using db = double;

typedef struct{
    db x, y;
}point;

typeof void(function*)(int, int); // c99, 函数指针类型定义

using function  = void(*)(int, int); // c++11, 函数指针类型定义

// 重定义std::map
typedef std::map<int, int> map_int;
using map_int = map<int, int>;

int main(){
}