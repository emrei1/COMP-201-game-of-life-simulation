#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// This method takes the input file name, file, number of rows, and number of columns to read from the input given file to return in the end a two dimentional matrix whose columns and rows consist of the character values of the image from the input file. The method allocates the memory for the 2D matrix in the heap using the malloc function.
char **read_from_file(const char *filename, FILE *f, int numberOfRows, int numberOfColumns)
{ 
    char **returnedMatrix = malloc(sizeof(char*) * numberOfColumns);
    
    int i = 0;    
    for (i = 0; i < numberOfColumns; i++) {
        *(returnedMatrix + i) = malloc(sizeof(char) * numberOfRows);       
    }

    for (i = 0; i < numberOfColumns; i++) {
        char line[numberOfRows + 1];
        fgets(line, 9999, f);
        int j = 0;
        for (j = 0; j < numberOfRows; j++) {
            *(*(returnedMatrix + i) + j) = line[j];
        }
    }
    return returnedMatrix;    
}

// This method takes the current pattern, number of columns, number of rows, the output name, and the number of iterations to return the next step of the game as a two dimentional matrix. The method uses the rules of the game to check the approporiate spots for each cell from the input matrix and according to its neighbors updates the new cell in the returned matrix. The method also checks the number of deaths and newly born cells in the next step of the game. The method prints the number of death, number of newly born, and the image of the next step of the game to the console.
char **next_state(char **state, int numberOfColumns, int numberOfRows, char* outputName, int iterations)
{
    char tempStateReturned[numberOfColumns][numberOfRows];
    int deathCount = 0;
    int bornCount = 0;
    int i = 0;
    for (i = 0; i < numberOfColumns; i++) {
        int j = 0;
        for (j = 0; j < numberOfRows; j++) {
            char cell = state[i][j];
            int numberOfNeighbors = 0;
            if (i == 0) {
                if (j == 0) {
                    if (state[i][j+1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i+1][j] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i+1][j+1] == 'X') {
                        numberOfNeighbors++;
                    }
                } else if (j == numberOfRows - 1) {
                    if (state[i][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i+1][j] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i+1][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                } else {
                    if (state[i][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i][j+1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i+1][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i+1][j] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i+1][j+1] == 'X') {
                        numberOfNeighbors++;
                    }
                }
           } else if (i == numberOfColumns - 1) {
                if (j == 0) {
                    if (state[i][j+1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j+1] == 'X') {
                        numberOfNeighbors++; 
                    }
                } else if (j == numberOfRows - 1) {
                    if (state[i][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                } else {
                    if (state[i][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i][j+1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j+1] == 'X') {
                        numberOfNeighbors++;
                    }
                }
            } else {
                if (j == 0) {
                    if (state[i][j+1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j+1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i+1][j] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i+1][j+1] == 'X') {
                        numberOfNeighbors++;
                    }
                } else if (j == numberOfRows - 1) {
                    if (state[i][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i+1][j] == 'X') {
                        numberOfNeighbors++;
                    } 
                    if (state[i+1][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                } else {
                    if (state[i][j+1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i+1][j] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i-1][j+1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i+1][j-1] == 'X') {
                        numberOfNeighbors++;
                    }
                    if (state[i+1][j+1] == 'X') {
                        numberOfNeighbors++;
                    }
                }
            }
            if (cell == 'X') {
                if (numberOfNeighbors < 2) {
                    deathCount++;
                    tempStateReturned[i][j] = '-';
                } else if (numberOfNeighbors > 3) {
                    deathCount++;
                    tempStateReturned[i][j] = '-';
                } else {
                    tempStateReturned[i][j] = 'X';
                }
            } else {
                if (numberOfNeighbors == 3) {
                    bornCount++;
                    tempStateReturned[i][j] = 'X';
                } else {
                    tempStateReturned[i][j] = '-';
                }
            }
        }
    } 

    int z = 0; 
    for (z = 0; z < numberOfColumns; z++) {
        for (i = 0; i < numberOfRows; i++) {
            state[z][i] = tempStateReturned[z][i];
        }
    }
    
    printf("%d\n", deathCount);
    printf("%d\n", bornCount);
    for (i = 0; i < numberOfColumns; i++) {
        printf("%s\n", state[i]);
    }

    FILE *outputFile;
    
    int digits = 1;
    int temp = iterations;

    while (temp / 10 != 0) {
        digits++;
        temp = temp / 10;
    }

    int reverseNumber[digits];
    temp = iterations;

    if (digits == 1) {
        reverseNumber[0] = temp % 10;
    } else {
        int count = 0;
        while (temp != 0) {
            reverseNumber[count] = temp % 10;
            temp = temp / 10;
            count++;
        }
    }

    int actualNumber[digits];

    for (i = 0; i < digits; i++) {
        actualNumber[i] = reverseNumber[digits - i - 1];
    }


    char outputFilePath[strlen(outputName) + digits + 4 + 1];

    for (i = 0; i < strlen(outputName); i++) {
        outputFilePath[i] = outputName[i];
    }

    for (i = 0; i < digits; i++) {
        outputFilePath[strlen(outputName) + i] = 48 + actualNumber[i];
    }


    outputFilePath[strlen(outputName) + digits] = '.';
    outputFilePath[strlen(outputName) + digits + 1] = 't';
    outputFilePath[strlen(outputName) + digits + 2] = 'x';
    outputFilePath[strlen(outputName) + digits + 3] = 't';
    outputFilePath[strlen(outputName) + digits + 4] = '\0';

    outputFile = fopen(outputFilePath, "w");


    int deathDigits = 1;
    int bornDigits = 1;

    temp = deathCount;

    while (temp / 10 != 0) {
        deathDigits++;
        temp = temp / 10;
    }
    
    temp = bornCount;

    while (temp / 10 != 0) {
        bornDigits++;
        temp = temp / 10;
    }

    int reverseDeath[deathDigits];
    int reverseBorn[bornDigits];

    temp = deathCount;

    if (deathDigits == 1) {
        reverseDeath[0] = temp % 10;
    } else {
        int count = 0;
        while (temp != 0) {
            reverseDeath[count] = temp % 10;
            temp = temp / 10;
            count++;
        }
    }

    int actualDeath[deathDigits];

    for (i = 0; i < deathDigits; i++) {
        actualDeath[i] = reverseDeath[deathDigits - i - 1];
    }


    temp = bornCount;

    if (bornDigits == 1) {
        reverseBorn[0] = temp % 10;
    } else {
        int count = 0;
        while (temp != 0) {
            reverseBorn[count] = temp % 10;
            temp = temp / 10;
            count++;
        }
    }

    int actualBorn[bornDigits];

    for (i = 0; i < bornDigits; i++) {
        actualBorn[i] = reverseBorn[bornDigits - i - 1];
    }

    for (i = 0; i < deathDigits; i++) {
        fprintf(outputFile, "%d", actualDeath[i]);
    }
    fprintf(outputFile, "\n");

    for (i = 0; i < bornDigits; i++) {
        fprintf(outputFile, "%d", actualBorn[i]);
    }
    fprintf(outputFile, "\n");

    for (i = 0; i < numberOfColumns; i++) {
       char line[numberOfRows];
       int j = 0;
       for (j = 0; j < numberOfRows; j++) {
           line[j] = state[i][j];
       }
       fprintf(outputFile, "%s", line);
       fprintf(outputFile, "\n");
    }   
   
    return state;
}

// The bonus task method takes the three dimentional matrix for the input and checks whether the 2D matrices within the 3D matrix array contains a repeating pattern. The method returns true if it finds any identical patterns within the 3D array structure, and returns false otherwise.
bool is_oscillator(char ***pattern, int max_steps, int numberOfRows, int numberOfColumns)
{

    int foundEqual = 0;
    int a = 0;
    for (a = 0; a < max_steps - 1; a++) {

        char **firstPatternToCheck = pattern[a];


        int equal = 0;
        int k = 0;
        for (k = a + 1; k < max_steps; k++) {
            char **thisPattern = pattern[k];
            int isEqual = 1;
            int j = 0;
            for (j = 0; j < numberOfColumns; j++) {
                int z = 0;
                for (z = 0; z < numberOfRows; z++) {
                    if (thisPattern[j][z] != firstPatternToCheck[j][z]) {
                        isEqual = 0;
                    }
                }
            }
            if (isEqual == 1) {
                equal = 1;
            }
        }
        if (equal == 1) {
            foundEqual = 1;
        }
    }


    if (foundEqual == 1) {
        return 1;
    } 

    return 0;
}

// print the game state
// after each step you can call this function, add some delay and then clear screen to create a simple game simulation in terminal
void print_state(char **state, int rows, int cols)
{

    int i, j;
    printf("\nNext State:\n");
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            printf("%c", state[i][j]);
        }
        printf("\n");
    }
}

