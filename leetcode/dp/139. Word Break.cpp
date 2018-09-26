
/*
  思路： dp
         
		 状态转移方程：dp[i]表示以i为结尾的单词是否符合要求;
		 
		               dp[i] =  true  (dp[j] = true && dict.count(str.substr(j,i-j)));
					   
					            false;
		               
  
  for example:
    
	 leetcode = ["leet", "code"] ;                         return true;
 
     because we can divide the word into leet and code;
	 
     catsandog = ["cats", "dog", "sand", "and", "cat"];    return false; 	   
    
	 we can not divide the word into the world in the worldlist;
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
		
      unordered_set<string> dict;      
	
	  for(auto iter = wordDict.begin(); iter!=wordDict.end(); iter++)	dict.insert(*iter);
		
	  vector<bool> dp(s.size()+1, false);	
	  
	  dp[0] = true;
	  
	  for(unsigned int i=1; i<=s.size(); i++){
		for(unsigned int j=i-1; j>=0; j--){
		  if(dp[j] == true  && wordDict.count(s.substr(j,i-j)) !=0){
			dp[i] = true;  
		  }		
		} 	  
	  }
     
      return dp[s.size()];	 
    }
};


//  上述代码为错误范例：

//  错误在于35行，本身unsigned int在0之后再相减变为40亿，所以导致错误;




