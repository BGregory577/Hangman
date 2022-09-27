

#include <stdio.h>
#include <iostream>
#include <string>
#include "Wordlists.h"


using namespace std;

int lettercheck(char guess, string unknownword, string& guessword) {        //function that checks if guessed letter to see if it was used before
    int matches = 0;
    int len = unknownword.length();

    for (int i = 0; i < len; i++)
    {
        if (guess == guessword[i])        //checks if the guess matches a letter that was previously guessed
            
            return 0;


        if (guess == unknownword[i]) {    //checks if the guess is in the unknown word.
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}


int main()
{



    int tries = 6;			//tries set for 6
    int numberselected;     //veriable to pick a word from the word list

    extern const char* wordlist[49];     //word list in an array can be found in the header


    printf("Let's play Hangman!\n");
    printf("You have %i" " tries left\n", tries);

    printf("Enter a number between 0 and 48 to generate a word\n");
    scanf_s("%i", &numberselected);                     //enter a number to be compared to the wordlist to generate a word to play with
    string word = wordlist[numberselected];

    string correctletter = "";              //for correct letters guessed
    string unknown(word.length(), '_');     //to generate placers for unknown letters in the game word.

    std::cout << "Your word is " << word.length() << " letters long" << endl;


    while (word == unknown, tries > 0)        //condition to end loop if word is guessed correctly or tries reaches 0
    {
        printf("Please guess a letter:\n");

        std::cout << unknown << endl;
        char letter;
        std::cin >> letter;         //enter letter for guess

        if (lettercheck(letter, word, unknown) == 0) {
            printf("could not find %c in word\n", letter);      //runs lettercheck function for the letter checked and comparing it to the selected word and unknown word.
            tries--;
        }
        else {
            printf("Your guess is right!\n");                   //If the leetercheck is not true then this response runs
        }

        if (word == unknown) {                               //compares if word string is equal to unknown string to determine if you won
            printf("Congraduations! You win!");
            return 0;
        }

        printf("Guess another letter, you have %i left\n", tries);
    }

    
    

    if (tries == 0) {                                            //If tries have ran out the loop will and this statement will run
        printf("You ran out of tries, better luck next time");
        std::cout << "The correct word is " << word << endl;
    }

    return 0;

}
