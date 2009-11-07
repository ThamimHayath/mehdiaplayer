#ifndef UIFOLDER_H
#define UIFOLDER_H

#include <QtGui>

class MehdiaPlayer;

class UIFolder : public QWidget
{
		Q_OBJECT
	public:
		/*
		 * Constructor
		 */
		UIFolder(MehdiaPlayer* parent, QString musicPath);
		~UIFolder();
 
		/*
		 * Refresh the content with a new music path
		 */
		void refreshWithNewMusicPath(QString& s);
		
	public slots:
		/*
		 * When the user double cliked on a file in the playlist
		 */
		void folderListDoubleClicked(QListWidgetItem* item);
		/*
		 * When the user clicks in the menu, on the item Add folder to playlist
		 */
		void slotAddFolder();
		/*
		 * When the user clicks in the menu, on the item Replace in playlist
		 */
		void slotReplFolder();
		
	protected:
		void contextMenuEvent(QContextMenuEvent* event);

	private:
		QListWidget* listWidget;

		QMenu* folderMenu;
		QAction* actAddFolder;
		QAction* actReplFolder;

		QString musicPath;
		QStringList dirContent;

		QStringList filters;

		void refreshDirContent();

		void addFile(QString uri);
		void addFolder(QString uri);

		MehdiaPlayer* parent;
};

#endif // UIFOLDER_H
