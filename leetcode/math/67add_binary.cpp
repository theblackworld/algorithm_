//rank : 100%;

class Solution {
public:
  string Add(string& a, string& b){
    //这里申请了过多的内存空间，但好处是可以使得整个代码看起来更清爽;
    vector<int> a_vec;
    vector<int> b_vec;
	vector<int> result;
	string str_result;
	
	reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
	
	int step = 0;
	
	//step one: string to int;
	for(int i=0; i<a.size(); i++) a_vec.push_back(static_cast<int>(a[i]-'0'));
	for(int i=0; i<b.size(); i++) b_vec.push_back(static_cast<int>(b[i]-'0'));
    
    //step two: add int; 	
    for(int i=0; i<a_vec.size(); i++){
      if(i < b_vec.size()){  
		result.push_back((a_vec[i]+b_vec[i]+step)%2);
        step = (a_vec[i]+b_vec[i]+step)/2;		
	  }	  
	  else{
		result.push_back((a_vec[i]+step)%2);
        step = (a_vec[i]+step)/2;		
	  } 
    }  	
	  
    if(step == 1){
	  result.push_back(1);	
	}	
	
	//  先申请内存，防止添加过程中的内存分配;
	str_result.resize(result.size());
	
	for(int i=result.size()-1; i>=0; i--){
	  str_result[result.size()-1-i]= static_cast<char>(result[i]+'0'-0);	
	}
	
	return str_result;  
  }
  
  string addBinary(string a, string b) {
  //
    if(a.size() == 0) return b;
    if(b.size() == 0) return a;
	
    int len1 = a.size();
    int len2 = b.size();
	
	if(len1>len2) return Add(a,b);	
    else return Add(b,a);

  }  
  
};