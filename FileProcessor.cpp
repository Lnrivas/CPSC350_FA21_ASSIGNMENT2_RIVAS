/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 2 - Tutnese Translation Continued
 * This is the implementation .cpp file for the FileProcessor class. Used for file processing, reading from one file and then writing the tutnese or english translation to output file.
*/
#include "FileProcessor.h"
#include "Translator.h" // for access to methods in Translator

FileProcessor::FileProcessor() { // default constructor body, it's empty

}

FileProcessor::~FileProcessor() { // destructor body, it's empty

}

void FileProcessor::processFile(string inputFile, string outputFile) {// takes string representing the input file (English) and a string representing the output file (where the Tutnese translation will be written).
  fstream fileStream;
  fileStream.open(inputFile, ios::in); // opens inputFile in read mode
  fileStream >> noskipws; // allows " " to be read correctly
  char character; // each character from the input file will be read into this variable
  string englishSentence; // Will hold one english sentence at a time
  string fullTutneseTranslation = "";

	if (fileStream.fail()) { // checks if file was opened incorrectly
		cout << "Input file not opened!" << endl;
	}
	else { // if file was opened correctly
		cout << "Input file opened successfully!" << endl;
    while (true) { // loops through entire file, character by character, until the end is reached
			fileStream >> character;
      englishSentence += character; // every character from the file is added to englishSentence
      if (character == '.' || character == '?' || character == '!' || fileStream.eof()) { // if end of a sentence is reached in the english input file
        Translator t; // creates Translator object to be able to use it's methods
        fullTutneseTranslation += t.translateEnglishSentence(englishSentence); // translates each english sentence one by one, adding each translation to fullTutneseTranslation
        englishSentence = ""; // clears englishSentence variable so it can store the next sentence
      }
			if (fileStream.eof()) { //breaks out of loop once the entire file has been read.
        break;
      }
		}
		fileStream.close();
    fileStream.clear();
	}

  fileStream.open(outputFile, ios::out); // opens outputFile in write mode
  if (fileStream.fail()) { // checks if file was opened incorrectly
		cout << "Output file not opened!" << endl;
	}
	else { // if file was opened correctly
    cout << "Output file opened successfully!" << endl;
		fileStream << fullTutneseTranslation; // adds fullTutneseTranslation to output file all at once
  }
  fileStream.close();
}

void FileProcessor::processFile(string tutInputFile, string englishOutputFile, char x) { //takes string representing the input file (tutnese) and a string representing the output file (where the english translation will be written).
  fstream fileStream;
  fileStream.open(tutInputFile, ios::in); // opens inputFile in read mode
  fileStream >> noskipws; // allows " " to be read correctly
  char character; // each character from the input file will be read into this variable
  string tutneseSentence; // Will hold one tutnese sentence at a time
  string fullEnglishTranslation = "";

  if (fileStream.fail()) { // checks if file was opened incorrectly
    cout << "Input file not opened!" << endl;
  }
  else { // if file was opened correctly
    cout << "Input file opened successfully!" << endl;
    while (true) { // loops through entire file, character by character, until the end is reached
      fileStream >> character;
      tutneseSentence += character; // every character from the file is added to englishSentence
      if (character == '.' || character == '?' || character == '!' || fileStream.eof()) { // if end of a sentence is reached in the english input file
        Translator t; // creates Translator object to be able to use it's methods
        fullEnglishTranslation += t.translateTutneseSentence(tutneseSentence); // translates each english sentence one by one, adding each translation to fullEnglishTranslation
        tutneseSentence = ""; // clears tutneseSentence variable so it can store the next sentence
      }
      if (fileStream.eof()) { //breaks out of loop once the entire file has been read.
        break;
      }
    }
    fileStream.close();
    fileStream.clear();
  }

  fileStream.open(englishOutputFile, ios::out); // opens outputFile in write mode
  if (fileStream.fail()) { // checks if file was opened incorrectly
    cout << "Output file not opened!" << endl;
  }
  else { // if file was opened correctly
    cout << "Output file opened successfully!" << endl;
    fileStream << fullEnglishTranslation; // adds fullEnglishTranslation to output file all at once
  }
  fileStream.close();
}
