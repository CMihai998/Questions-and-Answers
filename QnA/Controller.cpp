#include "Controller.h"

Controller::Controller(Repository* r) : repo(r) {}

void Controller::addAnswer(string& u, int question, string& text)
{
	try {
	repo->addAnswer(u, question, text);
	notify();
	}catch (runtime_error& error)
	{
		throw error;
	}
}

void Controller::addQuestion(string& n, string& t)
{
	try {
		repo->addQuestion(n, t);
		notify();
	}catch (runtime_error& error)
	{
		throw error;
	}
}


void Controller::downVote(int pos)
{
	repo->downVote(pos);
	notify();
}


void Controller::upVote(int pos)
{
	repo->upVote(pos);
	notify();
}



vector<Question*> Controller::getQuestions()
{
	return repo->getQuestions();
}

vector<Answer*> Controller::getAnswers(int qId)
{
	return repo->getAnswers(qId);
}


