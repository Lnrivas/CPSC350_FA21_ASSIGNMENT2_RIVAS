/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 2 - Tutnese Translation Continued
 * This is the header .h file for the FileProcessor class
*/
#include <iostream>
#include <fstream>

using namespace std;

class FileProcessor {
public:
  FileProcessor(); // default constructor
  ~FileProcessor(); // default deconstructor
  void processFile(string inputFile, string outputFile); // takes string representing the input file (English) and a string representing the output file (where the Tutnese translation will be written). Has a void return type.
  void processFile(string tutInputFile, string englishOutputFile, char x); // takes string representing the input file (tutnese) and a string representing the output file (where the english translation will be written), and char x to differentiate between english to tut vs tut to english. Has a void return type.
};
