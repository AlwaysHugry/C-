#include<iostream>
#include"Course.cpp"
using namespace std;
class Math : public Course{
    private :
       string book[5];
    public :
       Math(string name,string *p)
       {
           Course(name);
           //book
       }
};