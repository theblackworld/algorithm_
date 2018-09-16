//rank : 98.9%
class Solution {
public:
    int Add(int num){
	  int result = 0; 
      while(num/10!=0){  
	    result += num%10;
      	num = num/10;    
	  }	
	  result+= num; 
	  return result;	
	}
	int addDigits(int num) {
      while(num>=10){
		num = Add(num);  
	  } 
	  return num; 
    }
};