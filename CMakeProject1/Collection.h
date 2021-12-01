#include "CMakeProject1.h"
#include "Cards.h"
#include <iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
#pragma once

class Collection {
private :
	vector<Card> New;
	vector<Card> Learning;
	vector<Card> Mastered;
	void initializer() {
		New.clear();
		Learning.clear();
		Mastered.clear();
	}
public : 
	Collection() {
		initializer();
	}
	~Collection() {
		initializer();
	}

	void addCard(Card& card);
	bool isEmpty();
	void ShowNewWords();
	void ShowLearningWords();
	void ShowMasteredWords();
	bool DeleteCard(string& card);
	void Justify(Card& card);
	int newWordsSize();
	int learningWordsSize();
	int masteredWordsSize();
	Card getaNewWord();
	Card getaLearningWord();
	Card getaMasteredWord();
};
