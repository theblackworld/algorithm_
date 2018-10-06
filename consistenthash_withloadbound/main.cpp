#include"../include/aid_function.h"   //类似于读取配置文件;
#include"../include/murmurhash.h"
#include"../include/consistent.h"
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
const int CLIENT = 100000;
int main(){

  unsigned int real_num, vir_num;

  unsigned int up_load, down_load;

  unsigned int type;
  char** server;
  char** client;


  vector<char*> client_contain(CLIENT,NULL);

  cout<<"输入算法种类:1. consistent hash, 2. consistent hash with bound, 3. consistent hash withd bound (up and down)";

  cin>>type;

  cout<<"输入初始服务节点个数:";

  cin>>real_num;

  cout<<"输入初始虚拟节点个数:";

  cin>>vir_num;

  cout<<"输入各个节点的预设负载上限:";

  cin>>up_load;

  cout<<"输入每个节点的预设负载下限:";

  cin>>down_load;

  // 第一步读取配置信息,这里采用随机生成方式;
  server = new char*[real_num];

  for(unsigned int i=0; i<real_num; i++){
    server[i] = new char[50];
    memset(server[i], 0, 50);
  }

  for(unsigned int i=0; i<real_num; i++){
    RandIp(server[i]);
  }

  for(unsigned int i=0; i<real_num; i++) cout<<server[i]<<endl;

  // 一致性哈希的配置;

  // 可以反复进行试验验证！！！;

  ConsistentHash node(real_num, vir_num, up_load, down_load, type);

  node.Init(server);

 // node.ShowVirInfo();

 // node.ShowRealInfo();

 // 现在随机生成客户端的连接看负载的情况!!!;

  client = new char*[CLIENT];

  for(int i=0; i<CLIENT; i++){
    client[i] = new char[20];
    memset(client[i], 0, 20);
  }

  for(unsigned int i=0; i<CLIENT; i++){
    RandIp(client[i]);
    //client_contain[i] = client[i];
  }


  for(int i=0; i<CLIENT; i++){
    cout<<node.GetTheServer(client[i])<<endl;
  }

  node.ShowLinkInfo();

  cout<<endl;

  cout<<"the change time is:"<<node.GetTheChange();
  return 0;
}

