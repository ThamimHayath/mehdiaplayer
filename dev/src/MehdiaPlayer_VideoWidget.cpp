#include <QtGui>
#include <iostream>

#include "MehdiaPlayer.h"
#include "MehdiaPlayer_VideoWidget.h"

void
MehdiaPlayer_VideoWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
	if (event) // get rid of the warning (event var unused)
		parent->engine->toggleVideo();
}
