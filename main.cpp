#include <QCoreApplication>
#include <iostream>
#include <list>
#include <string>
using namespace std;

// создание строки из *
string create_str(int i)
{
    string st="";
    for(int j=0; j<i; j++)
        st +="*";
    return st;
}

// добавление пробелов
string add_space(int count)
{
    string st = "";
    for(int i=0; i<count;i++)
        st += " ";
    return st;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    list<string> values;
    int N, count = 1;
    cout<<"Enter value N=";
    cin>>N;

    // создание строк с * и добавление в список
    for(int i=0; i<N; i++)
    {
        values.push_back(create_str(count));
        count += 2;
    }
    count = 0;
    // добавлене пробелов
    for(list<string>::reverse_iterator itr=values.rbegin(); itr!=values.rend(); ++itr)
        *itr = add_space(count++) + *itr;
    // вывод треугольника
    for(list<string>::iterator itr=values.begin(); itr!=values.end(); ++itr)
        cout<<*itr<<endl;
    return a.exec();
}

