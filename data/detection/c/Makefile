CFLAGS =    # 目前不包含任何编译选项

SOURCES = $(wildcard *.c)   # 找到当前目录所有 .c 文件
OBJECTS = $(SOURCES:%.c=%.o) # 生成相应的 .o 文件
EXECS = $(SOURCES:%.c=%)    # 生成可执行文件名

all: $(EXECS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  # 先编译 .c 文件为 .o

%: %.o
	$(CC) $< -o $@  # 然后链接 .o 文件生成可执行文件

.PHONY: all clean

clean:
	rm -f $(EXECS) $(OBJECTS)