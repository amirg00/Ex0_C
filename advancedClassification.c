#include <math.h>
#include <stdio.h>
#define true 1
#define false 0

int getDigit(int,int);
int getSize(int);
int isArmstrong(int);
int isPalindrome(int);

/**
 * ARMSTRONG NUMBER DEFINITION. an armstrong number is an n-digit number that is equal to the sum of the n-th powers of its digits.
 * E.g. taking num = 407 then n = 3, so we have: 4^n + 0^n + 7^n = 4^3 + 0^3 + 7^3 = 64 + 0 + 343 = 407 so it's an armstrong number.
 * @param num a given integer number.
 * @return if an armstrong number by the definition above.
 *         If so return 1 which means true, otherwise, return 0 which means false.
 */
int isArmstrong(int num){
int sum = 0, n = getSize(num);
    for (int i = 0; i < n; ++i)
        sum += pow(getDigit(num,i),n);
return sum == num;
}
/**
 * @param num a given integer number
 * @param pos a given position
 * @return the pos-th digit from right to left.
 */
int getDigit(int num, int pos){ return (int)(num / pow(10,pos)) % 10;}
/**
 * for base x the formula to find how many digits is ()log_x(num)+1
 * @param num a given integer number.
 * @return how many digits assemble the number.
 */
int getSize(int num){ return num == 0 ? 1 : (int)log10(num) + 1;}
/**
 * PALINDROME NUMBER DEFINITION. a palindrome number is a number that can be read the same from left to right and from right to left.
 * E.g. taking num = 1331 is palindrome, however, taking num = 1231 isn't a palindrome since 1321 != 1231.
 * @param num a given number.
 * @return if the number is a palindrome by def. if so return 1, otherwise return 0.
 */
int isPalindrome(int num){
    if(num < 0) return false;
    for (int i = 0, m = getSize(num)-1; i < getSize(num); ++i,--m)
        if(getDigit(num,i) != getDigit(num,m))
            return false;
    return true;
}