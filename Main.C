#include <stdio.h>
#include <windows.h>

/*
[背包问题]有一个背包，背包容量是M=150。有7个物品，物品可以分割成任意大小。

要求尽可能让装入背包中的物品总价值最大，但不能超过总容量。

物品 A  B  C  D  E  F  G

重量 35 30 60 50 40 10 25

价值 10 40 30 50 35 40 30

记得当时学算法的时候，就是这个例子，可以说很经典。

*/
#define limit 150//限制150KG

int m[] = { 10,25,30,35,40,50,60 };//我这里需要把数据排序好
int valuelist[] = { 40,30,40,10,35,50,30 };//每个kg的物品对应的价值 要对应好
int maxValue = 0;
//从数组中寻找对应的值的索引
int findIndex(int *num, int count, int value)
{
	for (size_t i = 0; i < count; i++)
	{
		if (num[i] == value)
		{
			return i;
		}
	}
}
int print(int *m, int j, int total,int *k,int p)
{
	int ret;
	int flag = 0;
	int totalValue = 0;
	for (size_t i = 0; i < 7; i++)
	{
		if (total + m[i] > limit )
		{
			if (i == 0)//不是下一个函数进来的 只有下一个函数进来后第一次循环才输出
			{
				int value=0;
				for (size_t iz = 0; iz < p ; iz++)
				{
					//打印出值
					printf("%dkg ", k[iz]);
					value += valuelist[findIndex(m,7,k[iz])];//找到值对应的价值加起来
				}
					if (value > maxValue)
					{
						maxValue = value;
					}
				printf("TotalValue:%d\n",value);
			}
			return 1;	//满了
		}
		else
		{
			k[p] = m[i];
			print(m, i, total+m[i],k,p+1);
		}
	}
}
int main()
{
	int k[100] = { 0 };//记录的是值 
	print(m, 0, 0, k, 0);
	printf("%d", maxValue);
    return 0;
}
