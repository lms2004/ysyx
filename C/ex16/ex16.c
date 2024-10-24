#include <stdio.h>
#include <string.h>

// 定义结构体Person
struct Person {
    char name[50];  // 用字符数组代替指针避免动态分配内存
    int age;
    int height;
    int weight;
};

// 创建结构体的函数，使用栈而不是堆分配
struct Person Person_create(char *name, int age, int height, int weight) {
    struct Person who;

    // 复制字符串到结构体中
    strncpy(who.name, name, sizeof(who.name) - 1);
    who.name[sizeof(who.name) - 1] = '\0';  // 确保字符串以NULL结尾
    who.age = age;
    who.height = height;
    who.weight = weight;

    return who;  // 返回结构体
}

// 打印结构体信息的函数
void Person_print(struct Person who) {
    printf("Name: %s\n", who.name);
    printf("\tAge: %d\n", who.age);
    printf("\tHeight: %d\n", who.height);
    printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[]) {
    // 直接在栈上创建两个结构体变量
    struct Person joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person frank = Person_create("Frank Blank", 20, 72, 180);

    // 打印结构体信息
    printf("Joe is at memory location %p:\n", (void*)&joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", (void*)&frank);
    Person_print(frank);

    // 修改结构体的值
    joe.age += 20;
    joe.height -= 2;
    joe.weight += 40;
    Person_print(joe);

    frank.age += 20;
    frank.weight += 20;
    Person_print(frank);

    // 不需要销毁，因为栈上的内存会自动回收
    return 0;
}
