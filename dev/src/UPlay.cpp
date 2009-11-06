#include <iostream>
#include "UPlay.h"
#include "UI.h"
#include "Engine.h"

UPlay::UPlay(int & argc, char** argv) : QApplication(argc,argv)
{
	setApplicationName("uplay");
	musicPath = "/"; // default path : root
	engine = new Engine(this);
	ui = new UI(this,musicPath);
	restoreConf();
	connect(this, SIGNAL(aboutToQuit()), SLOT(onQuit()));
}

UPlay::~UPlay()
{
	if (engine)
		delete engine;
	if (ui)
		delete ui;
}

void
UPlay::addMedia(QString uri)
{
	engine->addMedia(uri);
}

void
UPlay::onQuit()
{
	saveConf();
	if (ui->getSettings().getSaveOnQuitState())
		ui->getPlaylist().savePlaylist();			
}

void
UPlay::restorePlaylist()
{
	QFile file(QDir::homePath() + "/.uplay_list");
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&file);
		QString line = in.readLine();
		while (!line.isNull())
		{
			ui->playlistAdd(line);	
			line = in.readLine();
		}
	}
}

void
UPlay::restoreConf()
{
	QFile file(QDir::homePath() + "/.uplayrc");
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		int l = 0;
		QTextStream in(&file);
		QString line = in.readLine();
		while (!line.isNull())
		{
			switch (l)
			{
				case 0: // music path
					ui->refreshFolderWith(line);
					break;
				case 1: // random enabled ?
					if (ui)
					{
						bool b = false;
						if (line == "true")
						{
							b = true;
						}
						ui->getControls().setRandom(b);
					}
					break;
				case 2: // save on quit state
					if (ui)
					{
						bool b = false;
						if (line == "true")
						{
							b = true;
						}
						ui->getSettings().setSaveOnQuitState(b);
					}
			}
			// line index
			l++;

			line = in.readLine();
		}
	}
}

void
UPlay::play(int row)
{
	switch (engine->getReadingState())
	{
		case Phonon::PlayingState:
			engine->play(row);
			break;
		case Phonon::PausedState:
			engine->play(row);
			break;
		default:
			int n = row;
			if (n == -1)
			{
				n = ui->playlistCurrentRow();
				if (n == -1) { n = 0; }
			}
			if (n > -1 && n < ui->playlistCount())
			{
				ui->setSelectedRow(n);
				engine->play(n);
			}
			break;
	}
}

void
UPlay::stop()
{
	engine->stop();
}

void
UPlay::next()
{
	int n = engine->getCurrentPlayedMedia();
	if (ui->random)
	{
		if (ui->playlistCount() > 2)
		{
			while (n == engine->getCurrentPlayedMedia())
			{
				n = qrand()%ui->playlistCount();
			}
		}
		else
		{ // only 2 songs in the playlist
			n = !n;
		}
	}
	else
	{
		n++;
		if (n >= ui->playlistCount())
		{
			n = 0;
		}
	}
	engine->play(n);
	ui->setSelectedRow(n);
}

void
UPlay::prev()
{
	int n = engine->getCurrentPlayedMedia();
	n--;
	if (n < 0)
	{
		n = ui->playlistCount()-1;
	}
	engine->play(n);
	ui->setSelectedRow(n);
}

void
UPlay::saveConf()
{
	if (ui)
	{
		QFile file(QDir::homePath() + "/.uplayrc");
		QTextStream out(&file);
		if (file.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			// First, the directory music
			QString dir = ui->getSettings().getDirectory();
			if (dir == "")
			{
				dir = "/";
			}
			out << dir << '\n';
			ui->refreshFolderWith(dir);

			// Then the random state
			bool randomState = ui->getControls().getRandomState();
			if (randomState)
			{
				out << "true" << '\n';
			}
			else
			{
				out << "false" << '\n';
			}

			// Do we have to save the playlist on quit ?
			bool saveOnQuitState = ui->getSettings().getSaveOnQuitState();
			if (saveOnQuitState)
			{
				out << "true" << '\n';
			}
			else
			{
				out << "false" << '\n';
			}

			file.close();
		}
	}
}
