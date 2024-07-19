#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

class Person{
public:
    Person(string name, int score = 0)
    {
        this->m_name = name;
        this->m_score = score;
    }
    string m_name;
    int m_score;
};

void createPerson(vector<Person>& ps)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        // string name = "选手";
        // name += nameSeed[i];
        // string name = "选手" + string(nameSeed[i]);
        string name = "选手" + string(1, nameSeed[i]);
        // cout << name << endl;
        cout << string(10, nameSeed[0]) << endl;
        Person p(name, 0);
        ps.push_back(p);
    }
    
}



int main(){

    // 随机数种子
    srand((unsigned int) time(NULL));

    // 创建选手
    vector<Person> vp;
    createPerson(vp);
    for (vector<Person>::iterator it = vp.begin(); it != vp.end(); it++)
    {
        cout << "姓名：" << (*it).m_name << "平均分：" << (*it).m_score << endl;
    }
    
    //  循环选手打分
    for (vector<Person>::iterator i = vp.begin(); i != vp.end(); i++)
    {   
        deque<int> ss;
        for (int y = 0; y < 10; y++)
        {
            int s = rand() % 41 + 60;
            ss.push_back(s);
        }

        // 排序打分
        sort(ss.begin(), ss.end());

        // 去除最高分和最低分
        ss.pop_front();
        ss.pop_back();
        // 给选手赋值平均分
        int sum = 0;
        for (deque<int>::iterator z = ss.begin(); z != ss.end(); z++)
        {
            sum += *z;
        }
        double scoreP = sum / ss.size();
        (*i).m_score = scoreP;
    }
    for (vector<Person>::iterator it = vp.begin(); it != vp.end(); it++)
    {
        cout << "姓名：" << (*it).m_name << "平均分：" << (*it).m_score << endl;
    }

    

    

    

}