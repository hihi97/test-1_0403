#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Function to generate a random 4-digit magic number
int generateMagicNumber() {
    srand(time(NULL));
    return rand() % 9000 + 1000;
}

// Function to check if the guessed number matches the magic number
void checkGuess(int magicNumber, int guess) {
    int magicDigits[4], guessDigits[4];
    int i, matched = 0;

    // Extract digits of magic number
    for (i = 0; i < 4; i++) {
        magicDigits[i] = magicNumber % 10;
        magicNumber /= 10;
    }

    // Extract digits of guess
    for (i = 0; i < 4; i++) {
        guessDigits[i] = guess % 10;
        guess /= 10;
    }

    // Check for matches
    for (i = 0; i < 4; i++) {
        if (magicDigits[i] == guessDigits[i]) {
            printf("%d", magicDigits[i]); // Print matched digit
            matched++;
        } else {
            printf("-");
        }
    }

    // Print remaining '-'
    for (i = 0; i < 4 - matched; i++) {
        printf("-");
    }
}

int main() {
    char playerName[MAX_NAME_LENGTH];
    int magicNumber, guess, correctGuesses = 0, totalGuesses = 0;

    printf("Enter your name: ");
    fgets(playerName, MAX_NAME_LENGTH, stdin);
    strtok(playerName, "\n"); // Remove newline character from playerName

    printf("Welcome, %s!\n", playerName);

    while (1) {
        magicNumber = generateMagicNumber();
        totalGuesses = 0;
        correctGuesses = 0;

        printf("Round %d\n", totalGuesses + 1);

        while (1) {
            printf("Enter your guess (4 digits): ");
            scanf("%d", &guess);

            // Check if guess is correct
            totalGuesses++;
            printf("Your guess: ");
            checkGuess(magicNumber, guess);
            printf("\n");

            if (magicNumber == guess) {
                printf("Congratulations, you've guessed the magic number: %d\n", magicNumber);
                correctGuesses++;
                break;
            }
        }

        printf("Lucky ratio: %.2f (%d/%d)\n", (float)correctGuesses / totalGuesses, correctGuesses, totalGuesses);

        char playAgain;
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }

    return 0;
}

