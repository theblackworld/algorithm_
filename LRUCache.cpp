/*基本描述参见leetcode: 

   大致意思是实现lru算法，并且在获取相应数据的的算法复杂度可以达到0(1);

   实现大致思路： hashtable + doublelist
*/
//模板实现保证程序的泛用性;
#include<unordered_map>
#include<iterator>

using std::iterator;
using std::unordered_map;

template<class _KEY, class _VALUE>
class LRUCache{
	public:
	
	  LRUCache(int capacity) : capacity_(capacity),
	                           head_(nullptr),
							   tail_(nullptr){};
	  
	  LRUCache() : capacity_(0),
	               head_(nullptr),
				   tail_(nullptr){};
	  
	  ~LRUCache();
	
	  void Put(_KEY key , _VALUE value);
	
	  void Get(_KEY key);
	  
	  
   	private:
	 
	  void SetHead(Node* node);
	  
	  void Remove(Node* node);
	
	  // no copying allowed;
	  
      LRUCache(const LRUCache&){};	
 	
	  LRUCache& operator=(const LRUCache&){};
	  
	  struct Node{
		_KEY    key_;  
		
		_VALUE  value_;
   		
		Node*   prev_; 
		
		Node*   next_;
   
  	    Node(_KEY key, _VALUE value) : key_(key),
                                       value_(value),
                                       prev_(nullptr),									   
	                                   next_(nullptr){ }
	  };  
	  
	  int capacity_; //当前cache的容量;	
	  
	  Node* head_;
	  
	  Node* tail_;
	  //key points 
	  unordered_map<_KEY, Node*>  container_;	  	
};

template<class _KEY, class _VALUE>
void LRUCache<_KEY, _VALUE>::~LRUCache(){
	
  for(auto iter = container_.begin(); iter != container_.end();){
	  
    delete iter->second;    
	
	iter->second = nullptr;
	
	container_.erase(iter++);  //防止迭代器失效，在删除的同时访问下一个位置;
	
  }  
  
  head_ = nullptr;
  
  end_ = nullptr;
}

template<class _KEY, class _VALUE>
void LRUCache<_KEY , _VALUE>::SetHead(Node* node){
	
   node_->next = head_;
   
   node_->prev = nullptr;
   
   if(head_!= nullptr) head_->prev = node;  
   
   head_ = node;
   
   if(end_ == nullptr) end_ = head_; 
}

template<class _KEY, class _VALUE>
void LRUCache<_KEY, _VALUE>::Remove(Node* node){	
	//正常的步骤
/*	
	node->prev_->next_ = node->next_;
	
	node->next_->prev_ = node->prev_;
    
	需要注意的是首位步的删除;
*/	
	if(node->prev_ != nullptr){
 	   node->prev_->next_ = node->next_;   
	}
	else{	
       head_ = node->next_;	//	
	}
	
	if(node->next_ != nullptr){
	   node->next_->prev_ = node->prev_;	
	}
	else{
	   tail_ = node->prev_;	
	}	
}
//flag 标定是否获得相应的数据;
template<class _KEY, class _VALUE>
_VALUE LRUCache<_KEY, _VALUE>::Get(_KEY key , int& flag){
    
   _VALUE a;   
   
   if(container_.count(key) == 0){
	  
	  flag = 0;
	  
	  return a;	   
   }	
   else{
	 // exists value;  
     Remove(container_[key]);

     SetHead(container_[key]);	 
      
	 flag = 1; //意味着你可以获得数据是有效的;
	 
	 return container_[key]->value_;    
   }		
}

template<class _KEY, class _VALUE>
void LRUCache<_KEY, _VALUE>::Put(_KEY key, _VALUE value){
  
  assert(capacity_ <= 0 );	
	
  if(container_.count(key) !=0){
	  
	container_[key]->value_ = value;  
	  
	Remove(container_[key]);
 
    SetHead(container_[key]); 
  }
  else{
		  
	Node* t = new Node(key, value);  
	
    if(container.size() == capacity_){
	 
       Node* temp = end_;
	   
	   Remove(end_);
	   
	   SetHead(t);
	   
	   delete temp;
	    		
	   container_.insert(pair<_KEY, Node*>(key, t));	
	}
	else{
	   SetHead(t);
	   
	   container_.insert(pair<_KEY, Node*>(key, t));
	}
  }
}

