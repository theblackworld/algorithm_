#include"../include/consistent.h"
#include"../include/murmurhash.h"
#include<iterator>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using std::pair;
using std::cout;
using std::endl;
using std::vector;
//目前暂定down_load为负载上限
uint32_t ConsistentHash::CHANGE = 0;

char* ConsistentHash::Compose(int i,int j,char* str){
  char* result = new char[30];
  sprintf(result,"%s.%d.%d",str,i,j);
  return result;
}

void ConsistentHash::Init(char** server){

  for(uint32_t i=0; i<real_num_; i++){

	RealNode* node = new RealNode(down_load_, i, server[i]);
	data_map_.insert(pair<unsigned int, RealNode*>(i,node));  //存储index => RealNode的映射关系，并且保留所有节点信息;
	for(uint32_t j=0; j<vir_num_; j++){
	  char* node_key = Compose(i,j,server[i]);
	  uint32_t pos = MurmurHashChar(node_key,j);
	  if(circle_node_.count(pos) != 0) cout<<node_key<<endl;
	  else{
       circle_node_.insert(pair<unsigned int,unsigned int>(pos, i));
       data_map_[i]->vir_node_++;
	  }
	  delete [] node_key;
     }
   }
}

int ConsistentHash::GetTheServer(char* client){
  switch(type_){
    case 1:
      return GetTheServerIndex(client);
      break;
    case 2:
      return GetTheServerIndexWithBound(client);
      break;
    case 3:
      return GetTheServerIndexWithBoundUpAndDown(client);
      break;
    default:
       return -1;
  }
}

//对应成有界负载的这里需要改变;
int ConsistentHash::GetTheServerIndex(char* client){

  uint32_t key = MurmurHashChar(client, 0xbc9f1d34);

  map<unsigned int,unsigned int>::iterator it = circle_node_.lower_bound(key);

  if(it == circle_node_.end()){
	it =  circle_node_.begin();
  }

  data_map_[it->second]->cur_link_++; //服务节点连接数增加1;

  return it->second;
}

int ConsistentHash::GetTheServerIndexWithBound(char* client){

  uint32_t key = MurmurHashChar(client, 0xbc9f1d34);

  map<unsigned int,unsigned int>::iterator it = circle_node_.lower_bound(key);

  if(it == circle_node_.end()){
	it =  circle_node_.begin();
  }

  //从这里与之前不一样！
  if(data_map_[it->second]->cur_link_ > down_load_){
    //需要顺着往下找;
    CHANGE++;

    uint32_t index = it->second;

    while(data_map_[index]->cur_link_ > down_load_){
       index++;
       if(index>=real_num_){
         index = 0;
       }
    }
    data_map_[index]->cur_link_++;
    return index;
  }
  else{
    data_map_[it->second]->cur_link_++; //服务节点连接数增加1;
    return it->second;
  }
}



int ConsistentHash::GetTheServerIndexWithBoundUpAndDown(char* client){





}


const char* ConsistentHash::GetTheServerName(char* client){

  int index = 0;

  uint32_t key = MurmurHashChar(client, 0xbc9f1d34);

  map<unsigned int,unsigned int>::iterator it = circle_node_.lower_bound(key);

  if(it == circle_node_.end()){
	it = circle_node_.begin();
  }

  data_map_[it->second]->cur_link_++;

  return data_map_[index]->server_name_; //
}

void ConsistentHash::AddRealNode(char* server){
//  unsigned int key = MurmurHashChar(server);
  RealNode* node = new RealNode(down_load_, real_num_, server);

  data_map_.insert(pair<unsigned int, RealNode*>(real_num_, node));

  real_num_++;   //服务节点总数+1;

  for(uint32_t i=0; i<vir_num_; i++){
	char* node_key = Compose(real_num_, i, server);
	unsigned int pos = MurmurHashChar(node_key, i);
	delete [] node_key;
    circle_node_.insert(pair<unsigned int,unsigned int>(pos, real_num_));
  }
}


void ConsistentHash::DelRealNode(char* server){
//  unsigned int key = MurmurHashChar(server);
  for(unsigned int i=0; i<vir_num_; i++){
	char* node_key = Compose(real_num_, i, server);
	uint32_t pos = MurmurHashChar(node_key,i);
	delete [] node_key;

  }
}

void ConsistentHash::ShowVirInfo(){
  cout<<"virtual node infomation:"<<endl;

  for(auto iter = circle_node_.begin(); iter!=circle_node_.end(); iter++){
    cout<<"virtual_node: "<<iter->first<<","<<"real_node: "<<iter->second<<endl;
  }
}

void ConsistentHash::ShowRealInfo(){
  cout<<"virtual node infomation:"<<endl;

  for(auto iter = data_map_.begin(); iter!= data_map_.end(); iter++){
	cout<<"index:"<<iter->second->index_<<",server_name:"<<iter->second->server_name_<<",cur_Link:"<<iter->second->cur_link_
	<<"alloc vir_node:"<<iter->second->vir_node_<<endl;
  }
}

void ConsistentHash::ShowLinkInfo(){
  vector<int> temp;
  for(auto iter = data_map_.begin(); iter!= data_map_.end(); iter++){
    cout<<"server_name:"<<iter->second->server_name_<<",cur_Link:"<<iter->second->cur_link_<<endl;
    temp.push_back(iter->second->cur_link_);
  }

  sort(temp.begin(), temp.end());
  cout<<"the Min link:"<<temp[0]<<endl;
  cout<<"the Max link:"<<temp[temp.size()-1];
}
