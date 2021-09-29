/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 2 - Tutnese Translation Continued
 * This is the main file, where our main method lives. This program reads an english file from the command line and writes the tutnese translation to another file from the command line.
*/
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"

int main(int argc, char** argv) {
  FileProcessor *x = new FileProcessor(); // creates FileProcessor pointer to use its method processFile later
  string E2T = "E2T";
  string T2E = "T2E";
  if (argc == 4 && argv[3] == E2T) { // checks if correct amount of command line arguments were entered E2T is entered.
    x->processFile(argv[1], argv[2]); // reads english file from argv[1] and writes tutnese translation in file from argv[2]
  } else if (argc == 4 && argv[3] == T2E) { // checks if correct amount of command line arguments were entered T2E is entered.
    x->processFile(argv[1], argv[2], 'x'); // reads tutnese file from argv[1] and writes english translation in file from argv[2]
  } else { // if incorrect amount of command lines were entered
    cout << "Must enter 2 seperate file names and either T2E or T2E when running program." << endl;
  }
  delete x; // frees up spacce taken by FileProcessor x
  return 0;
}
