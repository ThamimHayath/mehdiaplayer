#include <QtGui>
#include <iostream>

#include "UPlay.h"
#include "UPlay_VideoWidget.h"

void
UPlay_VideoWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
	if (event) // get rid of the warning (event var unused)
		parent->engine->toggleVideo();
}
