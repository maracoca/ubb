//
// Created by mara on 2/27/2024.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void read_numbers(int vector_of_nr[], int length) {
    /*
     * reads the numbers from the vector
     */

    int next_number;
    for (int i = 0; i < length; i++) {
        scanf("%d", &next_number);
        vector_of_nr[i] = next_number;
    }
}

int is_prime(int number){
    /*
     * checks if a number is prime
     */

    if (number == 0 || number == 1)
        return 0;

    for (int i = 2; i<=number/2; i++)
        if (number%i == 0){
            return 0;
        }
    return 1;
}

void prime_numbers(int vector_of_prime_nr[], int number) {
    /*
     * fills the vector with prime numbers
     */

    int current_position = 0;
    int number_to_check = 0;
    while (number > 0) {
        if (is_prime(number_to_check) == 1) {
            vector_of_prime_nr[current_position] = number_to_check;
            current_position++;
            number--;
        }
        number_to_check++;
    }
}

int greatest_common_divisor(int number1, int number2) {
    /*
     * calculates and returns the greatest common divisor of 2 numbers
     */
    int numerator, denominator;
    if (number1 > number2) {
        numerator = number1;
        denominator = number2;
    }
    else{
        numerator = number2;
        denominator = number1;
    }

    int remainder = numerator % denominator;
    while (remainder != 0)
    {
        numerator = denominator;
        denominator = remainder;
        remainder = numerator % denominator;
    }
    int gcd = denominator;
    return gcd;
}

void longest_subsequence(int vector_of_nr[], int length, int* start, int* max_length){
    /*
     * finds the start and the length of the longest subsequence such that any two consecutive elements are relatively prime
     */

    *start = 0;
    *max_length = 1;
    int current_length = 1;

    for (int i = 1; i < length; i++) {
        if (greatest_common_divisor(vector_of_nr[i - 1], vector_of_nr[i]) == 1) {
            current_length++;
        }
        else {
            if (current_length > *max_length) {
                *max_length = current_length;
                *start = i - *max_length;
            }
            current_length = 1;
        }
    }

    if (current_length > *max_length) {
        *start = length - current_length;
        *max_length = current_length;
    }
}

int ui(){
    while (true) {

        printf("What would you like to do next? \n 1.Read a vector of numbers from the console \n 2.Generate the first n prime numbers (n is a given natural number) \n 3.Find the longest contiguous subsequence such that any two consecutive elements are relatively prime. \n 4.Exit. \n ");
        int user_option;
        scanf("%d", &user_option);

        if (user_option == 1) {
            printf("How many numbers would you like to read? \n");
            int numbers_read;
            scanf("%d", &numbers_read);

            int vector_of_nr[numbers_read];
            for (int i = 0; i < numbers_read; i++)
                vector_of_nr[i] = 0;

            printf("Write the numbers. \n");
            read_numbers(vector_of_nr, numbers_read);
            for (int i = 0; i < numbers_read; i++)
                printf("%d ", vector_of_nr[i]);
            printf("\n");

        } else if (user_option == 2) {
            printf("How many prime numbers would you like to see? \n");
            int prime_number;
            scanf("%d", &prime_number);

            int vector_of_prime_nr[prime_number];
            for (int i = 0; i < prime_number; i++)
                vector_of_prime_nr[i] = 0;

//        int *list_of_primes;
//        list_of_primes = prime_numbers(vector_of_prime_nr, prime_number);
            prime_numbers(vector_of_prime_nr, prime_number);
            for (int i = 0; i < prime_number; i++) {
                printf("%d ", vector_of_prime_nr[i]);
            }
            printf("\n");

        } else if (user_option == 3) {
            printf("How many numbers would you like to add? \n");
            int numbers_read;
            scanf("%d", &numbers_read);

            printf("Write the numbers. \n");

            int vector_of_nr[numbers_read];

            for (int i = 0; i < numbers_read; i++)
                vector_of_nr[i] = 0;
            read_numbers(vector_of_nr, numbers_read);
            int start, max_length;
            longest_subsequence(vector_of_nr, numbers_read, &start, &max_length);

            for (int i = start; i < start + max_length; ++i) {
                printf("%d ", vector_of_nr[i]);
            }
            printf("\n");

        } else if (user_option == 4) {
            break;
        }
        else {
            return 0;
        }
    }
}

int main(){
    ui();
    return 0;
}
