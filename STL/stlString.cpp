#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <string>

void Print(int value)
{
    cout << value <<endl;
}

// 指针实验
void test00()
{
    int a = 10;
    int* ap;
    ap = &a;
    cout << "ap = " << ap << endl;
    cout << "a的地址 = " << &a << endl;
    cout << "a的地址再解址 = " << *&a << endl;
    cout << "ap所映射的值为： " << *ap << endl;
    cout << "ap地址： " << &ap << endl;
    cout << "ap地址再解址： " << &ap << endl;


    char b = 'a';
    char* bp = &b;
    cout << "char* 占用内存大小 = " << sizeof(char*) << endl;
    cout << "char* 占用内存大小 = " << sizeof(bp) << endl;
    cout << "b 占用内存大小 = " << sizeof(*bp) << endl;
    cout << "&bp 占用内存大小 = " << sizeof(&bp) << endl;
    cout << "&b 占用内存大小 = " << sizeof(&b) << endl;
    // output
    // ap = 0x5ffe6c
    // a的地址 = 0x5ffe6c
    // a的地址再解址 = 10
    // ap所映射的值为： 10
    // ap地址： 0x5ffe60
    // ap地址再解址： 0x5ffe60
}

// string 的构造
void test01()
{
    string s1;// 默认构造
    const char* str = "Hello World";
    string s2(str);
    cout << s2 << endl;
    string s3(s2);
    string s4(10,'a');
    cout << s4 << endl;
    string s5('a','b');
    cout << s5 << endl;
    // Hello World
    // Hello World
    // aaaaaaaaaa
    // bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
}
// string 的赋值操作
void test02()
{
    string str1;
    str1 = "Hello World";
    cout << "str1 = " << str1 << endl;
    string str2 = str1;
    cout << "str2 = " << str2 << endl;
    // string str3 = 'a';
    // cout << "str3 = " << str3 << endl;
    // 这个是可以的
    // 源码：basic_string.h
    // /**
    //    *  @brief  Set value to string of length 1.
    //    *  @param  __c  Source character.
    //    *
    //    *  Assigning to a character makes this string length 1 and
    //    *  (*this)[0] == @a c.
    //    */
    //   _GLIBCXX20_CONSTEXPR
    //   basic_string&
    //   operator=(_CharT __c)
    //   {
	// this->assign(1, __c);
	// return *this;
    //   }

    string str4;
    str4.assign("Hello C++");
    cout << "str4 = " << str4 << endl;

    string str5;
    str5.assign("Hello C++", 5);
    cout << "str5 = " << str5 << endl;

    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl;

    string str7;
    str7.assign(10, 'c');
    cout << "str7 = " << str7 << endl;





}

// 字符串拼接
void test03()
{
    string str1 = "a";
    str1 += "b";
    str1 += 'c';
    string str2 = "defg";
    str1 += str2;
    cout << "str1=" << str1 << endl;

    string str3 = "1";
    str3.append("2");

    str3.append("345678",4);
    str3.append(str2);
    str3.append(str2, 2, 2);
    cout << "str3=" << str3 << endl;
    // Hello World
    // str1=abcdefg
    // str3=123456defgfg
    str3.append(str2, 2, 10);
    cout << "str3=" << str3 << endl;
    // Hello World
    // str1=abcdefg
    // str3=123456defgfg
    // str3=123456defgfgfg



}

// 字符串查找 & 替换
void test04()
{
    // 查找
    string str1 = "012345678923";
    cout << str1.find("23") << endl; // 2
    cout << str1.find("hij") << endl; // -1
    cout << str1.rfind("23") << endl; // 10
    // 替换
    cout << str1.replace(1, 3, "abcd") << endl; // 0abcd45678923
}

// 字符串比较
// = 0
// > 1
// < -1
void test05()
{
    string str1 = "Hello";
    string str2 = "Hello";
    cout << str1.compare(str2) << endl; //0
    str2 = "Iello";
    cout << str1.compare(str2) << endl; //-1
    str2 = "Gello";
    cout << str1.compare(str2) << endl; //1
}

// 字符串存取
void test06()
{
    // 读
    string str1 = "012345";
    cout << str1[3] << endl; // 3
    cout << str1[100] << endl; // ""
    cout << str1.at(1) << endl; // 1
    // cout << str1.at(100) << endl; // Exception
    // 写
    str1[1] = 'a';
    str1.at(2) = 'b';
    cout << str1 << endl; // 0ab345;

    string s = "abc";
    string st = s;
    // st[0] = "1"; // exception
    cout << st << endl; // abc

}


// 字符串插入和删除
void test07()
{
    string str1 = "012345";
    cout << str1.insert(2, "abc") << endl; // 01abc2345;
    string str2 = "xyz";
    cout << str1.insert(2, str2) << endl; // 01xyzabc2345;
    cout << str1.insert(2, 2, '#') << endl; // 01##xyzabc2345;
    cout << str1.erase(2, 8) << endl; // 012345;
}

// 字符串的子串
void test08()
{
    string str1 = "0123456";
    cout << str1.substr(1,3) << endl; // 123
    // cout << str1.substr(100,1000) << endl; // exception out_of_range
}

int main(){
    cout << "Hello World" << endl;
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    // test06();
    // test07();
    test08();
}