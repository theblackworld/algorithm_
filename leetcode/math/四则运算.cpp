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

int Calcualte(const string &input){

  stack<int> s;

  int j=0;

  for(int i=0; i<input.size(); i++) cout<<input[i];

  for(int i=0; i<input.size();){
    if(input[i]>='0' && input[i] <= '9'){
      int result = 0;
      //陷入死循环的怪圈;
      for(j=i; j<input.size() && input[j]!='#'; j++) {
        result = result*10+static_cast<int>(input[j] - '0');
      }
      s.push(result);
      i = j+1;
    }
    else{
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      s.push(Operation(a,b,input[i]));
      i++;
    }
  }

  return s.top();
}

bool Cmp(char a, char b){ //是否该出栈;
  if(a == '+' || a =='-') return true;
  else if(a == '*' || a == '/') return (b == '*') || ( b == '/');
}
void PriorityOut(string& input, stack<char>& s,char a){
  while(!s.empty()){
    char b = s.top();

	if(b!= '(' && Cmp(a,b)){
	  s.pop();
	  input.push_back(b);
	}
    else break;
  }
  s.push(a);
}
string Poland(string &input){
  stack<char> s_;
  string result;
  //如果是想检查任意的也无非是这样;
  for(int i=0; i<input.size(); i++){
	if(input[i] >='0' && input[i]<='9'){
      if(i < (input.size() -1) && input[i+1] >='0' && input[i+1]<='9')
	    result.push_back(input[i]);
	  else{
        result.push_back(input[i]); //以#'作为分界线;
        result.push_back('#');
	  }
	}
	else if(input[i] == '('){
	  s_.push(input[i]);
	}
	else if(input[i] == ')'){
	  //需要出栈;
      while(!s_.empty()){
	    char c = s_.top();
	    //cout<<"(:"<<"hehe"<<c<<endl;
		s_.pop();
		if(c!= '('){
		  result.push_back(c);
		}
		else{
		  break;
		}
	  }
	}
    else{
	  PriorityOut(result, s_, input[i]);
	}
  }
  //最后弹出所有内容;
  while(!s_.empty()){
	result.push_back(s_.top());
    s_.pop();
  }

  return result;
}
int main(){
  string input = "900+30*(30-10)*3+40/2";
  cout<<Poland(input)<<endl;
  string result = Poland(input);
  cout<<Calcualte(result)<<endl;
  return 0;
}