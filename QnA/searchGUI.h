#pragma once

#include <QWidget>
#include "ui_searchGUI.h"
#include "Repository.h"
#include "Observer.h"
class searchGUI : public QWidget, public Observer
{
	Q_OBJECT

public:
	searchGUI(Repository* r, QWidget *parent = Q_NULLPTR);
	~searchGUI();

private:
	Repository* repo;
	Ui::searchGUI ui;
	void update() override;
private slots:
	void searchSlot(const QString &);
};
