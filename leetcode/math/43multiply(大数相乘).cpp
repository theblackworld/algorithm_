// rank: 28.07;
// 可以想下哪里可以优化;
class Solution {
public:
    string multiply(string num1, string num2) {
	  string result;
	  
	  if(num1.size() == 0 || num2.size() == 0) return result;
	  
	  if(num1[0] == '0' || num2[0] == '0') return "0";
	  
	  int len1 = num1.size();
	  int len2 = num2.size();
	 
        
	  vector<int> result_vec(len1+len2,0);
	  
	  //step one: 记录每个指定位置的相乘的结果;
	  for(int i=0; i<len1; i++){
	    for(int j=0; j<len2; j++){
	      result_vec[len1+len2-2-(i+j)] += (static_cast<int>(num1[i]-'0'))*(static_cast<int>(num2[j]-'0'));	 		
	    }    
	  }
	    
	  int add = 0;
	  int t = 0;
	  //step two: 做进位处理;
	  for(int i=0; i<=len1+len2-2; i++){
	     t = (result_vec[i]+add)%10;
             add = (result_vec[i]+add)/10;		
             result_vec[i] = t;  
	  }
	   
	  if(add != 0){
	    result_vec[len1+len2-1] = add;	  
	    result.resize(len1+len2);
            for(int i=len1+len2-1; i>=0; i--){
	      result[len1+len2-1-i] = static_cast<char>(result_vec[i]+'0'-0);	
	    }
	  } 
	  else{
	    result.resize(len1+len2-1); 
            for(int i=len1+len2-2; i>=0; i--){
	      result[len1+len2-2-i] = static_cast<char>(result_vec[i]+'0'-0);	
	    }		
	  } 
	  return result;
    }
};
