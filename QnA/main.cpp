#include "UserGUI.h"
#include <QtWidgets/QApplication>
#include "SearchGUI.h"
#include <assert.h>



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository* repo = new Repository;
	Controller* control = new Controller(repo);
	vector<UserGUI*> users;
	ifstream userInput;
	
	userInput.open("users.txt", ios::in);
	string line;
	while(getline(userInput, line))
	{
		users.push_back(new UserGUI{ line,control });
	}
	userInput.close();

	for (int i = 0; i < users.size(); i++) {
		control->addObserver(users[i]);
		users[i]->show();
	}

	searchGUI* search = new searchGUI{ repo };
	search->show();

	control->addObserver(search);

	//tests
	assert(repo->getAnswers(2).size() == 0);
	assert(repo->getQuestions().size() == 9);


	return a.exec();
}

