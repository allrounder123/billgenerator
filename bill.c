// auto bill generator
// Suppose you have a template letter.txt. You have to fill in values to a template. Letter.txt looks 
// something like this:
// Thanks {{name}} for purchasing {{item}} from our outlet {{outlet}}. Please visit our outlet {{outlet}} for
// any kind of problems. We plan to serve you again soon.
// You have to write a program that will automatically fill the template.For this, read this file and
// replace these values:
// {{name}} - Harry 
// {{item}} - Table Fan 
// {{outlet}} - Ram Laxmi fan outlet
// Use file functions in c to accomplish the same.
// auto bill generator
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// this is a string
char * replaceWord(const char * str, const char * oldWord, const char * newWord)
{
    char * resultString;
    int i, count = 0;
    int newWordLength = strlen(newWord);
    int oldWordLength = strlen(oldWord);

    // Lets count the number of times old word occurs in the string
    for (i = 0; str[i] !='\0'; i++)
    {
        if (strstr(&str[i], oldWord) == &str[i])
        {
            count++;

            // Jump over this word
            i = i + oldWordLength - 1;
        }
    }

    // Making a new string to fit in the replaced words
    resultString = (char *)malloc(i + count * (newWordLength - oldWordLength) + 1);//+1 for null character

    i = 0;
    while (*str)
    {
        // Compare the substring with result
        if(strstr(str, oldWord) == str)//str is a pointer
        {
            strcpy(&resultString[i], newWord);
            i += newWordLength;
            str += oldWordLength;
        }
        else{
            resultString[i] = *str;
            i += 1;
            str +=1;
        }
    }
    resultString[i] = '\0';
    return resultString;
}

int main()
{
    FILE * ptr = NULL;
    FILE * ptr2 = NULL;
    ptr = fopen("bill.txt", "r");
    ptr2 = fopen("genBill.txt", "w");
    char str [200];
    fgets(str, 200, ptr);
    printf("The given bill template was: %s\n", str);

    // Call the replaceWord function and generate newStr
    char * newStr;
    newStr = replaceWord(str, "{{item}}", "Table");
    newStr = replaceWord(newStr, "{{outlet}}", "collection");
    newStr = replaceWord(newStr, "{{name}}", "rina");
    printf("The actual bill generated is: %s\n", newStr);
    printf("The generated bill has been written to the file genBill.txt\n");

    
    fprintf(ptr2, "%s", newStr);
    // fclose(ptr);
    // fclose(ptr2);
    return 0;
}
