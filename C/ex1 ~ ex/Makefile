# 定义编译选项
CFLAGS = -Wall -g

# 定义编译器
CC = gcc

# 定义目标文件名
TARGET = ex1

# 默认目标，依赖于 $(TARGET)
all: $(TARGET)

# 生成可执行文件的规则
$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o

# 编译源文件生成目标文件的规则
$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -c $(TARGET).c -o $(TARGET).o

# 清理生成文件的规则
clean:
	rm -f $(TARGET) $(TARGET).o

# 声明伪目标，避免与实际文件名冲突
.PHONY: all clean
