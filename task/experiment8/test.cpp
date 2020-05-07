#include <iostream>
using namespace std;
class vehicle
{
    int wheels;
    float weight;

public:
    void message()
    {
        cout << "vehicle message\n";
    }
};
class car : public vehicle
{
    int passengers;

public:
    void message() { cout << "car message\n"; }
};
class truck : public vehicle
{
    int goods;

public:
    void message()
    {
        cout << "truck message\n";
    }
};
int main()
{
    vehicle obj, *ptr;
    car obj1;
    truck obj2;
    ptr = &obj;
    ptr->message();
    ptr = &obj1;
    ptr->message();
    ptr = &obj2;
    ptr->message();
}