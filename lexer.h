#ifndef LEXER_H
#define LEXER_H


int validate(int argc,char *argv[]);

void lexicalAnalyzer(FILE *fptr);

int delim(char ch);

int isOperator(const char ch);

int isKeyword(const char* str);

int isConstant(const char* str);

int isIdentifier(const char* str);

int isSpecialCharacter(char ch);


// void initializeLexer(const char* filename);
// Token getNextToken();
// void categorizeToken(Token* token);
// int isKeyword(const char* str);
// int isOperator(const char* str);
// int isSpecialCharacter(char ch);
// int isConstant(const char* str);
// int isIdentifier(const char* str);

#endif
