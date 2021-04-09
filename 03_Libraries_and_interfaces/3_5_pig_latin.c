/**
 * Function: PigLatin
 * Usage: PigLatin(word, buffer, bufferSize)
 * -----------------------------------------
 * This function translates a word from English to Pig Latin. The
 * translated word is written into the array buffer, which has an 
 * allocated size of bufferSize. The code checks for buffer
 * overflow and generates an error if it occurs
 */

#include <string.h>
#include <err.h>
#include "../cslib/genlib.h"

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
        strcat(buffer, "ay")
    }
}