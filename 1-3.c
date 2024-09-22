#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
char item;
int channel, price, number;
char nitem;
int nchannel, n, nprice, sum, input;

void buy()
{
	sum = 0;
	printf("请输入货物种类、通道标号、需要货物数量：\n");
	scanf(" %c %d %d", &nitem, &nchannel, &n);
	if (nitem != item || nchannel != channel)
	{
		printf("请输入正确的货物种类与通道标号！\n");
		scanf(" %c %d %d", &nitem, &nchannel, &n);
	}
	if (nitem == item && nchannel == channel && n > number)
	{
		printf("库存不足，请调整需求数目\n");
		scanf(" %c %d %d", &nitem, &nchannel, &n);
	}
	nprice = price * n;
	printf("请投硬币\n");
	while (sum < nprice)
	{
		scanf(" %d", &input);
		if (input != 1 && input != 2 && input != 5)
		{
			printf("请输入有效硬币\n");
			continue;
		}
		sum += input;
	}
	number -= n;
	printf("找零：%d\n", sum - nprice);
}
int main()
{
	printf("请输入放入货物种类、通道标号、单价以及货物个数：\n");
	scanf(" %c %d %d %d", &item, &channel, &price, &number);
	while (number != 0)
	{
		buy();
	}
	printf("已无存货\n");
	system("pause");
	return 0;
}

