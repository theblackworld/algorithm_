void Arithmetic::PriorityOut(stack<char>& s, char a){
  while(!s.empty()){
    char b = s.top();
	if(b!= '(' && Cmp(a,b)){
	  s.pop();
	  last_.push_back(b); //生成后缀表达式;
	}
    else break;
  }
  s.push(a);
}

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

int Arithmetic::Calculate(){
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