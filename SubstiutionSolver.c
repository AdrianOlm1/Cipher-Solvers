// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct {
    char letter;
    double frequency;
    double percent;
} LetterFrequency;

int compare(const void *a, const void *b) {
    const LetterFrequency *letterA = (const LetterFrequency *)a;
    const LetterFrequency *letterB = (const LetterFrequency *)b;

    // Compare by frequency (descending)
    if (letterB->percent > letterA->percent) return 1;
    if (letterB->percent < letterA->percent) return -1;
    
    // Then by letter (ascending)
    return (letterA->letter - letterB->letter);
}


void SubSolver(char myString[],char myKey[]) {
    // Creates the full key
    int keyNum=strlen(myKey);
    int count=0;
    char translate[27];
    char last=myKey[keyNum-1];
    memcpy(translate,myKey,keyNum);
    for(int i=0;i<26;++i) {
        char letter=last + i;
        if(letter>'Z') {letter-=26;}
        for(int j=0;j<keyNum;++j) {
            if(letter==myKey[j]) {break;}// Checks if letter is already in key
            if(j==keyNum-1) {translate[keyNum+count]=letter;count++;}
        }
    }

    translate[26]='\0';
    //printf("\n%s\n",translate);
    
    // Substitutes
    int num=strlen(myString);
    for(int i=0;i<num;++i){
        char letter=myString[i];
        if(letter!=' ') {
            for(int j=0;j<26;++j) {
                if(letter==translate[j]) {printf("%c",'a'+j);}
            }
        }
    }
}
 void AlphaSolver(char myString[]) {
    int num=strlen(myString);
    char old;
    char inp;
    
    printf("\nInsert you wish to replace: ");
    scanf("%c",&old);
    while((getchar()) != '\n');
    
    printf("Insert you wish to replace with: ");
    scanf("%c",&inp);
    while((getchar()) != '\n');
    
    while(1) {
        for(int i=0;i<num;++i) {
            if(myString[i]==toupper(old)) {myString[i]=tolower(inp);}
        }
        for(int i=0;i<num;++i) {
            if(myString[i]>='a'&&myString[i]<='z') {
                printf(ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET, myString[i]);
            }
            else if(myString[i]>='A'&&myString[i]<='Z') {
                printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET, myString[i]);
            }
            else {printf("%c",myString[i]);}
        }
        //printf("%s\n",myString);
        
        printf("\nInsert you wish to replace: ");
        scanf("%c",&old);
        while((getchar()) != '\n');
        if(old=='\n') {return;}
        
        printf("Insert you wish to replace with: ");
        scanf("%c",&inp);
        while((getchar()) != '\n');
    }
}

/*void AutoSolver(char *myString) {
    // Map each letter to its rank
    int ranks[26] = {
        3,  // A
        20, // B
        12, // C
        10, // D
        1,  // E
        16, // F
        17, // G
        8,  // H
        5,  // I
        23, // J
        22, // K
        11, // L
        14, // M
        6,  // N
        4,  // O
        19, // P
        24, // Q
        9,  // R
        7,  // S
        2,  // T
        13, // U
        21, // V
        15, // W
        25, // X
        18, // Y
        26  // Z
    };

    for (int i = 0; myString[i] != '\0'; i++) {
        if (isalpha((unsigned char)myString[i])) {
            char upper = toupper((unsigned char)myString[i]);
            int rank = ranks[upper - 'A'];
            printf("%d ", rank);
        } else {
            printf("%c ", myString[i]);
        }
    }
    printf("\n");
}*/

