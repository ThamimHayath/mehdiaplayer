#include <iostream>
#include <QtCore>
#include <QtGui>

#include "UPlay.h"
#include "UI.h"
#include "Engine.h"

int main(int argc, char  * argv[])
{
	UPlay app(argc, argv);
	app.setApplicationName("uplay");
	app.setQuitOnLastWindowClosed(true);


	// param	
	if (argc > 0)
	{
		int i;
		/*
		 * Add every arguments
		 */
		for (i = 1; i < argc; i++)
		{
			app.addMedia(argv[i]);
		}
		/*
		 * If there was a media added, play it
		 */
		if (i > 1)
		{
			app.next();
		}
	}

	// Restoring the playlist
	app.restorePlaylist();


	return app.exec();
}
