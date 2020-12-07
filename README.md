# c_complier
2020年南开大学软件学院编译原理大作业
## 运行方式
1. 进入项目目录在终端输入`make`指令
2. 在linux系统下，`make`之后会得到可执行文件scanner_parser_test  
在mac下则会出现问题，此时需要在`parser.tab.h`文件的前两行输入一下代码：  
`#include "abstract_syntax_tree/AstNode.h`  
`#include "symbol_table/symbol.h`  
保存后在终端输入命令：`g++ -o scanner_parser_test AstNode.o symbol.o parser.tab.c scanner.lex.c`  
3. 执行`scanner_parser_test`，若没有参数则会读取标准终端输入；  
或者提供文件路径来读取文件的内容，对文件进行词法、语法分析；
4. 注意`make clean`后再进行编译执行；  
## 目前的进度
1. 已经完成词法分析、语法分析的基础部分以及加分项中的：函数调用、一维数组和一维指针； 
2. 完成语法树的建立以及用符号表来解决重定义问题； 
## 安排
1. 复习git使用和github协作方法；
2. 积极学习了解后续开发任务；
##  整一个编译器，冲！！！

# To Be Continued...