void AlphaCounter(char myString[]) {
    int num = strlen(myString);
    int count = 0;
    LetterFrequency frequencies[26] = {0};

    // Initialize frequencies array
    for(int i = 0; i < 26; ++i) {
        frequencies[i].letter = 'A' + i;
        frequencies[i].frequency = 0;
    }

    // Count letters
    for(int i = 0; i < num; ++i) {
        if(myString[i] >= 'A' && myString[i] <= 'Z') {
            frequencies[myString[i] - 'A'].frequency++;
            count++;
        }
    }
    
    // Calculate percentages
    for(int i = 0; i < 26; ++i) {
        if(count > 0) { // To avoid division by zero
            frequencies[i].percent = (frequencies[i].frequency / count) * 100;
        }
    }
    
    // Sort frequencies
    qsort(frequencies, 26, sizeof(LetterFrequency), compare);

    // Print sorted frequencies
    for(int i = 0; i < 26; ++i) {
        if(frequencies[i].frequency > 0) {
            printf("%2d) %c = %3.0f  %.2f%%\n", i+1,frequencies[i].letter, frequencies[i].frequency, frequencies[i].percent);
        }
    }
    
}

int main() {
    char myString[]="NBPFR KISOQ NFRDB FKJFD XNOIN OJXIX NZXSI DJXIJ NYENO ISDSA SOFBY REJRK IKSKI PFRAR DJZIJ RUSEE JXIZI KADFB JXIJK SODYI OGIOJ SEJIK ADSOG UESOJ JXIAI VKPWX IKIPF RARDJ ENIRU FOJXI GSNDN IDSOG GNDYF RKDIN OOFVI EUXKS DIDFB PFRKY FAUEN YSJIG DJSJI FBANO GJXIA ISONO ZGFID OJASJ JIKNB NJDFO EPNGE IYXSJ JIKFB SJKSO DYIOG IOJSE LNOGS OGIVK PFOIW NEEDS PSDPF RWSEL PFRKA PDJNY WSPNB JXNDP FROZA SOIQU KIDDI DXNAD IEBNO JIKAD JFFGI IUBFK AIWXP WXSJS VIKPD NOZRE SKEPG IIUPF ROZAS OJXND GIIUP FROZA SOARD JCICI IEFMR IOJNO UKSND IFBJX IVIKP GREEF EGGSP DWXNY XXSVI EFOZD NOYIU SDDIG SWSPS OGYFO VNOYI IANBP FRYSO JXSJJ XIKIN ZOFBZ FFGMR IIOSO OIWSD YREJR KIDUS EANID JGSPF BYFRK DIPFR WNEEU FFXUF FXWXS JIVIK DBKID XSOGO IWSOG GIYES KINJD YKRGI SOGAI SOBFK SKJDJ FUUIG DXFKJ NOJXI YREJN VSJIG YFRKJ FBJXI IAUKI DDHFD IUXNO ISOGI VKPFO IWNEE DSPSD PFRWS ELPFR KAPDJ NYWSP NBJXS JDOFJ ZFFGI OFRZX BFKXN AWXNY XNDZF FGIOF RZXBF KAIWX PWXSJ SVIKP YREJN VSJIG LNOGF BPFRJ XJXND LNOGF BPFRJ XARDJ CIJXI OSDIO JNAIO JSEUS DDNFO FBSVI ZIJSC EIBSD XNFOA RDJIQ YNJIP FRKES OZRNG DUEII OSOSJ JSYXA IOJSE SUESJ FBFKS CSDXB REPFR OZUFJ SJFFK SOFJJ FFBKI OYXBK IOYXC ISOJX FRZXJ XIUXN ENDJN OIDAS PHFDJ EIPFR WNEEK SOLSD SOSUF DJEIN OJXIX NZXSI DJXIJ NYCSO GNBPF RWSEL GFWOU NYYSG NEEPW NJXSU FUUPF KSENE PNOPF RKAIG NIVSE XSOGS OGIVK PFOIW NEEDS PSDPF RWSEL PFRKB EFWKP WSPNB XIDYF OJIOJ WNJXS VIZIJ SCEIE FVIWX NYXWF REGYI KJSNO EPOFJ DRNJA IWXPW XSJSA FDJUS KJNYR ESKEP URKIP FROZA SOJXN DURKI PFROZ ASOAR DJCI";
    char myKey[]="LIME";
    
    //SubSolver(myString,myKey);
    
    //AlphaCounter(myString);
    //AlphaSolver(myString);

    return 0;
}





