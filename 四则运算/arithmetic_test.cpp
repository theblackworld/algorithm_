#include<iostream>
#include<vector>
#include"arithmetic"
using namespace std;
vector<string> testInput = {"900+30*(30-10)*3+40/2","100+(220*2+30)-90", "20*30*40", "((40+5)*(20+5))-10"};
vector<int>    testOutput = {2720, 480, 24000, 1115};
int main(){
	
  Arithmetic a(" ");
 	
  cout<< "total test example is" << testInput.size() << endl; 	
  
  for(int i=0; i<testInput.size(); i++){
	
	a.Reset(testInput[i]);
	
	if(a.Calculate() != testOutput[i]){
	  cout<<"test:"<<i<<":deos not passed: ";	
	  cout<<"the fail testInput is:"<<testInput[i]<<"&&"<<"the fail testInput is:"<<testOutput[i]<<endl;	
	}  
  }
	
  return 0;	
}