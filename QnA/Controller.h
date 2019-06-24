#pragma once
#include "Observer.h"
#include "Repository.h"
class Controller :
	public Subject
{
private:
	Repository* repo;
public:
	Controller(Repository* r);
	~Controller() = default;
	void addAnswer(string& u, int question, string& text);
	void addQuestion(string& n, string& t);
	void upVote(int pos);
	void downVote(int pos);
	vector<Answer*> getAnswers(int qId);
	vector<Question*> getQuestions();
};

