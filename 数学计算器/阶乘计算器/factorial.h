#include<vector>
using std::vector;

class Multiply{
   public:
     Multiply():num_(0),result_(-1),pos_(-1){}

	 Multiply(int num):num_(num),result_(-1),pos_(-1){}

	 void Set(int num){num_ = num;}

	 void Calculate();  //to store all the num in the result_ or the result_vec;

     long long Count(int n);  //if (num_ < 20) no need to allocate more space;

	 int SumByVector(vector<int>& );

	 int SumByNum(long long num);

	 void ShowResult();
	 
	 int CountEach();   //计算每一位数的相等和;

   private:
     //no copying allowed;
     Multiply(const Multiply&);

	 Multiply& operator=(const Multiply&);
     // num!
	 int num_;  
	 // 当阶乘小于20的时候此位有效，其余置为-1;
     long long result_;
     // 当前数字的位数,当且仅当数字极大阶乘超过20的时候此成员有效
	 int pos_;  
	 // 存储大数
	 vector<int> result_vec_;
};