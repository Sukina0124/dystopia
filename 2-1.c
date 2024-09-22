#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    char goods_type;
    int price;
    int quantity;
} Item;

Item inventory[5][50];
int total_cost = 0;
int current_state = 1;  // 当前状态

void place(char goods_type, int channel, int price, int quantity) {
    if (channel < 1 || channel > 5) {
        printf("通道编号无效，必须在 1 到 5 之间。\n");
        return;
    }
    
    if (price < 0 || quantity < 0) {
        printf("价格和数量必须为非负值。\n");
        return;
    }

    for (int i = 0; i < 50; i++) {
        if (inventory[channel - 1][i].quantity == 0) {
            inventory[channel - 1][i].goods_type = goods_type;
            inventory[channel - 1][i].price = price;
            inventory[channel - 1][i].quantity = quantity;
            printf("摆放货物: %c 在通道 %d，单价 %d，数量 %d\n", goods_type, channel, price, quantity);
            break;
        }
    }
}

void select(char goods_type, int channel, int quantity) {
    if (channel < 1 || channel > 5) {
        printf("通道编号无效，必须在 1 到 5 之间。\n");
        return;
    }
    
    for (int i = 0; i < 50; i++) {
        if (inventory[channel - 1][i].goods_type == goods_type && inventory[channel - 1][i].quantity >= quantity) {
            total_cost += inventory[channel - 1][i].price * quantity;
            inventory[channel - 1][i].quantity -= quantity;
            printf("选择购买: %c 从通道 %d，购买数量 %d\n", goods_type, channel, quantity);
            return;
        }
    }
    printf("通道 %d 中的 %c 货物不足或不存在。\n", channel, goods_type);
}

void pay(int payment) {
    static int total_payment = 0;  // 记录总投币金额
    total_payment += payment;
    printf("投币 %d 元，当前总金额 %d 元，所需金额 %d 元\n", payment, total_payment, total_cost);
    if (total_payment >= total_cost) {
        int change = total_payment - total_cost;
        printf("找零 %d 元\n", change);
        total_payment = 0;  // 重置投币金额
        total_cost = 0;     // 重置总花费
        current_state = 2;
        printf("可继续选择商品\n");
    }
}

int main() {
    char input[100];
    printf("请摆放商品（一个通道只可摆放一种商品，一个通道仅支持一次摆放）\n");
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // 移除换行符
        
        if (strcmp(input, "END") == 0) {
            if (current_state == 1) {
                current_state = 2;  // 完成摆货，进入选择状态
                printf("请选择商品\n");
            }
            else if (current_state == 2) {
                current_state = 3;  // 完成选择，进入投币状态
                printf("总价 %d\n", total_cost);
                printf("请投币\n");
            }
            continue;
        }

        if (current_state == 1) {
            // 摆货
            char goods_type;
            int channel, price, quantity;
            if (sscanf(input, "%c %d %d %d", &goods_type, &channel, &price, &quantity) == 4) {
                sscanf(input, "%c %d %d %d", &goods_type, &channel, &price, &quantity);
                place(goods_type, channel, price, quantity);
            }
            else {
                printf("请输入正确的格式\n");
                continue;
            }
        }
        else if (current_state == 2) {
            // 选择商品
            char goods_type;
            int channel, quantity;
            if (sscanf(input, "%c %d %d", &goods_type, &channel, &quantity) == 3) {
                sscanf(input, "%c %d %d", &goods_type, &channel, &quantity);
                select(goods_type, channel, quantity);
            }
            else {
                printf("请输入正确的格式\n");
                continue;
            }
        }
        else if (current_state == 3) {
            // 投币
            int payment;
            sscanf(input, "%d", &payment);
            if (payment == 1 || payment == 2 || payment == 5) {
                pay(payment);
            }
            else{
                printf("请输入有效硬币\n");
                continue;
            }
                
        }
    }
   
    return 0;
}