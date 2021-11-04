#include<math.h>
#include <stdio.h>
#define true 1
#define false 0

int getDigit(int,int);
int getSize(int);
int isArmstrong(int);
int isPalindrome(int);
int recArmstrong(int, int, int, int);
int reverse(int,int);

/** RECURSION IS REQUIRED!!!
 * ARMSTRONG NUMBER DEFINITION. an armstrong number is an n-digit number that is equal to the sum of the n-th powers of its digits.
 * E.g. taking num = 407 then n = 3, so we have: 4^n + 0^n + 7^n = 4^3 + 0^3 + 7^3 = 64 + 0 + 343 = 407 so it's an armstrong number.
 * @param num a given integer number.
 * @return if an armstrong number by the definition above.
 *         If so return 1 which means true, otherwise, return 0 which means false.
 */
int isArmstrong(int num){ return recArmstrong(num, getSize(num),0,num);}
int recArmstrong(int num, int n, int sum, int originalNum){
    if(num < 10)
        return originalNum == sum + pow(num, n);
    else
        return recArmstrong((num - num%10) / 10, n, sum + pow(getDigit(num, 0), n),originalNum);
}
/**
 * @param num a given integer number
 * @param pos a given position
 * @return the pos-th digit from right to left.
 */
int getDigit(int num, int pos){ return (int)(num/pow(10,pos)) % 10;}
/**
 * for base x the formula to find how many digits is (int)log_x(num)+1
 * @param num a given integer number.
 * @return how many digits assemble the number.
 */
int getSize(int num){ return num == 0 ? 1 : (int)log10(num) + 1;}
/** RECURSION IS REQUIRED!!!
 * PALINDROME NUMBER DEFINITION. a palindrome number is a number that can be read the same from left to right and from right to left.
 * E.g. taking num = 1331 is palindrome, however, taking num = 1231 isn't a palindrome since 1321 != 1231.
 * @param num a given number.
 * @return if the number is a palindrome by def, which means that the reversed number of num and num itself are equivalent.
 *         If so return 1, otherwise return 0.
 */
int isPalindrome(int num){
    if(num < 0)
        return false;
    else
        return reverse(num,0) == num;
}
/**
 * The method takes with recursion the first digit, and places it at the last position of the new number.
 * @param num a given integer number.
 * @param ans the reversed version of the given number.
 * @return ans parameter.
 */
int reverse(int num, int ans){
    if(num == 0)
        return ans;
    ans += getDigit(num,0) * pow(10, getSize(num)-1);
    num = (num - num%10)/10; //removes first digit from the number.
    return reverse(num,ans);
}