#include<iostream>
#include"Pairclass.cpp"

using namespace std;

int main(){

  Pair<int,int> p1;

  p1.setX(20);
  p1.setY(30);

  cout << "p1x:" << p1.getX() << "p1y:" << p1.getY() << endl;

  Pair <int,Pair<int,int>> p2;

  p2.setX(3423);
  p2.setY(p1);

  cout << "p2x:" << p2.getX() << "p2y1:" << p2.getY().getX() << "p2y2:" << p2.getY().getY() << endl;
  
}