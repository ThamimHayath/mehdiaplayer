#ifndef UISETTINGS_H
#define UISETTINGS_H

#include <QtCore>
#include <QtGui>

class UPlay;

class UISettings : public QWidget
{
		Q_OBJECT
	public:
		/*
		 * Constructor
		 */
		UISettings(UPlay* parent, QString& musicPath);
		~UISettings();

		/**
		 * Return the dir music
		 */
		QString
		getDirectory()
		{
			return directory->text();
		}

		/*
		 * Set the label for the music directory editbox
		 */
		void
		setDirectory(QString s)
		{
			directory->setText(s);
		}

		bool
		getSaveOnQuitState()
		{
			bool b = false;
			if (saveOnQuit)
			{
				b = saveOnQuit->isChecked();
			}
			return b;
		}

		void
		setSaveOnQuitState(bool b)
		{
			if (saveOnQuit)
			{
				saveOnQuit->setCheckState(b ? Qt::Checked : Qt::Unchecked);	
			}
		}
		
	public slots:
		void saveConf();
		void selectDir();
	
	private:
		QLineEdit* directory;
		QPushButton* buttonSave;
		QPushButton* buttonDir;
		QHBoxLayout* Hlayout;
		QVBoxLayout* layout;
		QLabel* labelDirectory;
		QCheckBox* saveOnQuit;

		UPlay* parent;
};

#endif // UIPLAYLIST_H
