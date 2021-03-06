#include<stdio.h>
#define SIZE 3  // 几个数全排列（3表示1  2  3）

/**
  这是n个数的全排序问题，利用了深度优先搜索的方法。
  深度优先搜索基本模型为：
  void dfs(int step){
      判断边界
      尝试每一种可能 for(itn i = 0; i < n; i++){
          继续下一步 dfs(step + 1);
      }
      返回
  }
  -------------------------------------------------------
  深度优先搜索是啥：
    这是在图论中用到的，它的思想就是从一个节点出发沿一条路走到底，如果发现不能找到目标，就返回上一个节点，再一条路走到底。
    而此题则是将全排列问题转化为图论问题。
	
*/

int a[10], book[10];  // a是用来存放排列的数据，book是用来标记那些数字使用过

void dfs(int );  // 深度优先搜索的方法

int main()
{
    dfs(0);   // 首先从第0层开始
    return 0;
}

void dfs(int step){
    // 如果这条路已经走到最后了，则打印这个排序
    if(step == SIZE){
        for(int i = 0; i < SIZE; i++)
            printf("%d  ", a[i]);
        printf("\n");
        return;   // 结束函数
    }
    
    for(int i = 0; i < SIZE; i++){
        if(book[i] == 0) // 如果这个节点没被使用过
        {
            a[step] = i + 1;  
            book[i]++;   // 标记表示数字已在使用中
            
            dfs(step + 1);  // 开始进行下一层的查找 
            book[i] = 0;  // 因为for开始进行下一个数字了，可将其视为返回上一层，因此在这之前先将数字设为可用
        }
    }
    
    return;  // 这里的return 也是很重要的，这个return是为了for语句结束而准备的
}
