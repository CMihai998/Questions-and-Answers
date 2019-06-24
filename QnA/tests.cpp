#include "Repository.h"
#include "assert.h"
#include <qvariant.h>
#include <string>

void test()
{
	Repository* repo = new Repository;
	auto questions = repo->getQuestions();
	repo->addQuestion(std::string{ "Mihai" }, std::string{ "Am fost adaugat de la teste nu?" });
	assert(repo->getQuestions().size() == 10);
	assert(repo->getAnswers(2).size() == 0);
}
