排序算法:

1。 冒泡排序:
##  排序的稳定性定义：假定在待排序的记录序列中，存在多个具有相同的关键字的记录，若经过排序，
##  这些记录的相对次序保持不变，即在原序列中，r[i]=r[j]，且r[i]在r[j]之前，而在排序后的序列中，
##  r[i]仍在r[j]之前，则称这种排序算法是稳定的；否则称为不稳定的。

//  bubble排序原理： 每次把最后最小的数字通过两两之间比较移动到最后或者移动到最前方;
//  复杂度:  最差： (o(n2))， 最优： o(n2);
//  稳定性： 稳定因为比较是在连续位置上两两之间进行比较, 所以相对位置到最后也一定是稳定的，并且你找不到任何反例; 

#******

//这里定义的函数后面直接引用;
int Compare(const void* a,const void* b){
  return *(int*)a - *(int*)b;
}

typedef int(*Cmp)(const void* ,const void*);

//后向冒;
template<class T>
void Bubble(T* array, int size, Cmp cmp = Compare){
	
  if(array  == nullptr || size <=0) return ;

  for(int i=0; i<size; i++){
	for(int j=0; j<size-1-i; j++){
	  if(cmp(array[j],array[j+1]) >0 ){ //这样是从小到大排序;
		swap(array[j],array[j+1]); 
	  }	
	}     
  } 
}

//前向冒;
template<class T>
void Bubble(T* array, int size ,Cmp cmp = Compare){
	
   if(array == nullptr || size<0) return ;

   for(int i=0; i<size; i++){
	 for(int j=size=1; j>=i; j--){
		if(cmp(array[j+1],array[j])){
		  swap(array[j+1], array[j]);	
		}  
	 }   
   }  	
}



2. 简单选择排序:

//  简单选择排序原理： 在每一轮中找到最小的数，并且和当轮起始位置替换,有人说这不和冒泡差不多么，但其实这个排序算法
//  每次比较的数是当前起始位置的数, 并且始终保证起始位置的数是最值; 
//  复杂度:  最差： (o(n2))， 最优： o(n2);
//  稳定性： 不稳定：比如 3 3 7 5 4 8 9 ; 根据定义第一轮为9 3 7 5 4 8 3,前后3 3 的相对位置发生改变; 
template<class T>
void SimpleSort(T* array, int size, Cmp cmp = Compare){
	
  if( T == nullptr || size<=0 ) return ;	
	
  int index = 0;
  
  for(int i=0; i<size; i++){
	  
	index = i;

    for(int j=i+1; j<size; j++){
	  if(cmp(array[j], index) >= 0){
	    index = j;  
	  }			
	}		
    swap(array[i],array[index]);	
  }	 	
  
}



3.  堆排序;

//  堆排序原理：首先利用堆排序需要构建堆，然后利用堆的性质, 对于每一个数只需要比较lgn（完全二叉树的深度）即可找到相应的位置;
//  复杂度：最好： o(nlgn)， 最坏: o(nlgn);
//  稳定性：不稳定;   


//index从零开始:
template<class T>
void HeapAdjust(T* array, int start, int end, Cmp cmp = Compare){
  
  int temp = array[start], i = 0;   
 	
  for(i=start*2+1; i<end; i=i*2+1){
	  
	if(i < end-1 && cmp(array[i], array[i+1])) i++;  
	  
	if(cmp(array[i], temp)) break;
    //这块可以好好体会;
    array[start] = array[i]; 	
  
    start = i;
  }	
  
  swap(temp,array[start]); 	
}

template<class T>
void CreateHeap(T* array, int size, Cmp cmp = Compare){
   for(int i = size/2; i>=0; i++){
	 HeapAdjust(T, i, end, cmp);  
   }	
}


template<class T>
void HeapSort(T* array, int size, Cmp cmp = Compare){
	
  CreateHeap(array, size);
  //构建好之后;
  for(int i=size-1; i>=0; i++){
	  
	swap(array[0], array[i]); //把最值移动到最后;

    HeapAdjust(array, 0 , i-1;)		  

  }  	
}

















































