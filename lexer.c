#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

static const char* keywords[] = {
            "auto",     "break",    "case",     "char",
            "const",    "continue", "default",  "do",
            "double",   "else",     "enum",     "extern",
            "float",    "for",      "goto",     "if",
            "int",      "long",     "register", "return",
            "short",    "signed",   "sizeof",   "static",
            "struct",   "switch",   "typedef",  "union",
            "unsigned", "void",     "volatile", "while" 
};

static const char operators[] = {'/', '+', '*', '-', '%', '=', '<', '>', '~', '&', ',', '!', '^', '|'};
static const char specialCharacters[] = ";{}()[]";


int validate(int argc,char *argv[])
{
    if(argc!=2)
        return 0;
    char *ch;
    if(ch=strstr(argv[1],".c"))
    {
        if(strcmp(ch,".c")==0)
        {
            printf("Valid arguments\n");
            return 1;
        }
    }
        return 0;
}

void lexicalAnalyzer(FILE *fptr)
{
    int i=0;
    char ch,buffer[60];
    while (fscanf(fptr, "%c", &ch) == 1)
    {
        if(ch=='#')
        {
            while(ch!='\n')
            {
                buffer[i++]=ch;
                fscanf(fptr, "%c", &ch);
            }
            buffer[i]='\0';
            printf("PREPROCESSOR DIRECTIVE-->%s\n",buffer);
            i=0;
        }
        else if(ch=='/')
        {
            char t_ch;
            fscanf(fptr, "%c", &t_ch);
            if (t_ch == '/')
            {
                buffer[i++] = '/';
                while (ch != '\n')
                {
                    buffer[i++] = ch;
                    fscanf(fptr, "%c", &ch);   
                }
                buffer[i]='\0';
                printf("SINGLE LINE COMMENTS-->%s\n",buffer);
                i=0;
            }
            else if(t_ch=='*')
            {
                buffer[i++] = '/';
                ch=t_ch;
                while (ch != '/')
                {
                    buffer[i++] = ch;
                    fscanf(fptr, "%c", &ch);   
                }
                buffer[i++] = '/';
                buffer[i]='\0';
                printf("MULTI LINE COMMENTS-->%s\n",buffer);
                i=0;
                continue;
            }
            else
            {
                fseek(fptr,-1,SEEK_CUR);
            }
        }

        if(delim(ch))
        {
            if(i!=0)
            {
                buffer[i]='\0';
                if(isKeyword(buffer))
                {
                    printf("KEYWORD-->%s\n",buffer);
                }
                else if(isIdentifier(buffer))
                {
                    printf("IDENTIFIER-->%s\n",buffer);
                }
                else if(isConstant(buffer))
                {
                    printf("CONSTANT-->%s\n",buffer);
                }
                else
                {
                    printf("UNIDENTIFIED->%s\n",buffer);
                }
                i=0;
            }
            if(isOperator(ch))
            {
                printf("OPERATOR-->%c\n",ch);
            }
            else if(isSpecialCharacter(ch))
            {
                printf("SPECIAL CHARACTER-->%c\n",ch);
            }
        }
        else
        {
            buffer[i++]=ch;
        }
    }
}

int delim(char ch)
{
    if(ch == ' ' || ch == '+' || ch == '-'|| ch == '*' || ch == '/' || ch == ','|| ch=='"'
        || ch == ';' || ch == '%' || ch == '>'|| ch == '<' || ch == '=' || ch == '('
        || ch == ')' || ch == '[' || ch == ']'|| ch == '{' || ch == '}' || ch=='\n' || ch=='&')
        {
            return 1;
        }
        else
        { 
            return 0;
        }
}

int isOperator(const char ch)
{
    int i=0;
    while(operators[i])
    {
        if(ch==operators[i])
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int isKeyword(const char* str)
{
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) {
       if (strcmp(str, keywords[i]) == 0) {
           return 1;
       }
   }
   return 0;
}

int isIdentifier(const char* str)
{
    if(str[0]>='0' && str[0]<='9')
        return 0;
    return 1;
}

int isConstant(const char* str)
{
    int i=0;
    while (str[i])
    {
        if(isdigit(str[i]))
            i++;
        else
            return 0;
    }
    return 1;
}

int isSpecialCharacter(char ch)
{
    int i=0;
    while(specialCharacters[i])
    {
        if(ch==specialCharacters[i])
        {
            return 1;
        }
        i++;
    }
    return 0;
}

