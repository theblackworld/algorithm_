#include"factorial.h"
#include<iostream>
using std::cout;

int main(){
//test 示例;
  for(int i=20; i<=100; i++){

    Multiply mu;

    mu.Set(i);

    mu.Calculate();

    cout<<i<<"的阶乘是:";

    mu.ShowResult();

    cout<<"每一位的合是:";

    cout<<mu.CountEach()<<endl;
  }
  
  return 0;
}
