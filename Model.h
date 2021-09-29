/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 2 - Tutnese Translation Continued
 * This is the header .h file for the Model class
*/
#include <iostream>

using namespace std;

class Model {
public:
  Model(); // Default constructor
  ~Model(); // Default desctructor
  string translateSingleCharacter(char englishSingleChar); // takes a single character as input and returns a string representing its encoding in Tutnese. Capitalization is preserved.
  string translateDoubleCharacter(char englishDoubleChar); // takes a single character as input that appears twice in a row and returns a string representing its encoding in Tutnese. Capitalization is preserved.
};
