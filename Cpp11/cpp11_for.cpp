#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 语法格式
// for(declaration : range_expression)
//  declaration: 表示此处要提供一个变量， 该变量的类型为range_expression的元素类型，可用auto关键字表示，
//  range_expression: 表示一个范围表达式，可以是数组、容器、迭代器等。

int main(){
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    for(auto i : v){
        cout << i << " ";
    }
    
}