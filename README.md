# c_complier
2020年南开大学软件学院编译原理大作业
## 运行方式
1. 进入项目目录在终端输入`make`指令
2. 在linux系统下，`make`之后会得到可执行文件scanner_parser_test  
在mac下则会出现问题，此时需要在`parser.tab.h`文件的前两行输入一下代码：  
`#include "abstract_syntax_tree/AstNode.h`  
`#include "symbol_table/symbol.h` 
`#include "intermidiate_code/interCode.h`
`#include "asm/AsmCode.h`
`#include "asm/AsmGenerate.cpp"`  保存后在终端输入命令:   
`g++ -o scanner_parser_test AstNode.o symbol.o interCode.o AsmGenerate.o parser.tab.c scanner.lex.c`  
3. 执行`scanner_parser_test`，若没有参数则会读取标准终端输入；  
或者提供文件路径来读取文件的内容，对文件进行词法、语法分析,以及中间代码、汇编语言的生成；
4. 注意`make clean`后再进行编译执行；  
5. 注意，数组名和变量名不应该冲突；
## 目前的进度
1. 已经完成词法分析、语法分析的基础部分以及加分项中的：函数调用、一维数组和一维指针； 
2. 完成语法树的建立
3. 完成中间代码基础部分的生成，以及符号表对已声明变量的关键信息的存储
5. 完成基本四则运算的汇编生成，并可以正确执行；
4. WZX正在搞一维数组和一维指针的中间代码和类型检查；ZLY在做控制流语句的汇编生成；
5. XHY在做代码优化；等待MLX考完试后回归开发，预计同ZLY一起完成控制流、数组和指针的汇编代码生成；


## 安排
##  整一个编译器，冲！！！
##  Success is in sight！！！

# To Be Continued...
