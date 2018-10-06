#include"../include/aid_function.h"   //�����ڶ�ȡ�����ļ�;
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

  cout<<"�����㷨����:1. consistent hash, 2. consistent hash with bound, 3. consistent hash withd bound (up and down)";

  cin>>type;

  cout<<"�����ʼ����ڵ����:";

  cin>>real_num;

  cout<<"�����ʼ����ڵ����:";

  cin>>vir_num;

  cout<<"��������ڵ��Ԥ�踺������:";

  cin>>up_load;

  cout<<"����ÿ���ڵ��Ԥ�踺������:";

  cin>>down_load;

  // ��һ����ȡ������Ϣ,�������������ɷ�ʽ;
  server = new char*[real_num];

  for(unsigned int i=0; i<real_num; i++){
    server[i] = new char[50];
    memset(server[i], 0, 50);
  }

  for(unsigned int i=0; i<real_num; i++){
    RandIp(server[i]);
  }

  for(unsigned int i=0; i<real_num; i++) cout<<server[i]<<endl;

  // һ���Թ�ϣ������;

  // ���Է�������������֤������;

  ConsistentHash node(real_num, vir_num, up_load, down_load, type);

  node.Init(server);

 // node.ShowVirInfo();

 // node.ShowRealInfo();

 // ����������ɿͻ��˵����ӿ����ص����!!!;

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

