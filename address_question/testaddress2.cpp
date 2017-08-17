#include <iostream>
using namespace std;

//linux的栈从低位开始压(因为从上向下是从高位到低位,与windows相反),参数列表从右向左,变量按照声明顺序.
void  func(int param1, int param2, int param3)
{
  int var1 = param1;
  int var2 = param2;
  int var3 = param3;
  cout<<&param1<<endl;
  cout<<&param2<<endl;
  cout<<&param3<<endl;
  cout<<&var1<<endl;
  cout<<&var2<<endl;
  cout<<&var3<<endl;
}

int main()
{
  func(1,2,3);
  return 0;
}
