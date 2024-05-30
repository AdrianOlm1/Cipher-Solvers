#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define INITIAL_BUFFER_SIZE 100
char* readline() {
    char* buffer = malloc(INITIAL_BUFFER_SIZE);
    if(buffer==NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }
    
    int capacity=INITIAL_BUFFER_SIZE;
    int count =0;
    char input;
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    
    while((input=getchar())!='\n' && input!=EOF) {
        if(count==capacity-1) {
            capacity*=2;
            char* temp=realloc(buffer,capacity);
            if(temp==NULL) {
                perror("Unable to allocate temp");
                free(buffer);
                exit(1);
            }
            buffer = temp;
        }
        buffer[count++]=input;
    }
    buffer[count]='\0';
    
    return buffer;
}

int main() {
    printf("Decrypting or Encrypting (Type D or E)\n");
    char inp;
    scanf(" %c",&inp);
    if(toupper(inp)=='D') {
        printf("Insert your word:\n");
        char* myWord = readline();
        int len = strlen(myWord);
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        
        for(int offset=1;offset<26;++offset) {
            printf("Offset: %d\n", offset);
            for(int i=0;i<len;++i) {
                if(myWord[i]!=' ') {
                    char shifted = myWord[i] + offset;
                    // Ensure wrap-around for uppercase letters
                    if (myWord[i] >= 'A' && myWord[i] <= 'Z' && shifted > 'Z') {
                        shifted -=26;
                    }
                    else if (myWord[i] >= 'a' && myWord[i] <= 'z' && shifted > 'z') {
                        shifted -=26;
                    }
                    printf("%c",shifted);
                }
                
                else {printf(" ");}
            }
            printf("\nPress Enter to continue\n");
            while(getchar() != '\n');
        }
        free(myWord);
    }
    else {
        printf("Insert your word:\n");
        char* myWord = readline();
        int len = strlen(myWord);
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        
        int shift;
        printf("Insert your offset:\n");
        scanf("%d",&shift);
        
        for(int i=0;i<len;++i) {
            if(myWord[i]!=' ') {
                char shifted = myWord[i] + shift;
                    // Ensure wrap-around for uppercase letters
                if (myWord[i] >= 'A' && myWord[i] <= 'Z' && shifted > 'Z') {
                    shifted -=26;
                }
                else if (myWord[i] >= 'A' && myWord[i] <= 'Z' && shifted < 'A') {
                    shifted +=26;
                }
                else if (myWord[i] >= 'a' && myWord[i] <= 'z' && shifted > 'z') {
                    shifted -=26;
                }
                else if (myWord[i] >= 'a' && myWord[i] <= 'z' && shifted < 'a') {
                    shifted +=26;
                }
                printf("%c",toupper(shifted));
              }
            else {printf(" ");}
        }
        free(myWord);
    }
    

    return 0;
}


