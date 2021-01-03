scanner_parser_test: scanner.l parser.y ./abstract_syntax_tree/AstNode.cpp ./symbol_table/symbol.cpp ./intermidiate_code/interCode.cpp ./asm/AsmGenerate.cpp ./asm/asm_io.asm
					g++ -c ./abstract_syntax_tree/AstNode.cpp ./symbol_table/symbol.cpp ./symbol_table/symbol.cpp ./intermidiate_code/interCode.cpp
					g++ -c -g ./asm/AsmGenerate.cpp
				

					bison -d parser.y
					flex -oscanner.lex.c scanner.l

					
					sed -i  "1i\#include \"./abstract_syntax_tree/AstNode.h\"" parser.tab.h
					sed -i  "2i\#include \"./symbol_table/symbol.h\"" parser.tab.h
					sed -i  "3i\#include \"./intermidiate_code/interCode.h\"" parser.tab.h
					sed -i  "4i\#include \"./asm/AsmGenerate.h\"" parser.tab.h
					g++ -o scanner_parser_test AstNode.o symbol.o interCode.o AsmGenerate.o parser.tab.c scanner.lex.c
					./scanner_parser_test test1.c
					nasm -g -f elf -d ELF_TYPE ./asm/asm_io.asm -o ./asm/asm_io.o
					gcc -g -m32 ./asm/asm_io.o -o test
					./test

					
clean:
		rm  *.tab.c  *.lex.c  *.h  *.o scanner_parser_test ./asm/*.o ./test
