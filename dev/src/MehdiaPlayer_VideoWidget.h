#ifndef MEHDIAPLAYER_VIDEOWIDGET
#define MEHDIAPLAYER_VIDEOWIDGET

#include <QtGui>

#include <phonon/videowidget.h>

class MehdiaPlayer;

class MehdiaPlayer_VideoWidget : public Phonon::VideoWidget
{
	Q_OBJECT
	public:
		MehdiaPlayer_VideoWidget(MehdiaPlayer* p) : parent(p) { };

		void mouseDoubleClickEvent(QMouseEvent* event);	

	private:
		MehdiaPlayer* parent;
};

#endif // MEHDIAPLAYER_VIDEOWIDGET
