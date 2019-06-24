#pragma once
#include <string>
using namespace std;
class Answer
{
private:
	int id;
	int qId;
	string user;
	string text;
	int votes;
public:
	Answer(string& u, int question, int id, string& text);
	Answer(string& u, int question, int id, string& text, int votes);
	Answer(const Answer& a);
	~Answer() = default;
	string toString() const;
	void upVote();
	void downVote();
	string getUser() const;
	int getQId() const;
	int getId() const;
	int getVotes() const;
	string getText() const;
};

