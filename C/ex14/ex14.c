#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 打印字符串的字符，只处理指定长度的字符串
void print_letters(const char str[], int length) {
    for (int i = 0; i < length; i++) {
        char ch = str[i];

        // 只打印字母或空白字符
        if (isalpha(ch) || isblank(ch)) {
            printf("'%c' == %d\n", ch, ch);
        }
    }
}

// 打印每个传入参数的字符
void print_arguments(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        int length = strlen(argv[i]); // 使用strlen来获取字符串的长度
        print_letters(argv[i], length);
    }
}

int main(int argc, char *argv[]) {
    print_arguments(argc, argv);
    return 0;
}
