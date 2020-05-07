#include<iostream>
using namespace std;
class Student{
    public :
      Student(string s,int t,int h):height(h){
        name = s;
        age = t;
        id++;
      }
      void showName(){
        cout<<name<<"*"<<endl;
      }
      void showName()const{
        cout<<name<<endl;
      }//常对象成员
    private :
      string name ;
      int age;
      static int id;
      static const char sex;
      const int height;
};
const char Student::sex = 'b';
int Student::id = 0; 
int main(){
    Student a("Lucre",20,172);
    a.showName();//会优先调用非常成员函数
    const Student b("Alas",21,168);//只能调用常成员函数
    b.showName();
}