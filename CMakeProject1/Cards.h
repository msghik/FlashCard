#pragma once
#include "CMakeProject1.h"
#include <iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class Card {
    friend istream& operator>>(istream& in, Card& card);
    friend ostream& operator<<(ostream& out, Card& card);
private:
  string Word;
  string Meaning;
  vector<string> Synonyms;
  int CorrectAnswers;
  void initializer() {
     CorrectAnswers = 0;
    this->Word = "";
    this->Meaning = "";
    this->Synonyms.clear();
  }

public:
  Card() {
      initializer();
  }
  Card(string word, string meaning, string synonym) {
      initializer();
      this->Word = word;
      this->Meaning = meaning;
      this->Synonyms.push_back(synonym);
  }
  Card(string word, string meaning) {
      initializer();
      this->Word = word;
      this->Meaning = meaning;
  }

  ~Card() {
    Synonyms.clear();
    initializer();
  }
  string getWord();
  string getMeaning();
  vector<string> getSynonyms();
  int getCorrectAnswers();

  void setWord(string word);
  void setMeaning(string meaning);
  void addSynonyms(string synonyms);
  void assignSynonyms(vector<string>& v);
  void increaseCorrectAnswer();
};