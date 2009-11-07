#ifndef UIPLAYLIST_H
#define UIPLAYLIST_H

#include <QtCore>
#include <QtGui>

class MehdiaPlayer;

class UIPlaylist : public QWidget
{
		Q_OBJECT
	public:
		/*
		 * Constructor
		 */
		UIPlaylist(MehdiaPlayer* parent);
		
		~UIPlaylist();

		/*
		 * Return the playlist widget
		 */
		QListWidget* getWidget()
		{
			return widgetPlaylist;
		}

		/*
		 * Return the current selected row
		 */
		int currentRow()
		{
			return widgetPlaylist->currentRow();
		}

		/*
		 * Add a media in the playlist
		 */
		void addItem(QString s);

		/*
		 * Set bold/Unbold a row of the playlist
		 */
		void setBold(unsigned int row, bool b);

	public slots:
		void clearPlaylist(); // clear the widget
		void buttonClearPlaylist(); // clear the content & the widget
		void playlistDoubleClicked();
		void savePlaylist();
		void delItem();

	private:
		QListWidget* widgetPlaylist;
		QPushButton* buttonDel, *buttonSave, *buttonClear;
		QHBoxLayout* layoutControlPL;
		QVBoxLayout* layout;

		MehdiaPlayer* parent;
};

#endif // UIPLAYLIST_H
