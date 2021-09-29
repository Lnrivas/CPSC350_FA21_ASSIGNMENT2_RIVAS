/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 2 - Tutnese Translation Continued
 * This is the implementation .cpp file for the Translator class. Used for translating an english word into a tutnese word and translating an english sentence into a tutnese sentence. Also does all that from tutnese to english.
*/
#include "Translator.h"
#include "Model.h" // for access to methods from Model

Translator::Translator() { // default constructor body, it's empty

}

Translator::~Translator() { // destructor body, it's empty

}

string Translator::translateEnglishWord(string englishWord) { // takes a single string representing a single English word as input and returns a string representing the Tutnese translation.
  string ret = "";
  Model m; // makes Model object to use the methods from the Model class
  for (int i = 0; i < englishWord.size(); ++i) { // iterates through the english word, letter by letter
    if (i < englishWord.size()-1 && englishWord[i] == englishWord[i+1]) { // for the first letter in a double letter sequence
       ret += m.translateDoubleCharacter(englishWord[i]);
    } else { // for any other character
      ret += m.translateSingleCharacter(englishWord[i]);
    }
  }
  return ret; // returns the translated word.
}

string Translator::translateEnglishSentence(string englishSentence) { // takes a single string representing a single English sentence as input and returns a string representing the Tutnese translation. Accounts for punctuation.
  string out = "";
  string word = "";
  for (int i = 0; i < englishSentence.size(); ++i) { // iterates through the english sentence, character by character
    word += englishSentence[i]; // adds each letter to "word"
    if (englishSentence[i] == ' ' || i == englishSentence.size()-1) { // if " " is encountered or end of sentence is reached aka a full word have been iterated through and added to "word"
      out += translateEnglishWord(word); // translates word saved in "word" variable to tutnese and saves it in "out" variable
      word = ""; // clears "word" variable so it is ready to store the next word.
    }
  }
  return out; // returns the translated sentence.
}

