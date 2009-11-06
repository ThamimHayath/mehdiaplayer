#ifndef UICONTROL_H
#define UICONTROL_H

#include <QtGui>
#include <phonon/mediaobject.h>


class UPlay;

class UIControl : public QWidget
{
	Q_OBJECT
	public:
		/*
		 * Constructor
		 */
		UIControl(UPlay* parent);
		~UIControl();
		
		/*
		 * Return the state of the random checkbox
		 */
		bool
		getRandomState()
		{
			bool b = false;
			if (random)
			{
				b = random->isChecked();
			}
			return b;
		}

		/*
		 * Set the random checkbox state
		 */
		void
		setRandom(bool b)
		{
			if (random)
				random->setCheckState(b ? Qt::Checked : Qt::Unchecked);
		}

		/*
		 * Set the pause icon if s == Phonon::PausedState
		 * set the playing icon if s == Phonon::PlayingState
		 */
		void
		setPlayIcon(Phonon::State s);

	public slots:
		void randomChanged(int state);
		void toggleInterface();
		void play();
		void next();
		void prev();
		void stop();

	private:
		QPushButton *buttonPrev, *buttonStop, *buttonPlay, *buttonNext, *buttonToggle;
		QCheckBox* random;
		QHBoxLayout *layoutControl;

		UPlay* parent;
};

#endif // UICONTROL_H
