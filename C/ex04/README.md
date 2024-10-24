# ex04

This folder contains the source code and exercises for ex04.

## Instructions
Follow the instructions in the corresponding exercise for ex04.
- ***未初始化值定位分析***
    - ***Valgrind 报告摘录***
        
        ```bash
        ==388462== Conditional jump or move depends on uninitialised value(s)
        ==388462==    at 0x48DEAD6: __vfprintf_internal (vfprintf-internal.c:1516)
        ==388462==    by 0x48C879E: printf (printf.c:33)
        ==388462==    by 0x1091E7: main (no_segfault_ex.c:8)
        ==388462==  Uninitialised value was created by a stack allocation
        ==388462==    at 0x109169: main (no_segfault_ex.c:2)
        
        ```
        
    - ***代码：***
        
        ```c
        #include <stdio.h>int main() {
            int a[5] = {1, 2, 3, 4, 5};
            unsigned total = 0;
            for (int j = 0; j < sizeof(a); j++) {
                total += a[j];
            }
            printf("sum of array is %d\n", total);
        }
        
        ```
        
    - ***具体分析***
        
        1. **跳转或操作依赖未初始化值** （第8行 `printf`）
        
        Valgrind 报告说程序在第8行的 `printf` 函数中依赖于未初始化的值。
        
        ```c
        printf("sum of array is %d\n", total);
        ```
        
        - **分析**：`printf` 依赖变量 `total`，因此问题可能是 `total` 依赖了未初始化的值（尽管 `total` 本身已经被初始化为 `0`，但它在循环中可能积累了未初始化的值）。
        
        2. **未初始化值在栈上创建** （第2行 `main`）
        
        Valgrind 提示未初始化值是在第2行的 `main` 函数中通过栈分配创建的：
        
        ```c
        int a[5] = {1, 2, 3, 4, 5};
        unsigned total = 0;
        ```
        
        - **分析**：在 `main` 函数开始时，栈上分配了局部变量 `a` 和 `total`。其中，`total` 已经初始化为 `0`，问题可能出在数组 `a` 的使用上。
        - **推测**：由于 `total` 已经被初始化，问题很可能是因为对数组 `a` 进行了越界访问，导致 `total` 在循环中累积了未初始化的内存值。
        
        ---