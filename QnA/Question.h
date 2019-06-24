#pragma once
#include <string>
using namespace std;
class Question
{
private:
	int id;
	string text;
	string name;
public:
	Question(string& n, string& t, int id);
	Question(const Question& q);
	~Question() = default;

	string toString() const;
	int getId() const;
	string getUser() const;
	string getText() const;
};

