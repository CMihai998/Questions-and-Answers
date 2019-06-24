#include "Question.h"

Question::Question(string& n, string& t, int id): name(n), text(t), id(id){}

Question::Question(const Question& q)
{
	id = q.getId();
	name = q.getUser();
	text = q.getText();
}

string Question::toString() const
{
	return name + " asks: " + text;
}

int Question::getId() const
{
	return id;
}

string Question::getUser() const
{
	return name;
}

string Question::getText() const
{
	return text;
}

