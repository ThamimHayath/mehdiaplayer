#ifndef UI_H
#define UI_H

#include <QtGui>

#include "UIFolder.h"
#include "UIPlaylist.h"
#include "UISettings.h"
#include "UIControl.h"

class MehdiaPlayer;

class UI : public QWidget
{
		Q_OBJECT
	public:
		UI(MehdiaPlayer* parent,QString& musicPath);
		~UI();

		/*
		 * Add a file in the playlist
		 */
		void playlistAdd(QString uri);
		/*
		 * Clear the playlist
		 */
		void clearPlaylist();

		bool random;
		
		void addItem(QString s);

		void setInfos(QString s, QString totalTime);

		/*
		 * Return the current selected row in the playlist
		 */
		int playlistCurrentRow()
		{
			return playlist->currentRow();
		}
		/*
		 * Return how many files in the playlist
		 */
		int playlistCount()
		{
			return playlist->getWidget()->count();
		}
		/*
		 * Change the selected row in the playlist
		 */
		void setSelectedRow(unsigned int row)
		{
			playlist->getWidget()->setCurrentRow(row);
		}

		/*
		 * Refresh the content of the folder list with a new folder string
		 */
		void refreshFolderWith(QString s)
		{
			if (settings)
				settings->setDirectory(s);
			if (folder)
				folder->refreshWithNewMusicPath(s);
		}

		bool
		isHidden()
		{
			return hidden;
		}

		void
		switchHide();

		UIControl& getControls()
		{
			return *controls;
		}

		UISettings& getSettings()
		{
			return *settings;
		}

		UIPlaylist& getPlaylist()
		{
			return *playlist;
		}
	

	public slots:
		/*
		 * Switch between big/small interface
		 */	
		void toggleInterface();
		/*
		 * Controls
		 */
		void play();
		void next();
		void prev();
		void stop();

		// Tray quit
		void tQuit();

		// Tray clicked
		void tClicked(QSystemTrayIcon::ActivationReason reason);

	private:
		QTabWidget* tab;
		UIPlaylist* playlist;
		UIFolder* folder;
		UIControl* controls;
		UISettings* settings;
		
		QVBoxLayout* mainLayout;

		QLabel* infosSong;

		QSystemTrayIcon* trayIcon;
		QMenu* trayMenu;
		QAction* trayPrev;
		QAction* trayNext;
		QAction* trayStop;
		QAction* trayPlay;
		QAction* trayQuit;

		bool hidden;
		
		void dragEnterEvent(QDragEnterEvent* event);
		void dropEvent(QDropEvent* event);

		MehdiaPlayer* parent;
};

#endif // UI_H
