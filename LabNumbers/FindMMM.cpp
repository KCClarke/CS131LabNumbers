/*
Kasey Clarke
CS& 131 October 1st 2024

Challenge Level: Find Mean, Median, and Mode (This is challenge because you need
arrays and to sort the array. If you need help sorting let me know)

Write a C++ program that asks the user to enter a set of integer numbers between
0 and 100 and stores it into an array of max size 10 with all the values
initialized to -1 so you know when to stop going through the array.

When storing the numbers do so in a loop. The program should keep asking the
user to enter a number until -1 is entered or until 10 numbers have been
inputted. When the break condition happens, Display the Mean, Median, and Mode.

If the user enters a number that is > 100 or < -1, the number is ignored (not
stored into the array) and a message stating that “Invalid number was entered;
must be between 0 and 100.” is displayed before the user is prompted to enter a
number again. The following is a sample outcome:

Enter a number between 0 and 100 (-1 to terminate): 34
Enter a number between 0 and 100 (-1 to terminate):11
Enter a number between 0 and 100 (-1 to terminate):-7
Invalid number was entered; must be between 0 and 100.
Enter a number between 0 and 100 (-1 to terminate):78
Enter a number between 0 and 100 (-1 to terminate):150
Invalid number was entered; must be between 0 and 100.
Enter a number between 0 and 100 (-1 to terminate):82
Enter a number between 0 and 100 (-1 to terminate):11
Enter a number between 0 and 100 (-1 to terminate):-1

Mean   Median   Mode
  43       34     11

Hint: Use setw from the <iomanip> header file to format the output

Mean(r) Median  Mode
     43     34    11

For the Mean you can floor it (43.2 = 43, 43.9 = 43), ceiling it (43.2 =
44, 43.9 = 44) or round it (43.2 = 43, 43.9 = 44). Just leave a comment so I
know which one you are doing. You can also have the program output next to the
mean one which option it is. In the example right about the (r) is to indicate
it's rounded.
*/

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
#define FLAG -1
#define MAX_NUMBER 100


void greeting(){cout << "Welcome to FindMMM\n";}

void initializeArray(int numbers[], const int SIZE, const int CONTENT ) {
  for (int i = 0; i < SIZE; i++)
    numbers[i] = CONTENT;
}

void printArray(int numbers[], const int SIZE) {
  for (int i = 0; i < SIZE; i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;
}

//gets the user input and returns it if it is within the range we want including the flag
int getInput() {
  int input;
  for (;;) {
    cout << "Enter a number between 0 and " << MAX_NUMBER << " (-1 to terminate): ";
    cin >> input;

    if (input < FLAG || input > MAX_NUMBER) {
      cout << "Invalid number was entered. must be between 0 and " << MAX_NUMBER << ". \n";
      continue;
    }
    return input;
  }
}

void swapPrevious(int numbers[], const int J){
  int temp = numbers[J];
  numbers[J] = numbers[J - 1];
  numbers[J - 1] = temp;
}

void sort(int numbers[], const int I){
  for(int j = I; j > 0; j--){
    if(numbers[j] >= numbers[j - 1]) break;
    swapPrevious(numbers, j);
  }
}

int calculateMean(const int NUMBERS[], const int POPULATION){
  int sum = 0;
  for(int i = 0; i < POPULATION; i++) sum += NUMBERS[i];
  return round((float)sum / POPULATION); /*returns the rounded mean*/
}

float calculateMedian(const int NUMBERS[], const int POPULATION){
  int middleTruncated = POPULATION / 2;
  if (POPULATION % 2 != 0) return NUMBERS[middleTruncated];
  return ((float)NUMBERS[middleTruncated - 1] + NUMBERS[middleTruncated]) / 2;
}

//may be multiple modes therefore no return
//TO DO: return multiple modes to caller
void calculateMode(const int NUMBERS[], const int POPULATION){
  const int RANGE = 1 + MAX_NUMBER; //100 is the max number but we need space for 0
  int frequency[RANGE];
  initializeArray(frequency, RANGE, 0);
  for(int i = 0; i < POPULATION; i++){
    frequency[NUMBERS[i]]++;
  }
  int greatestOccurance = 0;
  for(int i = 0; i < RANGE; i++){
    if(frequency[i] > greatestOccurance) greatestOccurance = frequency[i];
  }
  for(int i = 0; i < RANGE; i++){
    if(frequency[i] == greatestOccurance) cout << " " << i;
  }
  cout << endl;
}

void displayMMM(const int NUMBERS[], const int POPULATION){
  const int WIDTH = 8;
  const int MEAN = calculateMean(NUMBERS, POPULATION);
  const float MEDIAN = calculateMedian(NUMBERS, POPULATION);
  cout << setw(WIDTH) << "Mean" << setw(WIDTH) << "Median" << setw(WIDTH) << "Mode" << endl;
  cout << setw(WIDTH) <<  MEAN  << setw(WIDTH) <<  MEDIAN  << setw(WIDTH/2);
  calculateMode(NUMBERS, POPULATION);
}

int main(){
    greeting();
    const int SIZE = 10;
    int numbers[SIZE];
    initializeArray(numbers, SIZE, FLAG);
    int population = 0;
    for(population; population < SIZE; population++){
      const int INPUT = getInput();
      if(INPUT == FLAG) break;
      numbers[population] = INPUT;
      if(population > 0) sort(numbers, population);
    }
    if(population >= 1) displayMMM(numbers, population);
}