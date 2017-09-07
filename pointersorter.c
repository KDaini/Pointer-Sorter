/*Author: Kevin Daini
 9/10/2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pointersorter.h"


int main(int argc, const char ** argv) {
    int length = 0;
    int words = 0;
    char * input;
    int i = 0;
    
    /* check arguments*/
    
    if (argc < 2){
        printf("ARG ERROR\n");
        exit(EXIT_FAILURE);
    }
    /* get input from argv*/
    
    input = malloc(sizeof(char)*(strlen(argv[1])));
    strcpy(input, argv[1]);
    
    /*replace non alphabetic characters with ' ' (for strtok)*/
    
    for (i=0; i<strlen(input); i++){
        if (!isalpha(input[i])){
            input[i] = ' ';
            words++;
        }
    }
    
    words++;
    length=strlen(input);
    
    /* error check for no alphabetic characters*/
    
    if (words == length+1){
        printf("ERROR, NO WORDS ENTERED\n");
        exit(EXIT_FAILURE);
    }
    
    printf("INPUT: %s\n", input);
    
    /* call sort function*/
    sort(input, length, words);
    
    free(input);
    return 0;
}

int sort(char *in, int len, int numWords){
    int it = 0;
    int it1 = 0;
    int it2 =0;
    char * word;
    char * s = " ";
    char ** words;
    char * temp;
    int cmp = 0;
    
    words = malloc(sizeof(char)*numWords*len);
    
    /*tokenize input into words*/
    
    word = strtok(in, s);
    while(word!=NULL){
        words[it] = malloc(sizeof(char)*len);
        strcpy(words[it], word);
        it++;
        word = strtok(NULL, s);
    }
    temp = malloc(sizeof(char)*len);
    
    /*insertion sort on the strings*/
    
    for (it1=0; it1<it; it1++) {
        for (it2=it1+1; it2<it; it2++) {
            cmp = strcmp(words[it1], words[it2]);
            if (cmp>0) {
                strcpy(temp, words[it1]);
                strcpy(words[it1], words[it2]);
                strcpy(words[it2], temp);
            }
        }
    }
    
    /*print sorted strings*/
    
    for (it1=0; it1<it; it1++) {
        printf("%s\n", words[it1]);
    }
    
    free(words);
    free(temp);
    return 0;
}