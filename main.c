# include "NumClass.h"
# include <stdio.h>


void mainProgram(int, int);
/**
 *  the function takes two integers a,b for checking the range [a,b].
 *  If b < a or a < 0 or b < 0 than the program asks the user to enter again normal numbers to answer the requested conditions.
 * @return
 */
int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    mainProgram(a,b);
}
/**
 * By given a range [a,b], the function prints all the requested number in range.
 * In addition, the function arranges the print to be exactly as represented in output files,
 *      in terms of the number's order and spaces.
 * @param a given natural number.
 * @param b given natural number greater than 'a'.
 */
void mainProgram(int a, int b){
    int min = a < b ? a : b, max = a > b ? a : b;
    // printing all strong number in a line
    printf("The Armstrong numbers are:");
    for (int i = min; i <= max; ++i)
        if(isArmstrong(i)) printf(" %d", i);
    // printing all strong number in a line
    printf("\nThe Palindromes are:");
    for (int i = min; i <= max; ++i)
        if(isPalindrome(i))
            printf(" %d",i);
    // printing all strong number in a line
    printf("\nThe Prime numbers are:");
    for (int i = min; i <= max; ++i)
        if(isPrime(i)) printf(" %d",i);
    // printing all strong number in a line
    printf("\nThe Strong numbers are:");
    for (int i = min; i <= max; ++i)
        if(isStrong(i)) printf(" %d",i);
    printf("\n"); // new empty line in the end as represented in the outputted files.
}