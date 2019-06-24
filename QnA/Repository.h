#pragma once
#include "Question.h"
#include "Answer.h"
#include <vector>
#include <iostream>
#include  <fstream>
class Repository
{
private:
	vector<Question*> questions;
	vector<Answer*> answers;
public:
	Repository();
	~Repository() = default;
	vector<Question*> getQuestions();



	/*
	 * Returns a vector that contains all answers to a given question
	 * Input: int qId - the id of the question we want answers for
	 * Output: vector<Answer*> - vector of answers to that given question
	 */
	vector<Answer*> getAnswers(int qId);
	vector<Question*> getFewQuestions(string& in);
	int getNoAnswers(int pos);
	void savefiles();
	void sortAnswers();
	void sortQuestions();


	
	void addAnswer(string& u, int question, string& text);

	/*
	 *Adds a Question
	 *Input: string& n - name of the person who asked the question
	 *		 string& t - the question itself
	 *Output: -
	 *Throws: exception if the text has size 0
	 */
	void addQuestion(string& n, string& t);
	
	void upVote(int pos);
	void downVote(int pos);
	
};

