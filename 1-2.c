#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int sum = 0, need, change, input;
	printf("请输入总价\n");
	scanf("%d", &need);
	printf("请输入投币金额（只接收1元，2元和5元）\n");
	while(sum < need)
	{
		scanf("%d", &input);
		if(input != 1 && input != 2 && input != 5)
		{
			printf("请输入有效金额\n");
			continue;
		}
		sum += input;
	}
	printf("共投入%d元\n", sum);
	printf("找您%d元\n", sum - need);
	system("pause");
	return 0;
}