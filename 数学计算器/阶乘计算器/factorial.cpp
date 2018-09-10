/*
  函数说明:
     根据num_计算num_!结果，如果大于20则把相应结果放置在result_vec_中;
*/
void Multiply::Calculate(){

  long long result = 0;

  int pos = 0;

  vector<int> contain(100000,0);
  vector<int> containt(100000,0);

  if(num_ <=20){
	result_ = Count(num_);
  }
  else{
	result = Count(20);

	while(result != 0){
      contain[pos] = (result%10);
      pos++;  //代表几个数;
      result = result/10;
    }

	for(int i=21; i<=num_; i++){

      int temp = i;
      int add = 0;
      int time = 0;

      while(temp!=0){
        add = temp%10;
        temp = temp/10;
        for(int j=0; j<pos; j++){
          containt[j+time] += contain[j]*add;
        }
        time++;
      }

      int addt = 0; //进位;

      for(int i=0; i<time+pos-1; i++){
        contain[i] = (containt[i]+addt)%10;
        addt = (containt[i]+addt)/10;
      }

      //each time you have to erase the bit by zero;
      for(int j=0; j<time+pos-1; j++) containt[j] = 0;

      if(addt != 0){
        contain[time+pos-1] = addt;
        pos = time+pos;
      }
      else{
        pos = time+pos-1;
      }
    }
    result_ = -1;

    pos_ = pos;

	result_vec_.resize(pos);

	cout<<"result size is"<<result_vec_.size()<<endl;

	for(int i=0; i<pos; i++) result_vec_[i]= contain[i];

    reverse(result_vec_.begin(), result_vec_.end());
  }
}
/*
  函数说明:
    计算小于20数的阶乘;
*/
long long Multiply::Count(int n){

 long long result = 1;

 if(n==0) return  1;

 for(int i=1; i<=n; i++){
   result = result*i;
 }

 return result;
}
/*
  函数说明:
    
	计算大于20阶乘结果的各个位之和;
*/
int Multiply::SumByVector(vector<int>& input){
  int result = 0;
  for(int i=0; i<input.size(); i++){
    result += input[i];
  }
  return result;
}
/*
  函数说明:
    
	计算小于等于20阶乘结果的各个位之和;
*/
int Multiply::SumByNum(long long num){

  long long sum = 0;

  while(num/10!=0){
    sum += num%10;
    num = num/10;
  }
  return sum+num;
}
/*
  函数说明:
    显示阶乘的结果;
*/
void Multiply::ShowResult(){
  if(result_ == -1){
    for(int i=0; i<pos_; i++) cout<<result_vec_[i];
    cout<<endl;
  }
  else{
    cout<<result_<<endl;
  }
}
/*
  函数说明:
    
	计算阶乘各个位之和;
*/
int Multiply::CountEach(){
  if(result_ != -1){
	return SumByNum(result_);
  }
  else{
	return SumByVector(result_vec_);
  }
}  
  