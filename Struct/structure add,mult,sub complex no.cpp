#include<iostream>
using namespace std;
struct complexno
{
  int real;
  int imag;
};
struct complexno add(struct complexno a, struct complexno b)
{
  struct complexno d;
  d.real = a.real+b.real;
  d.imag = a.imag+b.imag;
  return d;
}
struct complexno sub(struct complexno a, struct complexno b)
{
  struct complexno d;
  d.real = a.real-b.real;
  d.imag = a.imag-b.imag;
  return d;
}
struct complexno multiply(struct complexno a, struct complexno b)
{
  struct complexno d;
  d.real = (a.real*b.real);
  d.imag = (a.imag*b.imag);
  return d;
}
int main()
{ 
  struct complexno d1 = {6,4};
  struct complexno d2 = {13,2};
  struct complexno d = add(d1,d2);
  struct complexno e = sub(d1,d2);
  struct complexno f = multiply(d1,d2);
  
  cout << "ADD = " << d.real << " + " << d.imag<<"i"<<endl;
  cout << "SUB = " << e.real << " + " << e.imag<<"i"<<endl;
  cout << "MUL = " << f.real << " + " << f.imag<<"i"<<endl;
  return 0;
}
 
