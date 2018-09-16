//rank 63.94;
class Solution {
public:
    string Add(string& a, string& b){
	  string result;
	  
	  vector<int> a_vec(a.size(), 0);	
	  vector<int> b_vec(b.size(), 0);		 
	  
      //正好把数给反过来存放了;	  
      for(int i=0; i<a.size(); i++) a_vec[a.size()-1-i] = static_cast<int>(a[i] - '0');  
	  for(int i=0; i<b.size(); i++) b_vec[b.size()-1-i] = static_cast<int>(b[i] - '0');
	  
	  int add = 0;
	  for(int i=0; i<a_vec.size(); i++){
		if(i<b_vec.size()){	
		  result.push_back(static_cast<char>((a_vec[i] + b_vec[i]+add)%10 + '0'-0));
          add = (a_vec[i] + b_vec[i]+add)/10;		  
		}  
		else{
		  result.push_back(static_cast<char>((a_vec[i]+add)%10 + '0'-0));
          add = (a_vec[i]+add)/10;	
		}  
	  }
	  
	  if(add!=0){
		result.push_back(static_cast<char>(add + '0'-0));  
	  }
	  
	  reverse(result.begin(), result.end());
	  return result;	
	}
    string addStrings(string num1, string num2) {
      if(num1.size() == 0) return num2;  
	  if(num2.size() == 0) return num1;
      if(num1[0] == '0') return num2;	  
      if(num2[0] == '0') return num1;	  
      
	  if(num1.size() > num2.size()) return Add(num1, num2); 
	  else return Add(num2, num1);
	}
};