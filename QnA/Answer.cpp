#include "Answer.h"

Answer::Answer(string& u, int question, int id, string& text): id(id), qId(question), user(u), text(text), votes(0){}

Answer::Answer(string& u, int question, int id, string& text, int votes): id(id), qId(question), user(u), text(text), votes(votes){}

Answer::Answer(const Answer& a)
{
	id = a.getId();
	qId = a.getQId();
	user = a.getUser();
	votes = a.getVotes();
	text = a.getText();
}

string Answer::toString() const
{
	return to_string(id) + " by " + user + ": " + text + "(Votes:" + to_string(votes) + ")";
}

void Answer::upVote()
{
	votes++;
}

void Answer::downVote()
{
	votes--;
}

string Answer::getUser() const
{
	return user;
}

int Answer::getQId() const
{
	return qId;
}

int Answer::getId() const
{
	return qId;
}

string Answer::getText() const
{
	return text;
}

int Answer::getVotes() const
{
	return votes;
}


