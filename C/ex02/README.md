# ex02

This folder contains the source code and exercises for ex02.

## Instructions
Follow the instructions in the corresponding exercise for ex02.

### makefile 解析原理

- ***基本工作原理***
    - **确定目标**，
        - **检查目标文件和依赖文件是否更新**
            - **更新**时**执行该目标下的命令**来生成或更新目标文件
            
- ***隐式规则***
    - **查找相关源文件**
        - **指定目标**：你在 `Makefile` 中定义了 `all: ex02`，意味着 `make` 需要生成 `ex02`。
        - **寻找源文件**：`make` 看到了目标 `ex02`，然后会自动查找与之相关的源文件，即 `ex02.c`。
        - **应用隐式规则**：`make` 根据内置的隐式规则，生成编译命令：
            
            ```bash
            bash
            Copy code
            cc $(CFLAGS) ex02.c -o ex02
            
            ```
            
            在这个过程中，`make` 自动将 `ex02.c` 编译为 `ex02`。