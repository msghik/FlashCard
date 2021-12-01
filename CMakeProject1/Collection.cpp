#include "CMakeProject1.h"
#include "Cards.h"
#include <iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include "Collection.h"
using namespace std;
void Collection::addCard(Card& card)
{
	this->New.push_back(card);
}

bool Collection::isEmpty()
{
	if(this->New.size()==0 && this->Learning.size()==0 && this->Mastered.size()==0)
		return true;
	return false;
}

void Collection::ShowNewWords()
{
	cout << "These are the New Words"<<endl;
	for (Card a : New) {
		cout << "*************************" << endl;
		cout << a<<endl;
		cout << "*************************" << endl;
	}
}

void Collection::ShowLearningWords()
{
	cout << "These are the Words You are Learning :"<<endl;
	for (Card a : Learning) {
		cout << "*************************"<<endl;
		cout << a << endl;
		cout << "*************************" << endl;
	}
}

void Collection::ShowMasteredWords()
{
	cout << "These are the words You are Mastered At :"<<endl;
	for (Card a : Mastered) {
		cout << "*************************" << endl;
		cout << a << endl;
		cout << "*************************" << endl;
	}
}

bool Collection::DeleteCard(string& card)
{
	bool find = false;
	for (int i = 0; i < New.size(); i++) {
		if (New[i].getWord() == card) {
			find = true;
			New.erase(New.begin()+i);
			return find;
		}
	}

	for (int i = 0; i < Learning.size(); i++) {
		if (Learning[i].getWord() == card) {
			find = true;
			Learning.erase(Learning.begin() + i);
			return find;
		}
	}

	for (int i = 0; i < Mastered.size(); i++) {
		if (Mastered[i].getWord() == card) {
			find = true;
			Mastered.erase(Mastered.begin() + i);
			return find; 
		}
	}
	return find;
}

void Collection::Justify(Card& card)
{
	if (card.getCorrectAnswers() > 1 && card.getCorrectAnswers()<5) {
		Learning.push_back(card);
		DeleteCard(card.getWord());
	}
	else if (card.getCorrectAnswers() >= 5) {
		Mastered.push_back(card);
		DeleteCard(card.getWord());
	}
}

int Collection::newWordsSize()
{
	return New.size();
}

int Collection::learningWordsSize()
{
	return Learning.size();
}

int Collection::masteredWordsSize()
{
	return Mastered.size();
}

Card Collection::getaNewWord()
{
	return New[rand()%New.size()];
}

Card Collection::getaLearningWord()
{
	return Learning[rand() % Learning.size()];
}

Card Collection::getaMasteredWord()
{
	return Mastered[rand() % Mastered.size()];
}