string Translator::translateTutneseWord(string tutneseWord) { // new to ass 2  takes a single string representing a single tutnese word as input and returns a string representing the english translation.
  string ret = "";
  for (int i = 0; i < tutneseWord.size(); ++i) { // iterates through the tutnese word, letter by letter
    if (tutneseWord[i] == 's' && tutneseWord[i+1] == 'q' && tutneseWord[i+2] == 'u' && tutneseWord[i+3] == 'a' && tutneseWord[i+4] == 't' &&
    tutneseWord[i+5] == 'u' && tutneseWord[i+6] == 't' && i < tutneseWord.size()-6) { //for weird edge case
      ret += "tt";
      i += 6;
    } else if (tutneseWord[i] == 'S' && tutneseWord[i+1] == 'q' && tutneseWord[i+2] == 'u' && tutneseWord[i+3] == 'a' && tutneseWord[i+4] == 't' &&
    (tutneseWord[i+5] == 'a' || tutneseWord[i+5] == 'e' || tutneseWord[i+5] == 'i' || tutneseWord[i+5] == 'o' || tutneseWord[i+5] == 'u') && i < tutneseWord.size()-5) { // CHECK FOR upper DOUBLE vowel HERE?
       ret += toupper(tutneseWord[i+5]);
       i += 4;
     } else if (tutneseWord[i] == 's' && tutneseWord[i+1] == 'q' && tutneseWord[i+2] == 'u' && tutneseWord[i+3] == 'a' && tutneseWord[i+4] == 't' &&
     (tutneseWord[i+5] == 'a' || tutneseWord[i+5] == 'e' || tutneseWord[i+5] == 'i' || tutneseWord[i+5] == 'o' || tutneseWord[i+5] == 'u') && i < tutneseWord.size()-5) { // CHECK FOR lower DOUBLE vowel HERE?
       ret += tutneseWord[i+5];
       i += 4;
     } else if (tutneseWord[i] == 'S' && tutneseWord[i+1] == 'q' && tutneseWord[i+2] == 'u' && tutneseWord[i+3] == 'a' && i < tutneseWord.size()-4) { // CHECK FOR upper DOUBLE consonant HERE?
       ret += toupper(tutneseWord[i+4]);
       i += 3;
     } else if (tutneseWord[i] == 's' && tutneseWord[i+1] == 'q' && tutneseWord[i+2] == 'u' && tutneseWord[i+3] == 'a' && i < tutneseWord.size()-4) { // CHECK FOR lower DOUBLE consonant HERE?
       ret += tutneseWord[i+4];
       i += 3;
     } else if (tutneseWord[i] == 'B' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'b' && i < tutneseWord.size()-2) { //for B
       ret += 'B';
       i += 2;
     } else if (tutneseWord[i] == 'b' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'b' && i < tutneseWord.size()-2) { //for b
       ret += 'b';
       i += 2;
     } else if (tutneseWord[i] == 'C' && tutneseWord[i+1] == 'a' && tutneseWord[i+2] == 's' && tutneseWord[i+3] == 'h' && i < tutneseWord.size()-3) { // for C
       ret += 'C';
       i += 3;
     } else if (tutneseWord[i] == 'c' && tutneseWord[i+1] == 'a' && tutneseWord[i+2] == 's' && tutneseWord[i+3] == 'h' && i < tutneseWord.size()-3) { // for c
       ret += 'c';
       i += 3;
     } else if (tutneseWord[i] == 'D' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'd' && i < tutneseWord.size()-2) { //for D
       ret += 'D';
       i += 2;
     } else if (tutneseWord[i] == 'd' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'd' && i < tutneseWord.size()-2) { //for d
       ret += 'd';
       i += 2;
     } else if (tutneseWord[i] == 'F' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'f' && i < tutneseWord.size()-2) { //for F
       ret += 'F';
       i += 2;
     } else if (tutneseWord[i] == 'f' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'f' && i < tutneseWord.size()-2) { //for f
       ret += 'f';
       i += 2;
     } else if (tutneseWord[i] == 'G' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'g' && i < tutneseWord.size()-2) { //for G
       ret += 'G';
       i += 2;
     } else if (tutneseWord[i] == 'g' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'g' && i < tutneseWord.size()-2) { //for g
       ret += 'g';
       i += 2;
     } else if (tutneseWord[i] == 'H' && tutneseWord[i+1] == 'a' && tutneseWord[i+2] == 's' && tutneseWord[i+3] == 'h' && i < tutneseWord.size()-3) { // for H
       ret += 'H';
       i += 3;
     } else if (tutneseWord[i] == 'h' && tutneseWord[i+1] == 'a' && tutneseWord[i+2] == 's' && tutneseWord[i+3] == 'h' && i < tutneseWord.size()-3) { // for h
       ret += 'h';
       i += 3;
     } else if (tutneseWord[i] == 'J' && tutneseWord[i+1] == 'a' && tutneseWord[i+2] == 'y' && i < tutneseWord.size()-2) { //for J
       ret += 'J';
       i += 2;
     } else if (tutneseWord[i] == 'j' && tutneseWord[i+1] == 'a' && tutneseWord[i+2] == 'y' && i < tutneseWord.size()-2) { //for j
       ret += 'j';
       i += 2;
     } else if (tutneseWord[i] == 'K' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'c' && tutneseWord[i+3] == 'k' && i < tutneseWord.size()-3) { // for K
       ret += 'K';
       i += 3;
     } else if (tutneseWord[i] == 'k' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'c' && tutneseWord[i+3] == 'k' && i < tutneseWord.size()-3) { // for k
       ret += 'k';
       i += 3;
     } else if (tutneseWord[i] == 'L' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'l' && i < tutneseWord.size()-2) { //for L
       ret += 'L';
       i += 2;
     } else if (tutneseWord[i] == 'l' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'l' && i < tutneseWord.size()-2) { //for l
       ret += 'l';
       i += 2;
     } else if (tutneseWord[i] == 'M' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'm' && i < tutneseWord.size()-2) { //for M
       ret += 'M';
       i += 2;
     } else if (tutneseWord[i] == 'm' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'm' && i < tutneseWord.size()-2) { //for m
       ret += 'm';
       i += 2;
     } else if (tutneseWord[i] == 'N' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'n' && i < tutneseWord.size()-2) { //for N
       ret += 'N';
       i += 2;
     } else if (tutneseWord[i] == 'n' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'n' && i < tutneseWord.size()-2) { //for n
       ret += 'n';
       i += 2;
     } else if (tutneseWord[i] == 'P' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'b' && i < tutneseWord.size()-2) { //for P
       ret += 'P';
       i += 2;
     } else if (tutneseWord[i] == 'p' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'b' && i < tutneseWord.size()-2) { //for p
       ret += 'p';
       i += 2;
     } else if (tutneseWord[i] == 'Q' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'a' && tutneseWord[i+3] == 'c' && tutneseWord[i+4] == 'k' && i < tutneseWord.size()-4) { // for Q
       ret += 'Q';
       i += 4;
     } else if (tutneseWord[i] == 'q' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'a' && tutneseWord[i+3] == 'c' && tutneseWord[i+4] == 'k' && i < tutneseWord.size()-4) { // for q
       ret += 'q';
       i += 4;
     } else if (tutneseWord[i] == 'R' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'g' && i < tutneseWord.size()-2) { //for R
       ret += 'R';
       i += 2;
     } else if (tutneseWord[i] == 'r' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'g' && i < tutneseWord.size()-2) { //for r
       ret += 'r';
       i += 2;
     } else if (tutneseWord[i] == 'S' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 's' && i < tutneseWord.size()-2) { //for S
       ret += 'S';
       i += 2;
     } else if (tutneseWord[i] == 's' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 's' && i < tutneseWord.size()-2) { //for s
       ret += 's';
       i += 2;
     } else if (tutneseWord[i] == 'T' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 't' && i < tutneseWord.size()-2) { //for T
       ret += 'T';
       i += 2;
     } else if (tutneseWord[i] == 't' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 't' && i < tutneseWord.size()-2) { //for t
       ret += 't';
       i += 2;
     } else if (tutneseWord[i] == 'V' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'v' && i < tutneseWord.size()-2) { //for V
       ret += 'V';
       i += 2;
     } else if (tutneseWord[i] == 'v' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'v' && i < tutneseWord.size()-2) { //for v
       ret += 'v';
       i += 2;
     } else if (tutneseWord[i] == 'W' && tutneseWord[i+1] == 'a' && tutneseWord[i+2] == 'c' && tutneseWord[i+3] == 'k' && i < tutneseWord.size()-3) { // for W
       ret += 'W';
       i += 3;
     } else if (tutneseWord[i] == 'w' && tutneseWord[i+1] == 'a' && tutneseWord[i+2] == 'c' && tutneseWord[i+3] == 'k' && i < tutneseWord.size()-3) { // for w
       ret += 'w';
       i += 3;
     } else if (tutneseWord[i] == 'E' && tutneseWord[i+1] == 'x' && i < tutneseWord.size()-1) { //for X
       ret += 'X';
       i += 1;
     } else if (tutneseWord[i] == 'e' && tutneseWord[i+1] == 'x' && i < tutneseWord.size()-1) { //for x
       ret += 'x';
       i += 1;
     } else if (tutneseWord[i] == 'Y' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'b' && i < tutneseWord.size()-2) { //for Y
       ret += 'Y';
       i += 2;
     } else if (tutneseWord[i] == 'y' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'b' && i < tutneseWord.size()-2) { //for y
       ret += 'y';
       i += 2;
     } else if (tutneseWord[i] == 'Z' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'b' && i < tutneseWord.size()-2) { //for Z
       ret += 'Z';
       i += 2;
     } else if (tutneseWord[i] == 'z' && tutneseWord[i+1] == 'u' && tutneseWord[i+2] == 'b' && i < tutneseWord.size()-2) { //for z
       ret += 'z';
       i += 2;
     } else { // for any other character
      ret += tutneseWord[i];
    }
  }
  return ret; // returns the translated word.
}

string Translator::translateTutneseSentence(string tutneseSentence) { // takes a single string representing a single tutnese sentence as input and returns a string representing the english translation. Accounts for punctuation.
  string out = "";
  string word = "";
  for (int i = 0; i < tutneseSentence.size(); ++i) { // iterates through the english sentence, character by character
    word += tutneseSentence[i]; // adds each letter to "word"
    if (tutneseSentence[i] == ' ' || i == tutneseSentence.size()-1) { // if " " is encountered or end of sentence is reached aka a full word have been iterated through and added to "word"
      out += translateTutneseWord(word); // translates word saved in "word" variable to english and saves it in "out" variable
      word = ""; // clears "word" variable so it is ready to store the next word.
    }
  }
  return out; // returns the translated sentence.
}
