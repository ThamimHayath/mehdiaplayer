#include "UIControl.h"
#include "UPlay.h"

UIControl::UIControl(UPlay* parent)
{
	this->parent = parent;

	// Control buttons
	QStyle * s = parent->style();
	buttonPrev = new QPushButton(s->standardIcon(QStyle::SP_MediaSkipBackward),"");
	buttonStop = new QPushButton(s->standardIcon(QStyle::SP_MediaStop),"");
	buttonPlay = new QPushButton(s->standardIcon(QStyle::SP_MediaPlay),"");
	buttonNext = new QPushButton(s->standardIcon(QStyle::SP_MediaSkipForward),"");
	buttonToggle = new QPushButton(s->standardIcon(QStyle::SP_FileIcon),"");
	random = new QCheckBox("Random");

	buttonNext->setFixedSize(30,30);	
	buttonStop->setFixedSize(30,30);
	buttonPrev->setFixedSize(30,30);
	buttonStop->setFixedSize(30,30);
	buttonPlay->setFixedSize(30,30);
	buttonToggle->setFixedSize(30,30);
	
	// Insert control in their layout
	layoutControl = new QHBoxLayout;
	layoutControl->addWidget(buttonPrev);
	layoutControl->addWidget(buttonStop);
	layoutControl->addWidget(buttonPlay);
	layoutControl->addWidget(buttonNext);
	layoutControl->addWidget(buttonToggle);
	layoutControl->addWidget(random);
	layoutControl->setSpacing(0);
	layoutControl->setAlignment(Qt::AlignCenter);
	
	// Signals
	connect(buttonPlay, SIGNAL(clicked()), SLOT(play()));
	connect(buttonStop, SIGNAL(clicked()), SLOT(stop()));
	connect(buttonPrev, SIGNAL(clicked()), SLOT(prev()));
	connect(buttonNext, SIGNAL(clicked()), SLOT(next()));
	connect(buttonToggle, SIGNAL(clicked()), SLOT(toggleInterface()));
	connect(random, SIGNAL(stateChanged(int)), SLOT(randomChanged(int)));
	
	this->setLayout(layoutControl);
}

UIControl::~UIControl()
{

}

void
UIControl::randomChanged(int state)
{
	parent->ui->random = state ? true : false;
}

void
UIControl::play()
{
	parent->play(-1);
}

void
UIControl::stop()
{
	parent->stop();
}

void
UIControl::next()
{
	parent->next();
}

void
UIControl::prev()
{
	parent->prev();
}

void
UIControl::setPlayIcon(Phonon::State state)
{
	QStyle* s= parent->style();
	switch (state)
	{
		case Phonon::PlayingState:
			buttonPlay->setIcon(s->standardIcon(QStyle::SP_MediaPlay));
			break;
		case Phonon::PausedState:
			buttonPlay->setIcon(s->standardIcon(QStyle::SP_MediaPause));
			break;
		default:
			break;
	}
}

void
UIControl::toggleInterface()
{
	parent->ui->toggleInterface();
}

