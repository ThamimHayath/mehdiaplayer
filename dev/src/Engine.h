#ifndef ENGINE_H
#define ENGINE_H

#include <QtGui>

#include <phonon/seekslider.h>
#include <phonon/audiooutput.h>
#include <phonon/videowidget.h>
#include <phonon/mediaobject.h>
#include <phonon/mediasource.h>

#include "MehdiaPlayer_VideoWidget.h"

typedef struct Media
{
	QString artist;
	QString title;
	QString album;
	QString totalTime;
} Media;

class MehdiaPlayer;

class Engine : public QObject
{
	Q_OBJECT
	public:
		Engine(MehdiaPlayer *parent);

		~Engine();

		/**
		 * Return the row played, or -1 if an error occured
		 */
		int play(int row);

		/*
		 * Stop playing
		 */
		void stop();


		/*
		 * The content of the seekbar (in a layout)
		 */
		QHBoxLayout* getSeekLayout()
		{
			return seekLayout;
		}

		/*
		 * Return the instance of the video widget
		 */
		Phonon::VideoWidget* getVideoWidget()
		{
			return videoWidget;
		}

		/*
		 * Add a media
		 */
		void addMedia(QString uri);

		/*
		 * Delete a media
		 */
		int delMedia(int row);

		/*
		 * Return info on a file
		 */
		Media getInfos(unsigned int row);

		/*
		 * Return the index of the currently played media
		 */
		int getCurrentPlayedMedia()
		{
			return currentPlayedMedia;
		}

		/*
		 * When an item song is removed from playlist, the id of the
		 * currently played media sometimes change
		 */
		void decCurrentPlayedMedia()
		{
			currentPlayedMedia--;
		}

		/*
		 * Return the uri index 'row'
		 */
		QString getUri(unsigned int row);
		
		/*
		 * Clear every list : playlist, media list, uris list sources list
		 */
		void clearPlayList();

		/*
		 * Convert a time in milliseconds to a human readable string (3:40)
		 */
		static QString msToString(qint64 ms);

		/*
		 * Return the state of the player (is it playing ? paused ?)
		 */
		Phonon::State getReadingState()
		{
			Phonon::State ret = Phonon::ErrorState;
			if (mediaObject)
			{
				ret = mediaObject->state();
			}
			return ret;
		}

		/*
		 * Show if hidden, hide if shown
		 */
		void
		toggleVideo();
		

	public slots:
		void metaInfosUpdated();//Phonon::State state, Phonon::State oldState);
		void hasVideoChanged(bool newValue);
		void refreshPlayedTime();
		void playEnded();

	private:		
		int currentPlayedMedia;

		Phonon::SeekSlider* seekSlider;
		Phonon::AudioOutput* audioOutput;
		Phonon::MediaObject* mediaObject;	
		Phonon::VideoWidget* videoWidget;
		Phonon::MediaObject* mediaObjectForMetaInfos;

		QHBoxLayout* seekLayout;
		QLabel *currentTime, *totalTime;

		QVector<Media> listMedias;
		QVector<Phonon::MediaSource> listSources;
		QVector<QString> listUris;
		QVector<QString> listToAdd;
		//Media tmpMedia;
		
		MehdiaPlayer* parent;
};

#endif
