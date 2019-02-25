#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
  double x;
  double y;
public:
  Point()
  {
    x = 0;
    y = 0;
  }
  Point(double _x, double _y)
  {
    x = _x;
    y = _y;
  }


  void print() const
  {
    cout<<"("<<x<<","<<y<<")"<<endl;
  }

  double getX() const
  {
    return x;
  }

  double getY() const
  {
    return y;
  }

  void setX(double _x)
  {
    x = _x;
  }

  void setY(double _y)
  {
    y = _y;
  }

  void set(double _x, double _y)
  {
    x = _x;
    y = _y;
  }
};

double distance(Point p1, Point p2)
{
  return sqrt(pow(p2.getX() - p1.getX(),2) + pow(p2.getY() -
                                                 p1.getY(),2));
}

class Triangle
{
private:
  Point first;
  Point second;
  Point third;
  double firstHeight;
  double secondHeight;
  double thirdHeight;

  void calcHeight()
  {
    double d1 = distance(first,second);
    double d2 = distance(first,third);
    double d3 = distance(second,third);

    firstHeight = 2*area() / d1;
    secondHeight = 2*area() / d2;
    thirdHeight = 2*area() / d3;


  }
public:
  Triangle()
  {
    first = Point(0,0);
    second = Point(1,1);
    third = Point(0,2);
    calcHeight();
  }
  Triangle(Point _first,Point _second, Point _third)
  {
    first = _first;
    second = _second;
    third = _third;
    calcHeight();
  }

  void print()
  {
    cout<<"First Point: ";
    first.print();
    cout<<"Second Point: ";
    second.print();
    cout<<"Third Point: ";
    third.print();
  }

  double perimeter()
  {
    double d1 = distance(first,second);
    double d2 = distance(first,third);
    double d3 = distance(second,third);

    return d1 + d2 + d3;
  }

  double area()
  {
    double d1 = distance(first,second);
    double d2 = distance(first,third);
    double d3 = distance(second,third);

    double s = perimeter() / 2;

    double area = sqrt(s*(s - d1)*(s - d2)*(s - d3));

    return area;
  }

  double getFirstHeight() const
  {
    return firstHeight;
  }

  double getSecondHeight() const
  {
    return secondHeight;
  }

  double getThirdHeight() const
  {
    return thirdHeight;
  }


};


int main()
{
  Point p;
  p.print();
  Point p1(2,1);
  Point p2 = Point(2,2);
  Point p3(3,1);
  p1.set(15,3);
  p1.print();
  //Triangle t = Triangle(p1,p2,p3);
  Triangle t(p1,p2,p3);
  t.print();
  p1.print();
  double perimeter = t.perimeter();
  cout<<"Perimeter: "<<t.perimeter()<<endl;
  cout<<"Area: "<<t.area()<<endl;
  cout<<"First Height: "<<t.getFirstHeight()<<endl;
  return 0;
}
