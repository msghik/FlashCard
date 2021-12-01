#include "CMakeProject1.h"
#include "Cards.h"

string Card::getWord()
{
	return string(this->Word);
}

string Card::getMeaning()
{
	return this->Meaning;
}

vector<string> Card::getSynonyms()
{
	return Synonyms;
}

int Card::getCorrectAnswers()
{
	return this->CorrectAnswers;
}

void Card::setWord(string word)
{
	this->Word = word;
}

void Card::setMeaning(string meaning)
{
	this->Meaning = meaning;
}

void Card::addSynonyms(string synonym)
{
	this->Synonyms.push_back(synonym);
}

void Card::assignSynonyms(vector<string>& v)
{
	this->Synonyms = v;
}

void Card::increaseCorrectAnswer()
{
	this->CorrectAnswers++;
}

void Card::increaseCorrectAnswerBy(int number)
{
	if (this->CorrectAnswers == 0) {
		return;
	}
	this->CorrectAnswers += number;
	return ;
}

istream& operator>>(istream& in, Card& card)
{
	string word, meaning, synonym;
	cout << "insert The Word :";
	in >> word;
	cout << "insert The Meaning :";
	in >> meaning;
	cout << "insert one Synonyms (put . if it's finished ) ";
	in >> synonym;
	while (synonym != ".") {
		card.addSynonyms(synonym);
		in >> synonym;
	}
	card.setWord(word);
	card.setMeaning(meaning);
	return in;
}

ostream& operator<<(ostream& out, Card& card)
{
	out << "Word : " << card.getWord() << endl;
	out << "Meaning : " << card.getMeaning() << endl;
	out << "Synonyms :";
	for (auto a : card.Synonyms) {
		out << a << " ";
	}
	return out;
}
