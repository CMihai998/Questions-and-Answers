#include "searchGUI.h"
#include <QMessageBox>
searchGUI::searchGUI(Repository* r, QWidget *parent)
	: QWidget(parent), repo(r)
{
	ui.setupUi(this);
	connect(ui.input, SIGNAL(textChanged(const QString &)), this, SLOT(searchSlot(const QString &)));
}

searchGUI::~searchGUI()
{
}

void searchGUI::update()
{
	auto input = ui.input->text();
	searchSlot(input);
}

void searchGUI::searchSlot(const QString &)
{
	ui.listWidget->clear();
	if (ui.input->text().size()) {
		string input = ui.input->text().toStdString();
		auto questions = repo->getFewQuestions(input);
		for (int i = 0; i < questions.size(); i++)
		{
			QListWidgetItem* newQieston = new QListWidgetItem{ QString::fromStdString(questions[i]->toString()) };
			newQieston->setBackgroundColor(QColor(Qt::GlobalColor::gray));
			ui.listWidget->addItem(newQieston);
			auto answers = repo->getAnswers(questions[i]->getId());
			for (int j = 0; j < 3 && j < answers.size(); j++)
			{
				QListWidgetItem* newAnswer = new QListWidgetItem{ QString::fromStdString("\t" + answers[j]->toString()) };
				ui.listWidget->addItem(newAnswer);
			}
		}
	}
}
