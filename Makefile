scanner_parser_test: scanner.l parser.y ./abstract_syntax_tree/AstNode.cpp
					g++ -c ./abstract_syntax_tree/AstNode.cpp
					bison -d parser.y
					flex -oscanner.lex.c scanner.l
					# sed -i "" "1i\#include \"./abstract_syntax_tree/AstNode.h\"" parser.tab.h
					# g++ -o scanner_parser_test AstNode.o parser.tab.c scanner.lex.c
clean:
		rm *.c *.h *.o scanner_parser_test
