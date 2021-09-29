/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 2 - Tutnese Translation Continued
 * This is the header .h file for the Translator class
*/
#include <iostream>

using namespace std;

class Translator {
public:
  Translator(); // default constructor
  ~Translator(); // default destructor
  string translateEnglishWord(string englishWord); // takes a single string representing a single English word as input and returns a string representing the Tutnese translation.
  string translateEnglishSentence(string englishSentence); // takes a single string representing a single English sentence as input and returns a string representing the Tutnese translation. Accounts for punctuation.
  string translateTutneseWord(string tutneseWord); // takes a single string representing a single tutnese word as input and returns a string representing the english translation.
  string translateTutneseSentence(string tutneseSentence); // takes a single string representing a single tutnese sentence as input and returns a string representing the english translation. Accounts for punctuation.
};
