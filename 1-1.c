#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char item = 0;
	int channel = 0;
	int price = 0;
	int number = 0;
	printf("欢迎使用售货机\n");
	printf("请输入货物种类、货物所在的通道标号、货物单价以及货物个数\n");
	scanf("%c %d %d %d", &item, &channel, &price, &number);
	printf("放入成功\n");
	printf("%d: ", channel);
	for (int i = 0; i < number; i++)
	{
		printf("%c", item);
	}
	printf(" %d\n", price);
	system("pause");
	return 0;
}
