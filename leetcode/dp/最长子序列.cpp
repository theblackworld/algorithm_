// 最长子序列的问题转化为dp问题, 因为存在两个字串之间的比较问题，自然而然想到的是二维dp

// 首先我们需要理解dp[i][j]这个状态本身的意义：代表以0起始长度为i的字串str1 与以0起始长度为j的str2最长公共子序列的长度;


// 从而确定状态转移方程：

/*        

    dp[i][j] =  dp[i-1][j-1] + 1   (if(str1[i] == str2[j]) && j>=1)
  
                max(dp[i-1][j], dp[i][j-1]) (if(str1[i] != str2[j]) && j>=1)

					
    max(dp[i-1][j], dp[i][j-1])//之所以这样写无非因为，当不等的时候字串1需要回退或者字串2回退;
	
*/

//question one: find the max size ;
int  FindTheSameOrder(string& str1, string& str2){
	
   if(str1.size() == 0 || str2.size() == 0) return;	
	
   int len1 = str1.size(), len2 = str2.size();	
	
   vector<int> dp(len1+1, vector<int>(len2+1,0));

   for(int i=0; i<=len1; i++) dp[i][0] = 0; 
	   
   for(int j=0; j<=len2; j++)  dp[0][j] = 0;
	     
   for(int i=1; i<=len1; i++){
	 for(int j=1; j<=len2; j++){
	   if(str[i] == str[j]){
		 dp[i][j] = dp[i-1][j-1]+1;  
	   }
       else{
		 dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
	   }	   
	 }  
   }
   
   return dp[len1][len2];		
}


// question two: find the all the max len sub string;
int  FindTheSameOrder(string& str1, string& str2){
	
   if(str1.size() == 0 || str2.size() == 0) return;	
	
   int len1 = str1.size(), len2 = str2.size();	
	
   vector<int> dp(len1+1, vector<int>(len2+1,0));

   for(int i=0; i<=len1; i++) dp[i][0] = 0; 
	   
   for(int j=0; j<=len2; j++)  dp[0][j] = 0;
	     
   for(int i=1; i<=len1; i++){
	 for(int j=1; j<=len2; j++){
	   if(str[i] == str[j]){
		 dp[i][j] = dp[i-1][j-1]+1;  
	   }
       else{
		 dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
	   }	   
	 }  
   }
   
   for(int i=0)   


   
}



// find the max sub string 
string FindTheSameOrderString(string& str1, string& str2){
	
   if(str1.size() == 0 || str2.size() == 0) return;	
	
   int len1 = str1.size(), len2 = str2.size();	
	
   vector<int> dp(len1+1, vector<int>(len2+1,0));

   for(int i=0; i<=len1; i++) dp[i][0] = 0; 
   
   for(int j=0; j<=len2; j++)  dp[0][j] = 0;	
}
