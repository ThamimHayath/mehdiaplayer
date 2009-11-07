#include <iostream>
#include <QtGui>

#include "MehdiaPlayer.h"

UISettings::UISettings(MehdiaPlayer* parent, QString& musicPath)
{
	this->parent = parent;
	
	directory = new QLineEdit(musicPath);
	buttonSave = new QPushButton("Save");
	buttonDir = new QPushButton("Browse");
	labelDirectory = new QLabel("Music directory :");
	saveOnQuit = new QCheckBox("Save playlist on quit");
	buttonSave->setFixedHeight(30);

	layout = new QVBoxLayout;
	layout->addWidget(labelDirectory);
	Hlayout = new QHBoxLayout;
	Hlayout->addWidget(directory);
	Hlayout->addWidget(buttonDir);
	layout->addLayout(Hlayout);
	layout->addWidget(saveOnQuit);
	layout->addWidget(buttonSave);
	layout->setAlignment(Qt::AlignCenter);

	connect(buttonSave, SIGNAL(clicked()), SLOT(saveConf()));
	connect(buttonDir, SIGNAL(clicked()), SLOT(selectDir()));

	setLayout(layout);
}

UISettings::~UISettings()
{

}

void
UISettings::saveConf()
{
	parent->saveConf();
}

void
UISettings::selectDir()
{
	QString res = QFileDialog::getExistingDirectory ( this, "Select your music directory", directory->text(), QFileDialog::ShowDirsOnly );
	if (!res.isNull())
	{
		parent->ui->refreshFolderWith(res);
		directory->setText(res);
	}
}
