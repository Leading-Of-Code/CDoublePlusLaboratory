#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(int value)
{
    cout << value <<endl;
}
void test01(){
    // 创建Vector容器
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();
    while(itBegin != itEnd){
        cout << *itBegin << endl;
        itBegin++;
    }

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << endl;
    }

    for_each(v.begin(), v.end(), Print);
}

int main(){
    cout << "Hello World" << endl;
    test01();



    system("pause");
}

//sudo apt-get install git-core bison flex gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4 openjdk-8-jdk
//找不到<span>  libstdc++-10-dev