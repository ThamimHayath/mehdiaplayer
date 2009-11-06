#include <iostream>
#include <QtGui>

#include "UPlay.h"

Engine::Engine(UPlay* parent)
{
	this->parent = parent;
	
	// Phonon init
	audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory);
	mediaObject = new Phonon::MediaObject();	
	videoWidget = new UPlay_VideoWidget(parent);
	seekSlider = new Phonon::SeekSlider();
	Phonon::createPath(mediaObject,audioOutput);
	Phonon::createPath(mediaObject,videoWidget);

	videoWidget->setScaleMode(Phonon::VideoWidget::FitInView);
	videoWidget->setMinimumWidth(320);
	videoWidget->setMinimumHeight(240);
	seekSlider->setEnabled(true);

        
	seekSlider->setIconVisible(false);
	seekSlider->setEnabled(true);
	seekLayout = new QHBoxLayout;
	currentTime = new QLabel("0:00");
	totalTime = new QLabel(" / 0:00");
	seekLayout->addWidget(seekSlider);
	seekLayout->addWidget(currentTime);
	seekLayout->addWidget(totalTime);
	
	seekLayout->setEnabled(true);

	// meta tag resolver
	mediaObjectForMetaInfos = new Phonon::MediaObject();
	connect(mediaObjectForMetaInfos, SIGNAL(metaDataChanged()),
				this, SLOT(metaInfosUpdated()));

	// media
	connect(mediaObject,SIGNAL(hasVideoChanged(bool)),SLOT(hasVideoChanged(bool)));
	connect(mediaObject,SIGNAL(finished()),SLOT(playEnded()));
	connect(mediaObject,SIGNAL(tick(qint64)),SLOT(refreshPlayedTime()));

	mediaObject->setTickInterval(1000);

	listMedias.clear();
	
	// default value
	currentPlayedMedia = -1;
}

Engine::~Engine()
{
	if (audioOutput)
		delete audioOutput; audioOutput = NULL;
	if (mediaObject)
		delete mediaObject; mediaObject = NULL;
	if (videoWidget)
		delete videoWidget; videoWidget = NULL;
	if (seekSlider)
		delete seekSlider; seekSlider = NULL;
	if (seekLayout)
		delete seekLayout; seekLayout = NULL;
	if (currentTime)
		delete currentTime; currentTime = NULL;
	if (totalTime)
		delete totalTime; totalTime = NULL;
	if (mediaObjectForMetaInfos)
		delete mediaObjectForMetaInfos; mediaObjectForMetaInfos = NULL;
}

void
Engine::stop()
{
	// stop playing
	if (mediaObject)
	{
		mediaObject->stop();

		parent->ui->getPlaylist().setBold(currentPlayedMedia,false);
		currentPlayedMedia = -1;
		parent->ui->getControls().setPlayIcon(Phonon::PlayingState);
		seekSlider->setEnabled(false);
	}
}

/**
 * Return the row played, or -1 if an error occured
 */
int
Engine::play(int row)
{
	if (currentPlayedMedia != -1 && row == -1)
	{
		switch (mediaObject->state())
		{	
			case Phonon::PausedState:
				row = currentPlayedMedia;
				if (mediaObject)
				{
					mediaObject->play();
					parent->ui->getControls().setPlayIcon(Phonon::PausedState);
				}
				break;
			case Phonon::PlayingState:
				mediaObject->pause();
				parent->ui->getControls().setPlayIcon(Phonon::PlayingState);
				break;
			default:
				break;
		}
	}
	else
	{
		if (row == -1)
		{
			// TODO
			row = 0;
		}
		if (row <= listMedias.count())
		{
			// Get infos
			Media media = getInfos(row);

			QString s;
			QFileInfo fi(listUris[row]);
			// If the file doesn't have infos, use filename instead
			if (media.title.isEmpty() || media.artist.isEmpty())
			{
				s = fi.fileName() + "\n";
			}
			else
			{
				s = media.artist + "\n" + media.title;	
			}

			// Set the label, display a tray message
			parent->ui->setInfos(s,media.totalTime);

			// preparing reading
			mediaObject->setCurrentSource(listSources[row]);
			mediaObject->setTickInterval(1000);
			mediaObject->setTransitionTime(1000);
			currentTime->setText("0:00");
			seekSlider->setMediaObject(mediaObject);
			totalTime->setText(" / " + media.totalTime);

			if (currentPlayedMedia > -1)
			{
				parent->ui->getPlaylist().setBold(currentPlayedMedia,false);
			}
			currentPlayedMedia = row;
			parent->ui->getPlaylist().setBold(row,true);

			// go
			mediaObject->play();
			seekSlider->setEnabled(true);
			parent->ui->getControls().setPlayIcon(Phonon::PausedState);
		}
		else
		{
			row = -1;
		}

	}

	return row;
}

