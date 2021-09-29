/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 2 - Tutnese Translation Continued
 * This is the implementation .cpp file for the Model class. Used for translating a single or doubled character from english into tutnese.
*/
#include "Model.h"

Model::Model() { // default constructor body, it's empty

}

Model::~Model() { // destructor body, it's empty

}

string Model::translateSingleCharacter(char englishSingleChar) { // takes a single character as input and returns a string representing its encoding in Tutnese. Capitalization is preserved.
  if (englishSingleChar == 'B') {
    return "Bub";
  } else if (englishSingleChar == 'b') {
    return "bub";
  } else if (englishSingleChar == 'C') {
    return "Cash";
  } else if (englishSingleChar == 'c') {
    return "cash";
  } else if (englishSingleChar == 'D') {
    return "Dud";
  } else if (englishSingleChar == 'd') {
    return "dud";
  } else if (englishSingleChar == 'F') {
    return "Fuf";
  } else if (englishSingleChar == 'f') {
    return "fuf";
  } else if (englishSingleChar == 'G') {
    return "Gug";
  } else if (englishSingleChar == 'g') {
    return "gug";
  } else if (englishSingleChar == 'H') {
    return "Hash";
  } else if (englishSingleChar == 'h') {
    return "hash";
  } else if (englishSingleChar == 'J') {
    return "Jay";
  } else if (englishSingleChar == 'j') {
    return "jay";
  } else if (englishSingleChar == 'K') {
    return "Kuck";
  } else if (englishSingleChar == 'k') {
    return "kuck";
  } else if (englishSingleChar == 'L') {
    return "Lul";
  } else if (englishSingleChar == 'l') {
    return "lul";
  } else if (englishSingleChar == 'M') {
    return "Mum";
  } else if (englishSingleChar == 'm') {
    return "mum";
  } else if (englishSingleChar == 'N') {
    return "Nun";
  } else if (englishSingleChar == 'n') {
    return "nun";
  } else if (englishSingleChar == 'P') {
    return "Pub";
  } else if (englishSingleChar == 'p') {
    return "pub";
  } else if (englishSingleChar == 'Q') {
    return "Quack";
  } else if (englishSingleChar == 'q') {
    return "quack";
  } else if (englishSingleChar == 'R') {
    return "Rug";
  } else if (englishSingleChar == 'r') {
    return "rug";
  } else if (englishSingleChar == 'S') {
    return "Sus";
  } else if (englishSingleChar == 's') {
    return "sus";
  } else if (englishSingleChar == 'T') {
    return "Tut";
  } else if (englishSingleChar == 't') {
    return "tut";
  } else if (englishSingleChar == 'V') {
    return "Vuv";
  } else if (englishSingleChar == 'v') {
    return "vuv";
  } else if (englishSingleChar == 'W') {
    return "Wack";
  } else if (englishSingleChar == 'w') {
    return "wack";
  } else if (englishSingleChar == 'X') {
    return "Ex";
  } else if (englishSingleChar == 'x') {
    return "ex";
  } else if (englishSingleChar == 'Y') {
    return "Yub";
  } else if (englishSingleChar == 'y') {
    return "yub";
  } else if (englishSingleChar == 'Z') {
    return "Zub";
  } else if (englishSingleChar == 'z') {
    return "zub";
  } else { // for non-consonant characters such as a vowels, periods, question marks, etc.
    string retur;
    return retur + englishSingleChar; // simply returns the english character
  }
}

string Model::translateDoubleCharacter(char englishDoubleChar) { // takes a single character as input that appears twice in a row and returns a string representing its encoding in Tutnese. Capitalization is preserved.
  if (englishDoubleChar == 'B' || englishDoubleChar == 'C' || englishDoubleChar == 'D' || englishDoubleChar == 'F' || englishDoubleChar == 'G' || englishDoubleChar == 'H' ||
  englishDoubleChar == 'J' || englishDoubleChar == 'K' || englishDoubleChar == 'L' || englishDoubleChar == 'M' || englishDoubleChar == 'N' || englishDoubleChar == 'P' ||
  englishDoubleChar == 'Q' || englishDoubleChar == 'R' || englishDoubleChar == 'S' || englishDoubleChar == 'T' ||  englishDoubleChar == 'V' || englishDoubleChar == 'W' ||
  englishDoubleChar == 'X' || englishDoubleChar == 'Y' || englishDoubleChar == 'Z') {
    return "Squa"; // for upper case double consonants
  } else if (englishDoubleChar == 'b' || englishDoubleChar == 'c' || englishDoubleChar == 'd' || englishDoubleChar == 'f' || englishDoubleChar == 'g' || englishDoubleChar == 'h' ||
  englishDoubleChar == 'j' || englishDoubleChar == 'k' || englishDoubleChar == 'l' || englishDoubleChar == 'm' || englishDoubleChar == 'n' || englishDoubleChar == 'p' ||
  englishDoubleChar == 'q' || englishDoubleChar == 'r' || englishDoubleChar == 's' || englishDoubleChar == 't' || englishDoubleChar == 'v' || englishDoubleChar == 'w' ||
  englishDoubleChar == 'x' || englishDoubleChar == 'y' || englishDoubleChar == 'z') {
    return "squa"; // for lower case double consonants
  } else if (englishDoubleChar == 'A' || englishDoubleChar == 'E' || englishDoubleChar == 'I' || englishDoubleChar == 'O' || englishDoubleChar == 'U') {
    return "Squat"; // for upper case double vowels
  } else if (englishDoubleChar == 'a' || englishDoubleChar == 'e' || englishDoubleChar == 'i' || englishDoubleChar == 'o' || englishDoubleChar == 'u') {
    return "squat"; // for lower case double vowels
  } else {
    return "" + englishDoubleChar; //returns english character
  }
}
