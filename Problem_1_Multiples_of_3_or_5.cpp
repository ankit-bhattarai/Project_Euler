#include <iostream>

/*

Problem Statement:

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

-----------------------------------------

 There are two ways of doing this:
 1. Brute Force
 2. Use Tricks of Summation
 * */
int integer_seq_sum(int n){
    int answer = n * (n + 1) / 2;
    return answer;
}
int faster_sum(int N, int a, int b){
    /*
     * A much better trick is to use the power of summation
     * We are basically adding the multiples of 3 and multiples of 5 separately
     * Using the example of N = 1000, a = 3 and b = 5, it is obvious that the sum can be broken down as follows
     * The multiples of 3 are added like 3 + 6 + 9 + 12 + ... + 999 = 3 * (1 + 2 + 3 + ... + 333)
     * Likewise, multiples of 5 are added like 5 + 10 + 15 + 20 + ... 995 = 5 * (1 + 2+ ... + 199)
     * Note that the multiples of 15, 15, 30, 45, ... 990 are in both the sum of 3 and the sum of 5, so it has to be
     * subtracted once. This means that the sum we have to subtract is 15 + 30 + ... + 990 = 15 * (1 + 2 + ... + 66)
     * 1 + 2 + 3 + ... + n has an easy to evaluate formula which is S(n) = n * (n + 1) / 2.
     * The entire sum can be denoted as 3 * S(333) + 5 * S(199) - 15 * S(66)
     * Note, we need to find the sum of numbers less than N, so the target number is N - 1
     * 1000 / 5 is 200, but for the sum we don't want to add 1000, only 995, so we use (N - 1) / 5 to prevent
     * adding 1000 to the sum, this is why for the factors below, the integer division by num is done as (N - 1) / num
     * Note, if N = ka, e.g. 1000 = 200 * 5, N/a = 200, but we don't wish to add 200 and instead (N-1)/a = k - 1/a,
     * The integer division here will produce k - 1 which is what we want
     */
    int factor_a = (N - 1) / a;
    int factor_b = (N - 1) / b;
    int factor_ab = (N - 1) / (a*b);
    int sum = a * integer_seq_sum(factor_a) + b * integer_seq_sum(factor_b) - a*b* integer_seq_sum(factor_ab);
    return sum;

}
int brute_force(int N, int a, int b){
    // This function will iterate from i = 1 to i = N - 1 and for every single number it will check if that number
    // is a multiple of a or a multiple of b. If they are, it will add it up to the sum
    // This has complexity O(N)
    int sum = 0;
    for (int i=1; i < N; i++){
        if ((i % a == 0)|(i % b ==0)){
            sum += i;
        }
    }
    return sum;

}
int main() {
    int sum = faster_sum(1000, 3, 5);
    std::cout<<sum;
    return 0;
}