// The main method acts as the logical organizer that runs all the components for the game of life. It passes necessary information to all the methods
// and creates the appropriate data structures that the methods require in their parameters.
int main(int argc, char **argv) 
{   
    char *inputFolder = *(argv + 1);

    FILE *f = fopen(inputFolder, "r");

    char firstLine[9999];
    fgets(firstLine, 9999, f);
    char secondLine[9999];
    fgets(secondLine, 9999, f);
    char thirdLine[9999];
    fgets(thirdLine, 9999, f);

    int firstNumber = 0;
    int j = 0;
    int numberOfDigits = strlen(firstLine) - 1;
    for (j = 0; j < numberOfDigits - 1; j++) {
        char digit = firstLine[j];
        int k = 0;
        int multiplier = 1;
        for (k = 0; k < (numberOfDigits - j - 1); k++) {
            multiplier *= 10;
        }
        int digitToInt = (int) (digit - 48);
        int addedNumber = digitToInt * multiplier;
        firstNumber += addedNumber;

    }
    firstNumber += ((int) firstLine[numberOfDigits - 1]) - 48;
    
    int secondNumber = 0;
    numberOfDigits = strlen(secondLine) - 1;
    for (j = 0; j < numberOfDigits - 1; j++) {
        char digit = secondLine[j];
        int k = 0;
        int multiplier = 1;
        for (k = 0; k < (numberOfDigits - j - 1); k++) {
            multiplier *= 10;
        }
        int digitToInt = (int) (digit - 48);
        int addedNumber = digitToInt * multiplier;
        secondNumber += addedNumber;
    }
    secondNumber += ((int) secondLine[numberOfDigits - 1]) - 48;

    int thirdNumber = 0;
    numberOfDigits = strlen(thirdLine) - 1;
    for (j = 0; j < numberOfDigits - 1; j++) {
        char digit = thirdLine[j];
        int k = 0;
        int multiplier = 1;
        for (k = 0; k < (numberOfDigits - j - 1); k++) {
            multiplier *= 10;
        }
        int digitToInt = (int) (digit - 48);
        int addedNumber = digitToInt * multiplier;
        thirdNumber += addedNumber;
    }
    thirdNumber += ((int) thirdLine[numberOfDigits - 1]) - 48;  

    int numberOfIterations = firstNumber;
    int numberOfColumns = secondNumber;
    int numberOfRows = thirdNumber;

    char **initialGrid = read_from_file(inputFolder, f, numberOfRows, numberOfColumns);
    char **currentGrid = initialGrid;

    char *outputName = *(argv + 2);

    int numberOfTimesOscillatorCheck = 20;

    int oscillatorMaxTimes = numberOfIterations;

    char ***oscillatorCheckMatrix = malloc(sizeof(char*) * oscillatorMaxTimes);
    
    for (j = 0; j < numberOfIterations; j++) {
        char **newGrid = next_state(currentGrid, numberOfColumns, numberOfRows, outputName, j + 1);

        char **tempGrid = malloc(sizeof(char*) * numberOfColumns);
        
        int i = 0;
        for (i = 0; i < numberOfColumns; i++) {
            tempGrid[i] = malloc(sizeof(char*) * numberOfRows);
            int z = 0;
            for (z = 0; z < numberOfRows; z++) {
                tempGrid[i][z] = newGrid[i][z];
            }
        }
        
        oscillatorCheckMatrix[j] = tempGrid;
        
        currentGrid = newGrid;
    }


    if (is_oscillator(oscillatorCheckMatrix, oscillatorMaxTimes, numberOfRows, numberOfColumns)) {
        printf("oscillator check result is that the pattern is oscillating\n");
    } else {
        printf("oscillator check result is that the pattern is not oscillating\n");
    }


    return 0;
}               
