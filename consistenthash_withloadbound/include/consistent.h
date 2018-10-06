#include<map>
#include<unordered_map>
#include<string>
using std::string;
using std::map;
using std::unordered_map;

struct RealNode{
  uint32_t load_bound_;   //����ڵ�ĸ���;
  uint32_t index_;        //����ڵ�λ��;
  uint32_t cur_link_;     //����ڵ㵱ǰ������;
  const char* server_name_;   //����ڵ��ip;
  uint32_t vir_node_;
  RealNode(uint32_t load_bound, uint32_t index,const char* server_name)
                                     : load_bound_(load_bound),
                                       index_(index),
                                       cur_link_(0),
									   server_name_(server_name),
									   vir_node_(0){}
};

class ConsistentHash{
  public:
   ConsistentHash(int real_num, int vir_num,int up_load,int down_load,int type):
                      real_num_(real_num),
                      vir_num_(vir_num),
					  up_load_(up_load),
					  down_load_(down_load),
					  type_(type){}

   ~ConsistentHash(){}

   void Init(char** server);  //��ʼ��Բ��,��ҪIP֮���ӳ���ϵ;

   int GetTheServer(char* client);

   int GetTheServerIndex(char* client);     //���ݴ������ݵ�IPת����Ӧ��key��ȡʵ�ʷ���ڵ���±�;

   int GetTheServerIndexWithBound(char* client);

   int GetTheServerIndexWithBoundUpAndDown(char* client);

   const char* GetTheServerName(char* client);

   void AddRealNode(char* server);  //

   void DelRealNode(char* server);

   char* Compose(int i,int j,char* str);

   void ShowVirInfo();

   void ShowRealInfo();

   void ShowLinkInfo();

   uint32_t GetTheChange(){
     return CHANGE;
   }
   private:
     //no copying allowed;
	 ConsistentHash(const ConsistentHash&){}
     ConsistentHash& operator=(const ConsistentHash&){}
     static uint32_t CHANGE;
     uint32_t real_num_;   // ʵ�ʽڵ����;
	 uint32_t vir_num_;    // ����ڵ����;
	 uint32_t up_load_;    // ��������;
	 uint32_t down_load_;  // ��������;
     uint32_t type_;

     map<unsigned int, unsigned int> circle_node_;     // Բ��,  keyΪ����ڵ�, intΪindex;
	 unordered_map<unsigned int, RealNode*> data_map_; // �洢��index��RealNode��ӳ���ϵ;
};
