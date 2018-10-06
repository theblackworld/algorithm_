#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void RandIp(char*s){
  unsigned int ip1 = rand()%255;
  unsigned int ip2 = rand()%255;
  unsigned int ip3 = rand()%255;
  unsigned int ip4 = rand()%255;
  sprintf(s,"%d.%d.%d.%d",ip1,ip2,ip3,ip4);
}
