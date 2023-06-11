#include <stdio.h>

int main() {
    char c;
    int parentheses = 0;
    int braces = 0;
    int brackets = 0;

    while ((c = getchar()) != EOF) {
        if (c == '(') {
            parentheses++;
        } else if (c == ')') {
            parentheses--;
        } else if (c == '{') {
            braces++;
        } else if (c == '}') {
            braces--;
        } else if (c == '[') {
            brackets++;
        } else if (c == ']') {
            brackets--;
        }
    }

    if (parentheses == 0 && braces == 0 && brackets == 0) {
        printf("All parentheses, braces, and brackets are correctly matched and balanced.\n");
    } else {
        printf("The parentheses, braces, and/or brackets are not correctly matched and balanced.\n");
    }

    return 0;
}


// check of All parentheses, braces, and brackets are correctly matched and balanced

void main()
{
    int ch;  
    int parenthes = 0 ;
    int braces = 0 ;
    int barckets = 0;

    while(ch =  getchar() != EOF) {
        switch (ch)
        {
        case '('/* constant-expression */:
            parenthes++;
            /* code */
            break;
        
        case ')'/* constant-expression */:
            parenthes--;
            /* code */
            break;

        case '{'/* constant-expression */:
            braces++;
            /* code */
            break;

        case '}'/* constant-expression */:
            braces--;
            /* code */
            break;

        
        default:
            break;
        }


    }



}