void
Engine::addMedia(QString uri)
{
	Phonon::MediaSource source(uri);
	listUris.append(uri);
	listSources.append(source);
	listToAdd.append(uri);
	// meta data resolver GO!
	if (listToAdd.size() == 1)
	{
		mediaObjectForMetaInfos->setCurrentSource(source);
	}
}

void
Engine::refreshPlayedTime()
{
	currentTime->setText(Engine::msToString(mediaObject->currentTime()));
}

Media
Engine::getInfos(unsigned int row)
{
	Media media;
	if (row < (unsigned int)listMedias.count())
	{
		media = listMedias.at(row);
	}
	return media;
}

QString
Engine::getUri(unsigned int row)
{
	QString ret = "";
	if (row < (unsigned int)listUris.count())
	{
		ret = listUris.at(row);
	}
	return ret;
}

void
Engine::metaInfosUpdated()
{
	// When a file was added, and when
	// his metadata were resolved, we can add it to the displayed playlist
	Media media;
	// get infos
	QStringList tmpSL = mediaObjectForMetaInfos->metaData("TITLE");
	media.title = "Unknown title";
	if (tmpSL.size() > 0)
	{
		media.title = tmpSL[0];
	}

	media.artist = "Unknown artist";
	tmpSL = mediaObjectForMetaInfos->metaData("ARTIST");
	if (tmpSL.size() > 0)
	{
		media.artist = tmpSL[0];
	}
	
	media.album = "Unknown album";
	tmpSL = mediaObjectForMetaInfos->metaData("ALBUM");
	if (tmpSL.size() > 0)
	{
		media.album = tmpSL[0];
	}
	media.totalTime = Engine::msToString(mediaObjectForMetaInfos->totalTime());

	// Add to the playlist and in the media list
	QString result;
	int tmp = listMedias.count();
	QFileInfo fi(listUris[tmp]);
	if (media.title == "Unknown title" || media.artist == "Unknown artist")
	{
		/* Not enough tag */
		result = fi.fileName();
		media.artist = fi.fileName();
		media.title = "";
	}
	else
	{
		result = media.artist + " - " + media.title;
	}
	listMedias.append(media);
	parent->ui->addItem(result);
	listToAdd.erase(listToAdd.begin());
	if (listToAdd.size() > 0)
	{
		QString* tmp = listToAdd.begin();
		if (tmp)
		{
			Phonon::MediaSource source(*tmp);
			mediaObjectForMetaInfos->setCurrentSource(source);
		}
	}

}

void
Engine::hasVideoChanged(bool newValue)
{
	// Show/Hide the video
	videoWidget->setVisible(newValue);
}

void
Engine::playEnded()
{
	parent->next();
}

int
Engine::delMedia(int row)
{
	int ret = 0;
	if (row < listMedias.count())
	{
		listMedias.remove(row);
		listSources.remove(row);
		listUris.remove(row);
		ret = 1;
	}
	return ret;
}

void
Engine::clearPlayList()
{
	if (parent && parent->ui)
		parent->ui->clearPlaylist();
	listMedias.clear();
	listSources.clear();
	listUris.clear();
}

QString
Engine::msToString(qint64 ms)
{
	QString ret = "";
	qint64 tmp = ms / 1000;
	int seconds = 0;
	int minutes = 0;
	int hours = 0;
	int tmpMins = tmp/60;
	if (tmpMins > 59)
	{
		hours = tmpMins/60;
		minutes = tmpMins%60;		
	}
	else
	{
		minutes = tmpMins;
	}
	seconds = tmp%60;

	if (hours > 0)
	{ // with hours
		/**
		 * We test if minutes/10 == 0 
		 * to not have a display like this -> 1:5:12
		 * but a display like this -> 1:05:12
		 */
		ret += QString::number(hours) + ":";
		if (minutes/10 == 0)
		{
			ret += "0";
		}
		ret += QString::number(minutes) + ":";
		if (seconds/10 == 0)
		{
			ret += "0";
		}
		ret += QString::number(seconds);
	}
	else
	{ // without hours
		ret += QString::number(minutes) + ":";
		if (seconds/10 == 0)
		{
			ret += "0";
		}
		ret += QString::number(seconds);
	}
	return ret;
}

void
Engine::toggleVideo()
{
	if (videoWidget->isFullScreen())
	{
		videoWidget->setFullScreen(false);
	}
	else
	{
		videoWidget->setFullScreen(true);
	}
}
