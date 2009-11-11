#include <iostream>
#include <QtGui>

#include "MehdiaPlayer.h"
#include "UI.h"

UI::UI(MehdiaPlayer* parent, QString& musicPath)
{
	this->parent = parent;

	QStyle* style = this->style();

	// Initialize the random
	qsrand(time(NULL));
	random = false;

	infosSong = new QLabel("Stopped\n");
	infosSong->setAlignment(Qt::AlignCenter);
	infosSong->setFrameStyle(QFrame::StyledPanel);
	
	// Controls
	controls = new UIControl(parent);
	// Playlist
	playlist = new UIPlaylist(parent);
	// Folder
	folder = new UIFolder(parent,musicPath);
	// Settings
	settings = new UISettings(parent, musicPath);

	// Tab
	tab = new QTabWidget;
	tab->addTab(playlist, "Playlist");
	tab->addTab(folder, "Folder");
	tab->addTab(settings,"Settings");

	// Layouts
	mainLayout = new QVBoxLayout;

	mainLayout->addWidget(infosSong);
	mainLayout->addLayout(parent->engine->getSeekLayout());
	mainLayout->addWidget(controls);
	mainLayout->addWidget(tab);

	mainLayout->setSpacing(2);


	// Tray icon
	trayIcon = new QSystemTrayIcon(style->standardIcon(QStyle::SP_MediaPlay));
	trayIcon->show();
	trayMenu = new QMenu;
	trayNext = new QAction(style->standardIcon(QStyle::SP_MediaSkipForward),"Next", this);
	connect(trayNext, SIGNAL(triggered()), this, SLOT(next()));
	trayPrev = new QAction(style->standardIcon(QStyle::SP_MediaSkipBackward),"Previous", this);
	connect(trayPrev, SIGNAL(triggered()), this, SLOT(prev()));
	trayStop = new QAction(style->standardIcon(QStyle::SP_MediaStop),"Stop", this);
	connect(trayStop, SIGNAL(triggered()), this, SLOT(stop()));
	trayPlay = new QAction(style->standardIcon(QStyle::SP_MediaPlay),"Play", this);
	connect(trayPlay, SIGNAL(triggered()), this, SLOT(play()));
	trayQuit = new QAction(style->standardIcon(QStyle::SP_DialogCloseButton),"Quit", this);
	connect(trayQuit,SIGNAL(triggered()),this,SLOT(tQuit()));
	trayMenu->addAction(trayPlay);
	trayMenu->addAction(trayStop);
	trayMenu->addAction(trayNext);
	trayMenu->addAction(trayPrev);
	trayMenu->addAction(trayQuit);
	trayIcon->setContextMenu(trayMenu);

	connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), SLOT(tClicked(QSystemTrayIcon::ActivationReason)));

	// Accept drag'n'drop
	setAcceptDrops(true);

	// UI
	setLayout(mainLayout);
	show();
}
UI::~UI()
{
	if (controls)
		delete controls; controls = NULL;
	if (folder)
		delete folder; folder = NULL;
	if (settings)
		delete settings; settings = NULL;
}

void
UI::toggleInterface()
{
	tab->setVisible(!tab->isVisible());
	adjustSize(); // TODO find a better solution than call 2 times the func...
	adjustSize();
}
	
void
UI::dragEnterEvent(QDragEnterEvent *event)
{
	event->acceptProposedAction();
}

void
UI::clearPlaylist()
{
	playlist->clearPlaylist(); 
}

void
UI::dropEvent(QDropEvent* event)
{
	QList<QUrl> urlList;

	// if dropped data = url
	if (event->mimeData()->hasUrls())
	{
		event->acceptProposedAction();
		// we retrieve data
		urlList = event->mimeData()->urls();

		for (int i = 0; i < urlList.size(); i++)
		{
			playlistAdd(urlList[i].toString());
		}

	}	
}

void
UI::playlistAdd(QString s)
{
	parent->engine->addMedia(s);
}

void
UI::addItem(QString s)
{
	playlist->addItem(s);
}

void
UI::play()
{
	parent->play(-1);
}

void
UI::stop()
{
	parent->stop();
}

void
UI::next()
{
	parent->next();
}

void
UI::prev()
{
	parent->prev();
}

void
UI::tQuit()
{
	parent->exit();
}

void
UI::setInfos(QString s,QString totalTime)
{
	infosSong->setText(s);
	trayIcon->setToolTip(s + " (" + totalTime + ")");
	trayIcon->showMessage("Playing",s + " (" + totalTime + ")\n",QSystemTrayIcon::NoIcon, 5000);
}

void
UI::tClicked(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
		case QSystemTrayIcon::Trigger:
			switchHide();	
			break;
		default:
			break;
	}
}

void
UI::switchHide()
{
	if (hidden == true) { hidden = false; }
	else { hidden = true;  }
	if (hidden)
	{
		hide();
	}
	else
	{
		show();
	}
}
