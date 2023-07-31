#include <assert.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

static long long fib[90], sum[90], temp[90], P, Q; // 定义静态数组fib,sum,temp和变量P,Q

// n当前的fib长度 ，P当前有多少个完整的fib
long long fsum(int n, long long P)
{ // 定义一个函数fsum，用来计算数列的一段和
  //  fprintf(stderr, "%d %I64d\n", n, P);
  if (!P) // 如果已经没有完整的fib
    return 0; // 如果P为0，返回0
  if (P == 1) // 
    return 1;                  // 如果P为1，返回1
  assert(P > 0 && P < fib[n]); // 断言P在0和fib[n]之间
  if (P < fib[n - 1])
  {                        // 如果P小于fib[n-1]
    return fsum(n - 1, P); // 递归调用fsum(n-1,P)
  }
  else
  {                                         // 否则
    P -= fib[n - 1];                        // 更新P的值
    return sum[n - 1] + P + fsum(n - 2, P); // 返回sum[n-1]+P+fsum(n-2,P)
  }
}

int fn(int r, int n, long long P)
{ // 定义一个函数fn，用来计算数列的剩余部分和
  if (r <= 0)
    return 0;                                                                         // 如果r小于等于0，返回0
  return P < fib[n + 1] ? fn(r - 1, n - 1, P) : 1 + fn(r - 2, n - 2, P - fib[n + 1]); // 如果P小于fib[n+1]，返回fn(r-1,n-1,P)，否则返回1+fn(r-2,n-2,P-fib[n+1])
}

int main()
{                                  // 定义主函数
  int n, i, r;                     // 定义变量n,i,r+
  freopen("fib.in", "r", stdin);   // 打开文件"fib.in"作为标准输入
  freopen("fib.out", "w", stdout); // 打开文件"fib.out"作为标准输出
  fib[1] = sum[1] = temp[1] = 1;   // 初始化fib[1],sum[1],temp[1]为1
  for (i = 2; i < 90; i++)
  {                                   // 用一个循环计算fib,sum,temp的前90项
    fib[i] = fib[i - 1] + fib[i - 2]; // 计算fib[i]
    sum[i] = fib[i] + temp[i - 2];    // 计算sum[i]
    temp[i] = sum[i] + temp[i - 1];   // 计算temp[i]
  }
  assert(scanf("%lld", &P) == 1); // 从标准输入读取一个正整数P，并断言读取成功
  n = 1;                          // 初始化n为1
  while (n * fib[n] <= P)
  {                  // 用一个循环找到最大的n，使得n * fib[n] <= P
    P -= n * fib[n]; // 更新P的值
    Q += sum[n];     // 更新Q的值
    n++;             // 增加n的值
  }
  r = P % n;       // 计算P除以n的余数r
  P /= n;          // 计算P除以n的商，并更新P的值
  Q += fsum(n, P); // 调用fsum函数，并更新Q的值
  // fprintf(stderr,"%d %d %I64d\n",r,n,P+fib[n+1]);
  Q += fn(r, n, P + fib[n + 1]); // 调用fn函数，并更新Q的值
  printf("%lld\n", Q);           // 把Q的值输出到标准输出

  return 0; // 返回0，表示程序正常结束
};
