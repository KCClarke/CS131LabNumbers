/*
Task:
Choose between the Newbie and the Challenge Level.

Newbie Level: Abundant Numbers 

An Abundant Number is when the sum of all the divisors of a number 
(not including the number itself) is larger than the number. 
It is considered a perfect number if the sum of the divisors is equal to the number. 
It is deficient if the sum of the divisors is less then the number.

12 = 1 + 2 + 3 + 4 + 6 = 16 is a abundant number
16 = 1 + 2 + 4 + 8 = 15 is a deficient number
28 = 1 + 2 + 4 + 7 + 14 = 28 is a perfect number

Write a program to allow the user to enter a maximum of 10 numbers into an array using a loop.
  The array initialized should have the values of -1 so that you can check if the user
  entered in a value. The program will then determine if the numbers are 
  abundant, deficient, or perfect.  Below is some sample output

Number types:
Enter a number (-1 to quit): 12
Enter a number (-1 to quit): 14
Enter a number (-1 to quit): 6
Enter a number (-1 to quit): -1

12 is an abundant number. 
14 is a deficient number.
6 is a perfect number.
*/

#include <iostream>
using namespace std;
#define FLAG -1
void greeting(){cout << "Welcome to AbundantNumbers\n";}

void initializeArray(int numbers[], int size){
  for (int i = 0; i < size; i++)
    numbers[i] = FLAG;
}

void printArray(int numbers[], int size){
  for (int i = 0; i < size; i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;
}

//gets the user input and returns it if it is within the range we want including the flag
int getInput(){
  int input;
  for (;;) {
    cout << "Enter a number (-1 to quit): ";
    cin >> input;
    if (input < FLAG ) continue;
    break;
    }
    return input;
}

int sumFactors(const int N){
  int sum = 0;
  for(int i = 1; i < N; i++) if(N % i == 0) sum += i;
  return sum;
}

void printResult(const int NUMBERS[], const int POPULATION){
  for(int i = 0; i < POPULATION; i++) {
    const int NUMBER = NUMBERS[i];
    if(NUMBER == sumFactors(NUMBER)) cout << NUMBER <<  " is a perfect number.\n";
    if(NUMBER <  sumFactors(NUMBER)) cout << NUMBER <<  " is an abundant number.\n";
    if(NUMBER  > sumFactors(NUMBER)) cout << NUMBER <<  " is a deficient number.\n";
  }
}

int main(){
  greeting();
  const int SIZE = 10;
  int numbers[SIZE];
  initializeArray(numbers, SIZE);
  int population = 0;
  for(population; population < SIZE; population++){
    const int INPUT = getInput();
    if(INPUT == FLAG) break;
    numbers[population] = INPUT;
  }
  printResult(numbers, population);
}