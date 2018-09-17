#include<string>
#include<stack>
using std::string;
using std::stack;

class  Arithmetic{
  public:
    Arithmetic(const string& mid_):mid_(mid_){}

	~Arithmetic(){ };

	bool Cmp(char a, char b){
      if(a == '+' || a =='-') return true;
      else if(a == '*' || a == '/') return (b == '*') || ( b == '/');
    }

	void PriorityOut(stack<char>& s, char a);

	void Poland();

	int Calculate();

	int Operation(int a, int b, char c);

	void Reset(const string& input){
	  mid_ = input;
      last_.clear();
	};

  private:
    //no copyinh allowed here;
    Arithmetic(const Arithmetic &){};
    Arithmetic& operator=(const Arithmetic&){};

    string mid_;  // 中缀表达式;
    string last_; // 后缀表达式;
};