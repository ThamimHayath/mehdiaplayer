#include <iostream>
#include <QtGui>

#include "MehdiaPlayer.h"

UIPlaylist::UIPlaylist(MehdiaPlayer* parent)
{
	this->parent = parent;

	widgetPlaylist = new QListWidget;

	buttonDel = new QPushButton("Remove");
	buttonDel->setFixedHeight(30);

	buttonClear = new QPushButton("Clear");
	buttonClear->setFixedHeight(30);

	buttonSave = new QPushButton("Save");
	buttonSave->setFixedHeight(30);


	// Layout
	layout = new QVBoxLayout();

	layoutControlPL = new QHBoxLayout;
	layoutControlPL->addWidget(buttonDel);
	layoutControlPL->addWidget(buttonClear);
	layoutControlPL->addWidget(buttonSave);
	layoutControlPL->setAlignment(Qt::AlignCenter);

	connect(buttonDel, SIGNAL(clicked()), SLOT(delItem()));
	connect(buttonClear, SIGNAL(clicked()), SLOT(buttonClearPlaylist()));
	connect(buttonSave, SIGNAL(clicked()), SLOT(savePlaylist()));
	connect(widgetPlaylist, SIGNAL(itemDoubleClicked(QListWidgetItem*)), SLOT(playlistDoubleClicked()));

	layout->addWidget(widgetPlaylist);
	layout->addLayout(layoutControlPL);
	setLayout(layout);
}

UIPlaylist::~UIPlaylist()
{

}

void
UIPlaylist::playlistDoubleClicked()
{
	parent->play(widgetPlaylist->currentRow());
}

void
UIPlaylist::addItem(QString s)
{
	QListWidgetItem* item = new QListWidgetItem(s);
	widgetPlaylist->addItem(item);
}

void
UIPlaylist::delItem()
{
	int row = widgetPlaylist->currentRow();
	QListWidgetItem* item = widgetPlaylist->takeItem(row);
	if (item)
	{
		delete item;
		parent->engine->delMedia(row);
		if (row < parent->engine->getCurrentPlayedMedia())
		{
			parent->engine->decCurrentPlayedMedia();	
		}
	}
}

void
UIPlaylist::setBold(unsigned int row, bool b)
{
	QListWidgetItem* item = widgetPlaylist->item(row);
	if (item)
	{
		QFont tmp;
		tmp.setBold(b);		
		item->setFont(tmp);
	}
}

void
UIPlaylist::savePlaylist()
{
	int count = parent->ui->playlistCount();
	int i;
	QFile file(QDir::homePath() + "/.uplay_list");
	QTextStream out(&file);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		for (i = 0; i < count; i++)
		{
			out << parent->engine->getUri(i) << '\n';
		}
	}
	file.close();
}

void
UIPlaylist::buttonClearPlaylist()
{
	parent->engine->clearPlayList();
}

void
UIPlaylist::clearPlaylist()
{
	widgetPlaylist->clear();
}

