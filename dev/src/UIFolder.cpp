#include <iostream>
#include <QtGui>

#include "MehdiaPlayer.h"

UIFolder::UIFolder(MehdiaPlayer* parent, QString musicPath)
{
	this->parent = parent;

	listWidget = new QListWidget;

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(listWidget);

	this->musicPath = musicPath;

	connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), SLOT(folderListDoubleClicked(QListWidgetItem*)));

	// Menus
		// Folder menu
	folderMenu = new QMenu;
	actAddFolder = new QAction("Add to playlist", this);
	connect(actAddFolder, SIGNAL(triggered()), this, SLOT(slotAddFolder()));
	actReplFolder = new QAction("Replace in playlist", this);
	connect(actReplFolder, SIGNAL(triggered()), this, SLOT(slotReplFolder()));
	folderMenu->addAction(actAddFolder);
	folderMenu->addAction(actReplFolder);
	

	// Filters
		// Audios
	filters << "*.mp3" << "*.wav" << "*.wma" << "*.mpc" << "*.m4a" << "*.ogg";
		// Videos
	filters << "*.avi" << "*.mpg";
		// System
	filters << "..";

	refreshDirContent();
	setLayout(layout);
}

UIFolder::~UIFolder()
{
	if (folderMenu)
		delete folderMenu; folderMenu = NULL;
}

void
UIFolder::refreshDirContent()
{
	int i;
	QDir tmp(musicPath);
	QListWidgetItem* item = NULL;
	QStyle * style = parent->style();
	QStyle::StandardPixmap icon;
	QFileInfo fi;

	tmp.setSorting(QDir::DirsFirst | QDir::IgnoreCase);
	tmp.setFilter(QDir::AllDirs | QDir::Files);
	tmp.setNameFilters(filters);

	listWidget->clear();
	dirContent = tmp.entryList();

	for (i=1; i < dirContent.count(); i++) // start to 1 cause the first one is .
	{
		fi.setFile(musicPath+"/"+dirContent[i]);
		if (fi.isDir())
		{
			icon = QStyle::SP_DirIcon;
		}
		else
		{
			icon = QStyle::SP_FileIcon;
		}
				
		item = new QListWidgetItem(style->standardIcon(icon),dirContent[i]);
		if (item)
		{
			listWidget->addItem(item);
		}
	}
}

void
UIFolder::folderListDoubleClicked(QListWidgetItem* item)
{
	QString s = musicPath + "/" + item->text();
	QFileInfo fi;

	fi.setFile(s);

	if (fi.isDir())
	{ // directory
		musicPath += "/" + item->text();
		musicPath = QDir::cleanPath(musicPath);
		refreshDirContent();
	}
	else
	{
		addFile(s);
	}
}

void
UIFolder::addFile(QString uri)
{
	int i; int nbFilters = filters.count();
	QString ext;
	int c = uri.count();
	bool readable = false;

	ext.reserve(4);

	ext[0] = uri[c-4];
	ext[1] = uri[c-3];
	ext[2] = uri[c-2];
	ext[3] = uri[c-1];

	for (i = 0; i < nbFilters;i++)
	{
		if (filters[i].contains(ext) && filters[i] != "..")
		{
			readable = true;
			break;
		}

	}
	if (readable)
	{
		parent->ui->playlistAdd(uri);
	}
}

void
UIFolder::contextMenuEvent(QContextMenuEvent * event)
{
	QFileInfo fi;
	QString fname;

	QListWidgetItem* item = listWidget->currentItem();
	if (item)
	{
		fname = listWidget->currentItem()->text();
		fi.setFile(musicPath + "/" + fname);
		
		folderMenu->exec(event->globalPos());
	}
}

void
UIFolder::slotAddFolder()
{
	// add the content of the dir
	if (listWidget->currentItem()->text() != "..")
	{
		QString uri = musicPath + "/" + listWidget->currentItem()->text();
		QFileInfo fi;
		fi.setFile(uri);
		if (fi.isDir())
		{
			addFolder(uri);
		}
		else
		{	
			addFile(uri);
		}
	}
}

void
UIFolder::slotReplFolder()
{
	// add the content of the dir
	if (listWidget->currentItem()->text() != "..")
	{
		// clear the current playlist
		parent->engine->clearPlayList();
		QString uri = musicPath + "/" + listWidget->currentItem()->text();
		QFileInfo fi;
		fi.setFile(uri);
		if (fi.isDir())
		{
			addFolder(uri);
		}
		else
		{	
			addFile(uri);
		}
	}
}

void
UIFolder::addFolder(QString uri)
{
	int i;
	QDir tmp(uri);
	QString s;
	QFileInfo fi;

	QStringList tmpDirContent = tmp.entryList();
	int count = tmpDirContent.count();

	for (i=2; i < count; i++) // start to 2 cause the first one is . and the second == ..
	{
		s = uri + "/" + tmpDirContent[i];
		fi.setFile(s);
		if (fi.isDir())
		{
			addFolder(s);
		}
		else
		{
			addFile(s);
		}
	}
}

void
UIFolder::refreshWithNewMusicPath(QString& s)
{
	musicPath = s;
	refreshDirContent();
}

