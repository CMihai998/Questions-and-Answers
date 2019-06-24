#include "UserGUI.h"

UserGUI::UserGUI(string& n, Controller* c,QWidget *parent)
	: QMainWindow(parent), control(c), name(n)
{
	
	ui.setupUi(this);
	
	this->setWindowTitle(QString::fromStdString(name));
	populate();
	ui.likes->setRange(-999, 999);
	
	connect(ui.askButton, SIGNAL(clicked()), this, SLOT(askQuestion()));
	connect(ui.questionsList, SIGNAL(itemSelectionChanged()), this, SLOT(displayAnswers()));
	connect(ui.answerButton, SIGNAL(clicked()), this, SLOT(answerQuestion()));
	connect(ui.answerList, SIGNAL(itemSelectionChanged()), this, SLOT(displayLikes()));
	connect(ui.likes, SIGNAL(valueChanged(int)), this, SLOT(changeLikes(int)));
}

void UserGUI::populate()
{
	ui.questionsList->clear();
	auto questions = control->getQuestions();
	for(int i=0;i<questions.size();i++)
	{
		QListWidgetItem* newEntry = new QListWidgetItem{ QString::fromStdString(questions[i]->toString()) };
		ui.questionsList->addItem(newEntry);
	}
	
}

void UserGUI::changeAllLikes()
{
	auto id = control->getQuestions()[lasSelectedQuestion]->getId();
	auto answers = control->getAnswers(id);
	int votes = answers[lastSelectedAnswer]->getVotes();
	ui.likes->disconnect();
	ui.likes->setValue(votes);
	connect(ui.likes, SIGNAL(valueChanged(int)), this, SLOT(changeLikes(int)));
}

void UserGUI::askQuestion()
{
	string input = ui.questionInput->text().toStdString();
	try {
		control->addQuestion(name, input);
		ui.questionInput->clear();
	}catch (runtime_error& err)
	{
		QMessageBox error;
		error.critical(NULL, "ERROR 404", err.what());
	}
}

void UserGUI::answerQuestion()
{
	try {
	int question = ui.questionsList->currentIndex().row();
	auto id = control->getQuestions()[question]->getId();
	auto answer = ui.answerInput->text().toStdString();
	ui.answerInput->clear();
	control->addAnswer(name, id, answer);
	}catch (runtime_error& err)
	{
		QMessageBox error;
		error.critical(NULL, "ERROR 404", err.what());
	}
}

void UserGUI::displayAnswers()
{
	ui.answerList->setItemSelected(NULL,false);
	ui.answerList->clear();
	int question = ui.questionsList->currentIndex().row();
	auto id = control->getQuestions()[question]->getId();
	auto answers = control->getAnswers(id);
	for(int i=0;i<answers.size();i++)
	{
		if(answers[i]->getUser() != name)
		{
			QListWidgetItem* newEntry = new QListWidgetItem{ QString::fromStdString(answers[i]->toString()) };
			ui.answerList->addItem(newEntry);
		}
		else
		{
			QListWidgetItem* newEntry = new QListWidgetItem{ QString::fromStdString(answers[i]->toString()) };
			newEntry->setBackgroundColor(QColor(Qt::GlobalColor::yellow));
			ui.answerList->addItem(newEntry);
		}
	}
}

void UserGUI::displayLikes()
{
	ui.likes->setEnabled(true);
	
	int question = ui.questionsList->currentIndex().row();
	auto id = control->getQuestions()[question]->getId();
	auto answers = control->getAnswers(id);

	int answer = ui.answerList->currentIndex().row();

	lastSelectedAnswer = answer;
	lasSelectedQuestion = question;
	if (answers[lastSelectedAnswer]->getUser() == name)
		ui.likes->setDisabled(true);
	int votes = answers[lastSelectedAnswer]->getVotes();
	ui.likes->disconnect();
	ui.likes->setValue(votes);
	connect(ui.likes, SIGNAL(valueChanged(int)), this, SLOT(changeLikes(int)));

	//ui.answerList->setItemSelected(NULL,false);
	ui.answerList->clearSelection();
	ui.answerList->clearFocus();
}



void UserGUI::changeLikes(int value)
{
	auto id = control->getQuestions()[lasSelectedQuestion]->getId();
	auto answers = control->getAnswers(id);
	int idQ = answers[lastSelectedAnswer]->getId();
	if (value > answers[lastSelectedAnswer]->getVotes())
		control->upVote(idQ);
	else
		control->downVote(idQ);
	
}






