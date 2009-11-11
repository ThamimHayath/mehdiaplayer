#ifndef MEHDIAPLAYER_H
#define MEHDIAPLAYER_H

#include <QtCore>
#include <QtGui>

#include "Engine.h"
#include "UI.h"

class MehdiaPlayer : public QApplication
{
		Q_OBJECT
	public:
		MehdiaPlayer(int& argc, char** argv);
		/*
		 * Destructor
		 */
		~MehdiaPlayer();

		/*
		 * The media engine
		 */
		Engine* engine;
		/*
		 * The ui
		 */
		UI* ui;

		/*
		 * To restore from a file the content of the playlist
		 */
		void restorePlaylist();

		/*
		 * Read the conf (~/.uplayrc)
		 */
		void restoreConf();

		/*
		 * Add a media in the playlist
		 */
		void addMedia(QString uri);

		/*
		 * Save settings
		 */
		void saveConf();

		
	public slots:
		void onQuit();
		void play(int row);
		void stop();
		void next();
		void prev();

	private:
		QString musicPath;
};

#endif // MEHDIAPLAYER
