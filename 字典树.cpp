//  1。字典树：
//  应用场景：
     
//  适用于需要查找速度相对稳定，且相对较快的场景，且对内存要求没有那么严格约束的场景

//   相对于hashtable由于hash table本身hash计算需要时间，其次有可能出现hash key重复现象，再有到hash key定位到slot之后如果存在重复依旧需要0（M）的比较
//复杂度，其中m为需要查找的字符串的长度;

const int NUM = 26; // 可以根据这个调整每次节点中的孩子的个数，具体取决于你字典中每个元素的范围；比如ascll码值小写26字母则定位26;
                    // 当然需要看你实际的应用场景;

struct Node{
	
   char value_;	
	
   vector<Node*> child_;	
	
   Node(char value): value_(value), child_(vector<Node*> temp(NUM, nullptr)){} 

class Dictionary{
	
   public:
   
	 Dictionary();
	
	 ~Dictionary();
	 
	 void Add(string& input);  
	
	 void Add(vector<string>& input);  
	
     void IsInDict(string& str);
	
   private:
   
      Node* root_;
};

void Dictionary::~Dictionary(){
	
	
	
	
}

void Dictionary::Add(string& input){
	
  Node* temp = root_;
  
  for(int i=0; i<input.size(); i++){
	if(temp->value_ == input[i]){
	  //每一个对应的位置;   	
	}  
  }	
	
}

void Dictionary::Add(vector<string>& input){
	
	
}

