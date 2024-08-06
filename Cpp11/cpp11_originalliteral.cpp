#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    string str = R"("D\work\temp.txt")";
    cout << str << endl;
    str = R"abc("D\work\temp.txt")abc";
    cout << str << endl;
}