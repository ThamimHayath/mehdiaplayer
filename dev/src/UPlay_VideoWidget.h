#ifndef UPLAY_VIDEOWIDGET
#define UPLAY_VIDEOWIDGET

#include <QtGui>

#include <phonon/videowidget.h>

class UPlay;

class UPlay_VideoWidget : public Phonon::VideoWidget
{
	Q_OBJECT
	public:
		UPlay_VideoWidget(UPlay* p) : parent(p) { };

		void mouseDoubleClickEvent(QMouseEvent* event);	

	private:
		UPlay* parent;
};

#endif // UPLAY_VIDEOWIDGET
