//algorithm:

//中缀表达式转后缀表达式:

/*
// 0 - 9 的 四则运算;
//step one:
  1. 当当前字符为数字时，直接输出;
//step two
  2. 当当前字符为”(“时，将其压栈;
//step three:
  3. 当当前字符为”)”时，则弹出堆栈中最上的”(“之前的所有运算符并输出，然后删除堆栈中的”(”;
//step four:
  4. 当当前字符为运算符时，则依次弹出堆栈中优先级大于等于当前运算符的(到”(“之前为止)，输出，再将当前运算符压栈;

  5. 最后弹出所有栈中的内容输出;
*/
/*
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int Operation(int a, int b, char c){
  switch(c){
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/': return a/b;
    default : break;
  }
}

int Calcualte(const string &mid_){

  stack<int> s;

  int j=0;

  for(int i=0; i<mid_.size(); i++) cout<<mid_[i];

  for(int i=0; i<mid_.size();){
    if(mid_[i]>='0' && mid_[i] <= '9'){
      int last_ = 0;
      //陷入死循环的怪圈;
      for(j=i; j<mid_.size() && mid_[j]!='#'; j++) {
        last_ = last_*10+static_cast<int>(mid_[j] - '0');
      }
      s.push(last_);
      i = j+1;
    }
    else{
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      s.push(Operation(a,b,mid_[i]));
      i++;
    }
  }

  return s.top();
}

bool Cmp(char a, char b){ //是否该出栈;
  if(a == '+' || a =='-') return true;
  else if(a == '*' || a == '/') return (b == '*') || ( b == '/');
}
void PriorityOut(string& mid_, stack<char>& s,char a){
  while(!s.empty()){
    char b = s.top();

	if(b!= '(' && Cmp(a,b)){
	  s.pop();
	  mid_.push_back(b);
	}
    else break;
  }
  s.push(a);
}
string Poland(string &mid_){
  stack<char> s_;
  string last_;
  //如果是想检查任意的也无非是这样;
  for(int i=0; i<mid_.size(); i++){
	if(mid_[i] >='0' && mid_[i]<='9'){
      if(i < (mid_.size() -1) && mid_[i+1] >='0' && mid_[i+1]<='9')
	    last_.push_back(mid_[i]);
	  else{
        last_.push_back(mid_[i]); //以#'作为分界线;
        last_.push_back('#');
	  }
	}
	else if(mid_[i] == '('){
	  s_.push(mid_[i]);
	}
	else if(mid_[i] == ')'){
	  //需要出栈;
      while(!s_.empty()){
	    char c = s_.top();
	    //cout<<"(:"<<"hehe"<<c<<endl;
		s_.pop();
		if(c!= '('){
		  last_.push_back(c);
		}
		else{
		  break;
		}
	  }
	}
    else{
	  PriorityOut(last_, s_, mid_[i]);
	}
  }
  //最后弹出所有内容;
  while(!s_.empty()){
	last_.push_back(s_.top());
    s_.pop();
  }

  return last_;
}
int main(){
  string mid_ = "900+30*(30-10)*3+40/2";
  cout<<Poland(mid_)<<endl;
  string last_ = Poland(mid_);
  cout<<Calcualte(last_)<<endl;
  return 0;
}*/

class  Arithmetic{
  public:
    Arithmetic(string& mid_):mid_(mid_){}
    
	~Arithmetic();	
	
	bool Cmp(char a, char b){
      if(a == '+' || a =='-') return true;
      else if(a == '*' || a == '/') return (b == '*') || ( b == '/');
    }
	
	void PriorityOut(stack<char>& s, char a);
	
	void Poland();
	
	int Calcualte();
    
	int Operation(int a, int b, char c);
	
	void Reset(string& input){		
	  mid_ = input;
      last_.clear();	  
	};
	
  private:
    //no copyinh allowed here;
    Arithmetic(const Arithmetic &){};
    Arithmetic& operator=(const Arithmetic&){};	
	
    string mid_;  // 中缀表达式;
    string last_; // 后缀表达式; 	
}

void Arithmetic::PriorityOut(stack<char>& s, char a){
  while(!s.empty()){
    char b = s.top()；
	if(b!= '(' && Cmp(a,b)){
	  s.pop();
	  last_.push_back(b); //生成后缀表达式;
	}
    else break;
  }
  s.push(a);
}
//last_ 由  mid_生成;
void Arithmetic::Poland(){
  
  stack<char> s_;
  //如果是想检查任意的也无非是这样;
  for(int i=0; i<mid_.size(); i++){
	if(mid_[i] >='0' && mid_[i]<='9'){
      if(i < (mid_.size() -1) && mid_[i+1] >='0' && mid_[i+1]<='9')
	    last_.push_back(mid_[i]);
	  else{
        last_.push_back(mid_[i]); //以#'作为分界线;
        last_.push_back('#');
	  }
	}
	else if(mid_[i] == '('){
	  s_.push(mid_[i]);
	}
	else if(mid_[i] == ')'){
	  //需要出栈;
      while(!s_.empty()){
	    char c = s_.top();
	    //cout<<"(:"<<"hehe"<<c<<endl;
		s_.pop();
		if(c!= '('){
		  last_.push_back(c);
		}
		else{
		  break;
		}
	  }
	}
    else{
	  PriorityOut(s_,  mid_[i]);
	}
  }
  //最后弹出所有内容;
  while(!s_.empty()){
	last_.push_back(s_.top());
    s_.pop();
  }	
}

int Arithmetic::Calcualte(){
  //step one ;
  
  
  Poland();
		
  stack<int> s;
  
  int j=0;

  for(int i=0; i<last_.size();){
    if(last_[i]>='0' && last_[i] <= '9'){
      int result = 0;
      //正负数在此完成;
      for(j=i; j<last_.size() && last_[j]!='#'; j++) {
        result = result*10+static_cast<int>(last_[j] - '0'); 
      }
      s.push(result);
      i = j+1;
    }
    else{
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      s.push(Operation(a, b, last_[i]));
      i++;
    }
  }
  return s.top();
}	
	

//精度控制在这个函数里面完成;
int Arithmetic::Operation(int a, int b, char c){
   switch(c){
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/': return a/b;
    default : break;      //may exists no return;
  }  
}


