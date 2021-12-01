// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"
using namespace std;

Collection FlashCard;

void Practicing() {
	system("cls");
	srand(time(0));
	if (FlashCard.isEmpty()) {
		cout << "There is no word !";
		getchar();
		return;
	}

	cout << "Welcome to FlashCard , Let's Start Practicing !" << endl;
	while (true) {
		for (int i = 0; i < 5; i++) {
			Card queryCard = FlashCard.getaNewWord();
			cout << queryCard.getWord()<<endl;
			cout << "Do you know this Word ?? [y/n]:";
			char What;
			cin >> What;
			if (What == 'y') {
				queryCard.increaseCorrectAnswer();
				cout << "Well Done!" << endl;
				FlashCard.Justify(queryCard);
			}
			else {
				cout << "Sorry to Hear that !"<<endl;
			}
		}

		for (int i = 0; i < 3; i++) {
			Card queryCard = FlashCard.getaLearningWord();
			cout << queryCard.getWord() << endl;
			cout << "Do you know this Word ?? [y/n]:";
			char What;
			cin >> What;
			if (What == 'y') {
				queryCard.increaseCorrectAnswer();
				cout << "Well Done!" << endl;
				FlashCard.Justify(queryCard);
			}
			else {
				cout << "Sorry to Hear that !"<<endl;
			}
		}

		Card queryCard = FlashCard.getaMasteredWord();
		cout << queryCard.getWord() << endl;
		cout << "Do you know this Word ?? [y/n]:";
		char What;
		cin >> What;
		if (What == 'y') {
			queryCard.increaseCorrectAnswer();
			cout << "Well Done!" << endl;
		}
		else {
			cout << "Sorry to Hear that !";
		}
	}
	return;
}

void NewWord() {
	system("cls");
	Card newCard;
	cin >> newCard;
	FlashCard.addCard(newCard);
	cout << "The Word Has been Added Successfully !" << endl;
	cout << "Presss Enter to Continue ;";
	getchar();
	getchar();
	return;
}

void DeleteWord() {
	system("cls");
	cout << "Enter the Word you wish to Delete . : ";
	string deleteCard;
	cin >> deleteCard;
	if (FlashCard.DeleteCard(deleteCard)) {
		cout << "The Word Has been Deleted Successfully !"<<endl;
	}
	else {
		cout << "There is no such a word " << endl;
	}
	cout << "Presss Enter to Continue ;";
	getchar();
	getchar();
	return;
}

void ShowAlltheWords() {
	system("cls");
	if (FlashCard.isEmpty()) {
		cout << "There is no words"<<endl;
		cout << "Press Enter to Continue .";
		getchar();
		getchar();
		return;
	}
	FlashCard.ShowNewWords();
	FlashCard.ShowLearningWords();
	FlashCard.ShowMasteredWords();
	cout << "Press Enter to Continue .";
	getchar();
	getchar();
}

void start() {
	while (true) {
		system("cls");
		cout << "................................................." << endl;
		cout << "Wellcome to FastFlashCard!!!!" << endl;
		cout << "................................................." << endl;
		cout << "Here is The Menu SIR !!!" << endl;
		cout << "1. Start Practicing ." << endl;
		cout << "2. Add a new word . " << endl;
		cout << "3. Delete a Word . " << endl;
		cout << "4. Show All the Words ." << endl;
		int decide;
		cout << "Choose : ";
		cin >> decide;
		switch (decide) {
		case 1:Practicing(); break;
		case 2:NewWord(); break;
		case 3:DeleteWord(); break;
		case 4: ShowAlltheWords(); break;
		default:
			cout << "Invalid";
		}
	}
}



int main()
{
	start();
	return 0;
}
