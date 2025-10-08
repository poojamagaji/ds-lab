#include <stdio.h>
#include <ctype.h>

char s[100]; int top = -1;
void push(char c){ s[++top]=c; }
char pop(){ return s[top--]; }
int prec(char c){ return c=='^'?3:(c=='*'||c=='/')?2:(c=='+'||c=='-')?1:0; }

int main() {
    char e[]="A+(B*C-(D/E^F)*G)", out[100]; int k=0;
    for(int i=0;e[i];i++){
        char c=e[i];
        if(isalnum(c)) out[k++]=c;
        else if(c=='(') push(c);
        else if(c==')'){ while(s[top]!='(') out[k++]=pop(); top--; }
        else{
            while(top!=-1 && prec(s[top])>=prec(c)) out[k++]=pop();
            push(c);
        }
    }
    while(top!=-1) out[k++]=pop();
    out[k]='\0';
    printf("%s", out);
}
