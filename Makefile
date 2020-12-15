scanner_parser_test: scanner.l parser.y ./abstract_syntax_tree/AstNode.cpp ./symbol_table/symbol.cpp ./intermidiate_code/interCode.cpp
					g++ -c ./abstract_syntax_tree/AstNode.cpp
					g++ -c ./symbol_table/symbol.cpp
					g++ -c ./intermidiate_code/interCode.cpp
					bison -d parser.y
					flex -oscanner.lex.c scanner.l
					sed -i  "1i\#include \"./abstract_syntax_tree/AstNode.h\"" parser.tab.h
					sed -i  "2i\#include \"./symbol_table/symbol.h\"" parser.tab.h
					sed -i  "3i\#include \"./intermidiate_code/interCode.h\"" parser.tab.h
					g++ -o scanner_parser_test AstNode.o symbol.o interCode.o parser.tab.c scanner.lex.c
clean:
		rm  *.tab.c  *.lex.c  *.h  *.o scanner_parser_test
