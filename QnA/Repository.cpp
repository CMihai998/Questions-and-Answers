#include "Repository.h"
#include <sstream>

std::vector<std::string> tokenize(std::string input, char delimiter)
{
    std::stringstream stream(input);

    std::vector<std::string> result;
    std::string token;

    while (getline(stream, token, delimiter))
        result.push_back(token);

    return result;
}
Repository::Repository()
{
	string line;
	ifstream qInput, aInput;

	qInput.open("questions.txt", ios::in);
	while(getline(qInput, line))
	{
		auto fields = tokenize(line, ',');
		questions.push_back(new Question{ fields[0], fields[1], stoi(fields[2])});
	}
	qInput.close();

	aInput.open("answers.txt", ios::in);
	while(getline(aInput, line))
	{
		auto fields = tokenize(line, ',');
		answers.push_back(new Answer{ fields[0],stoi(fields[1]), stoi(fields[2]), fields[3], stoi(fields[4]) });
	}
	aInput.close();
	sortQuestions();
	sortAnswers();
}

vector<Question*> Repository::getQuestions()
{
	return questions;
}

vector<Answer*> Repository::getAnswers(int qId)
{
	vector<Answer*> result;
	for (int i = 0; i < answers.size(); i++)
		if (answers[i]->getQId() == qId)
			result.push_back(answers[i]);
	return result;
}

vector<Question*> Repository::getFewQuestions(string& in)
{
	vector<Question*> result;
	for (int i = 0; i < questions.size(); i++)
		if (!questions[i]->getText().find(in))
			result.push_back(questions[i]);
	return result;
}

void Repository::savefiles()
{
	ofstream qOutput, aOutput;

	qOutput.open("questions.txt", ios::out);
	for (int i = 0; i < questions.size(); i++)
		qOutput << questions[i]->getUser() + "," + questions[i]->getText() + "," + to_string(questions[i]->getId()) + "\n";
	qOutput.close();

	aOutput.open("answers.txt", ios::out);
	for (int i = 0; i < answers.size(); i++)
		aOutput << answers[i]->getUser() + "," + to_string(answers[i]->getQId()) + "," + to_string(answers[i]->getId()) + "," + answers[i]->getText() + "," + to_string(answers[i]->getVotes()) + "\n";
	aOutput.close();
}

void Repository::sortAnswers()
{
	for(int i=0; i<answers.size()-1; i++)
		for(int j=i+1;j<answers.size(); j++)
			if(answers[i]->getVotes() < answers[j]->getVotes())
			{
				auto aux = answers[i];
				answers[i] = answers[j];
				answers[j] = aux;
			}
}

void Repository::sortQuestions()
{
	for(int i=0;i<questions.size()-1;i++)
		for(int j=i+1;j<questions.size();j++)
			if(getNoAnswers(i)<getNoAnswers(j))
			{
				auto aux = questions[i];
				questions[i] = questions[j];
				questions[j] = aux;
			}
}

void Repository::addAnswer(string& u, int question, string& text)
{
	if (text.size() != 0) {
		int id = answers.size() + 1;
		answers.push_back(new Answer{ u,question,id,text });
		sortAnswers();
		sortQuestions();
		savefiles();
	}
	else { throw runtime_error{ "Input not found!" }; }
}

void Repository::addQuestion(string& n, string& t)
{
	if (t.size() != 0) {
		int id = questions.size() + 1;
		questions.push_back(new Question{ n,t,id });
		sortQuestions();
		savefiles();
	}
	else { throw runtime_error{ "Input not found!" }; }
}

void Repository::upVote(int pos)
{
	int position = 0;
	while (answers[position]->getId() != pos)
		position++;
	answers[position]->upVote();
	sortAnswers();
	savefiles();
}

void Repository::downVote(int pos)
{
	int position = 0;
	while (answers[position]->getId() != pos)
		position++;
	answers[position]->downVote();
	sortAnswers();
	savefiles();
}

int Repository::getNoAnswers(int pos)
{
	int count = 0;
	for (int i = 0; i < answers.size(); i++)
		if (questions[pos]->getId() == answers[i]->getQId())
			count++;
	return count;
}




