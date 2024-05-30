#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Encrypt(char text[], char key[],char final[]) {
    int length = strlen(text);
    int kLen=strlen(key);
    
    for(int i=0;i<length;++i) {
        if((text[i]<'A'||text[i]>'Z')&&(text[i]<'a'||text[i]>'z')) {final[i]=text[i];}
        else {
            int a=toupper(text[i])-'A';
            int b=toupper(key[i%kLen])-'A';
            char letter = ((a+b)%26)+'A';
            //printf("%c + %c = %c\n",text[i],key[i%3],letter);
            final[i]=letter;
        }
    }
    final[length]='\0';
    
    printf("%s\n",final);
}

void Decrypt(char text[],char key[]) {
    int length=strlen(text);
    int kLen=strlen(key);
    char final[length+1];
    
    for(int i=0;i<length;++i) {
        if((text[i]<'A'||text[i]>'Z')&&(text[i]<'a'||text[i]>'z')) {final[i]=text[i];}
        else {
            int a=toupper(text[i])-'A';
            int b=toupper(key[i%kLen])-'A';
            char letter = ((a - b + 26) % 26) + 'A';
            //printf("%c + %c = %c\n",text[i],key[i%3],letter);
            final[i]=letter;
        }
    }
    
    final[length]='\0';
    printf("%s\n",final);
}


int main() {
    
    char text[]="HELLO DAD I LIKE TO EAT PIZZA";
    char key[]="ABC";
    char final[strlen(text)+1];
    
    Encrypt(text,key,final);
    Decrypt(final,key);
    

    return 0;
}







