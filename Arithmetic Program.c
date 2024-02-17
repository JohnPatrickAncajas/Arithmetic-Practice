#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {

    srand(time(0));

    int correctAnswers = 0;
    int totalQuestions = 0;

    while (1) {
        printf("Menu\n\n1. Addition\n2. Subtraction\n3. Division\n4. Multiplication\n5. Exit\n\n");
        char input[10];
        fgets(input, 10, stdin);
        int choice = atoi(input);
        if(choice < 1 || choice > 5) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            continue;
        }

        if (choice == 5) break;

        int num1 = rand() % 100;
        int num2 = rand() % 100;

        if (choice == 2 && num2 > num1) {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }

        if (choice == 3) num1 = num1 * num2;

        printf("What is ");
        if (choice == 1) printf("%d + %d?\n", num1, num2);
        else if (choice == 2) printf("%d - %d?\n", num1, num2);
        else if (choice == 3) printf("%d / %d?\n", num1, num2);
        else if (choice == 4) printf("%d * %d?\n", num1, num2);

        fgets(input, 10, stdin);
        int answer = atoi(input);

        int correctAnswer;
        if (choice == 1) correctAnswer = num1 + num2;
        else if (choice == 2) correctAnswer = num1 - num2;
        else if (choice == 3) correctAnswer = num1 / num2;
        else if (choice == 4) correctAnswer = num1 * num2;

        if (answer == correctAnswer) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", correctAnswer);
        }

        totalQuestions++;
        printf("Your score: %.2f%%\n", (100.0 * correctAnswers / totalQuestions));
    }

    return 0;
}
