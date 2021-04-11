#include <stdio.h>
#include <string.h>
#include "genlib.h"

#define MaxWord 100

/**
 * Functioin: IsVowel
 * Usage: IsVowel(char cp);
 * ------------------------
 * This function returns 1 if a cp is a vowel returns zero otherwise.
 */

int IsVowel(char *cp){
   
   char vowels[] = "aeiouy";

   int i;
   for (i = 0; vowels[i] != '\0'; i++){
           printf("%d\n", vowels[i]);       
   }
   return(1);
}
/**
 * Function: FindFirstVowel
 * Usage: vp = FindFIrstVowel(word);
 * ---------------------------------
 * This function returns a pointer of the first vowel in word.
 * If word does not contain a vowel, FindFistVowel returns NULL.
 */

static char *FindFirstVowel(char *word){
    
    char *cp;
    
     for (cp = word; *cp != '\0'; cp++){
         /* I don't see anywhere IsVowel is defined */
         if (IsVowel(*cp)) return(cp);
     }
     return (NULL);
}

/**
 * Function: PigLatin
 * Usage: PigLatin(word, buffer, bufferSize)
 * -----------------------------------------
 * This function translates a word from English to Pig Latin. The
 * translated word is written into the array buffer, which has an 
 * allocated size of bufferSize. The code checks for buffer
 * overflow and generates an error if it occurs
 */

static void PigLatin(char *word, char buffer[], int bufferSize) {
    char *vp;
    int wordLength;
    
    vp = FindFirstVowel(word);
    wordLength = strlen(word);
    
    if (vp == word){
        wordLength += 3;
    } else if (vp != NULL){
        wordLength += 2;
    }

    if (wordLength >= bufferSize) Error("Buffer overflow");

    if (vp == NULL){
        strcpy(buffer, word);
    } else if (vp == word){
      strcpy(buffer, word);
      strcat(buffer, "way");
    } else {
        strcpy(buffer, vp);
        strncat(buffer, word, vp - word);
        strcat(buffer, "ay");
    }
}

int main(){
    string word;
    char translationBuffer[MaxWord + 1];

    word = "Hello";
    
    PigLatin(word, translationBuffer, MaxWord + 1);
    printf("Pig Latin: %s\n", translationBuffer);
}