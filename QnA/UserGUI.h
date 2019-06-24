#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_UserGUI.h"
#include "GeneratedFiles/ui_UserGUI.h"
#include "Observer.h"
#include "Controller.h"
#include <QMessageBox>
class UserGUI : public QMainWindow, public Observer
{
	Q_OBJECT
private:
	Controller* control;
	int id;
	string name;
	int lastSelectedAnswer = 0;
	int lasSelectedQuestion = 0;
public:
	UserGUI(string& name, Controller* c, QWidget *parent = Q_NULLPTR);

private:
	void update() override { populate(); }
	void populate();
	Ui::UserGUIClass ui;
	void changeAllLikes();
private slots:
	void askQuestion();
	void answerQuestion();
	void displayAnswers();
	void displayLikes();
	void changeLikes(int value);
};
