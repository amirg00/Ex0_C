#include <stdio.h>
#include <math.h>
#define true 1
#define false 0

int isPrime(int);
int isStrong(int);

/**
 * @param num a given integer number.
 * @return if num is a prime number, if so return 1, otherwise return 0, when 1 is true and 0 is false.
 */
int isPrime(int num){
    if (num < 1) // if the number is negative or zero then it couldn't be a prime number by definition.
        return false;
    for (int i = 2; i <= sqrt(num); ++i)
        if (num % i == 0)
            return false;
    return true;
}
/**
 * factorial(x) = x! = x * (x-1) * ... * 2 * 1, factorial(0) = factorial(1) = 1.
 * @param num a given number.
 * @return the factorial of num (num!).
 */
int factorial(int num){
    int sum = 1;
    for (int i = 2; i <= num; ++i)
        sum *= i;
    return sum;
}
/**
 * STRONG NUMBER DEFINITION. a strong number is a number, such that the sum of all his digits with factorial on each equals to the number itself.
 * E.g.: given num = 145, then:  1! + 4! + 5! = 1 + 24 + 120 = 145. Therefore, 145 is a strong number.
 * @param num - a given integer number.
 * @return whether num is a strong number, i.e. if the sum of num's digits factorials are equal to the given num.
 *         if so return 1 which means true, otherwise, return 0 which means false.
 */
int isStrong(int num){
    int sum = 0, originalNum = num;
    while (num > 0){
        int lastDigit = num % 10;
        sum += factorial(lastDigit);
        num = (num - lastDigit) / 10;
    }
    return sum == originalNum;
}