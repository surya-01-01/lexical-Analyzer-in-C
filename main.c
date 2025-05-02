#include <stdio.h>
#include "lexer.h"
#include"lexer.c"

int main(int argc, char *argv[]) {

    if(validate(argc,argv))
    {
        FILE *fptr=NULL;
        fptr=fopen(argv[1],"r");
        if(fptr==NULL)
        {
            printf("Unable to open the %s file\n",argv[1]);
            return 1;
        }
        lexicalAnalyzer(fptr);
    }
    else
    {
        printf("Invalid Arguments\n");
        return 1;
    }

    return 0;
}
