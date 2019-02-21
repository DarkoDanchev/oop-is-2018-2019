#include <iostream>
#include <cmath>

using namespace std;

//A point in 2d plain
struct Point
{
  int x;
  int y;

  void multiplyBySkalar(int s)
  {
    x = x*s;
    y = y*s;
  }

  void print()
  {
    cout<<"("<<x<<","<<y<<")"<<endl;
  }

  int distance(Point p2)
  {
    int dis = sqrt(pow(p2.x - x,2) + pow(p2.y - y,2));

    x = dis;
    y = dis;

    return dis;
  }
};

Point createPoint(int x, int y)
{
  Point p;
  p.x = x;
  p.y = y;

  return p;
}

void createPoint(Point& p, int x,int y)
{
  p.x = x;
  p.y = y;
}

int distance(Point p1, Point p2)
{
  int dis = sqrt(pow(p2.x - p1.x,2) + pow(p2.y - p1.y,2));

  return dis;
}
int main()
{
  Point p1;
  Point p2;

  p1 = createPoint(3,3);
  createPoint(p2,9,9);

  p1.multiplyBySkalar(4);

  p1.print();
  p2.print();

  int dis1 = p1.distance(p2);
  int dis2 = distance(p1,p2);

  cout<<dis1<<endl;
  cout<<dis2<<endl;

  return 0;
}
