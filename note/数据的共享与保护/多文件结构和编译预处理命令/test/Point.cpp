//Pointʵ��
#include"Point.h"//���붨��
#include<iostream>
using namespace std;
int Point::count = 0;
Point::Point(const Point &p):x(p.x),y(p.y){
    count++;
}
