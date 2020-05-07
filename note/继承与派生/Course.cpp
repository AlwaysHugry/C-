#include <iostream>
using namespace std;
class Course
{
private:
    string name;

protected:
    string id;

public:
    string teacherName;
    Course();
    Course(string name);
    void setId(string id);
    void setTeacherName(string name);
    string getId();
    string getTeacherName();
};

Course::Course()
{
    cout<<"Course default construction!"<<endl;
}
Course::Course(string name)
{
    cout<<"Course name's construction!"<<endl;
}
void Course::setId(string id){
    this->id = id;
}
void Course::setTeacherName(string name)
{
    this->name = name;
}
string Course::getId()
{
    return id;
}
string Course::getTeacherName()
{
    return name;
}