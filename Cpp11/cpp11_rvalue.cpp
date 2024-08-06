#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

// 右值的实际应用
// 1. 移动语义: 将临时对象的空间给出接收者，公用一段内存空间

class String{
public:
    String(const char* str = ""){
        cout << "String(const char* str)" << endl;
        if (str == nullptr){
            m_data = new char[1];
            m_data[0] = '\0';
        }
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    }
    String(const String& s) : m_data(new char[strlen(s.m_data) + 1])
    {
        cout << "String(const String& s)" << endl;
        strcpy(m_data, s.m_data);
    }
    // 移动构造函数
    String(String&& s) : m_data(s.m_data)
    {
        cout << "String(String&& s)" << endl;
        s.m_data = nullptr;
    }
    // move函数强制把左值转化成右值引用
    // 为了保证移动语义的传递，程序员在编辑移动构造函数的时候，最好用std::move()转移拥有资源的成员为右值
    String(String&& s) : m_data(std::move(s.m_data))
    {
        cout << "String(String&& s)" << endl;
        s.m_data = nullptr;
    }
    String& operator=(const String& s)
    {
        cout << "String& operator=(const String& s)" << endl;
        if (this != &s)         
        {
            char* pTemp = new char[strlen(s.m_data) + 1];
            strcpy(pTemp, s.m_data);
            delete[] m_data;
            m_data = pTemp;
        }
        return *this;
    }
    ~String()
    {
        cout << "~String()" << endl;
        if (m_data)
        {
            delete[] m_data;
        }
    }
    friend ostream &operator << (ostream &out, const String& t)
    {
        out << t.m_data;
        return out;
    }
private:
    char* m_data;
};

String getString(const char* str    ){
    String tmp(str);
    return tmp;
}

int main(){
    String s(getString("hello"));

    
}