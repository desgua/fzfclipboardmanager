#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xfixes.h>

int main(int argc, char *argv[]) {
	
    Display *display = XOpenDisplay(NULL);

    if (!display) {
        fprintf(stderr, "Can't open X display\n");
        return EXIT_FAILURE;
    }

    XEvent event;
    Window root         = DefaultRootWindow(display);
    Atom   xa_clipboard = XInternAtom(display, "CLIPBOARD", False);

	if (argc == 1) {
			printf("Usage: %s [change/empty]\n", argv[0]);
        	return EXIT_SUCCESS;
		} else if (strcmp(argv[1], "change") == 0) { 
        	XFixesSelectSelectionInput(display, root, xa_clipboard, XFixesSetSelectionOwnerNotifyMask);
		} else if (strcmp(argv[1], "empty") == 0) { 
    		XFixesSelectSelectionInput(display, root, xa_clipboard, XFixesSelectionClientCloseNotifyMask);
		} else {	
			printf("Usage: %s [change/empty]\n", argv[0]);
        	return EXIT_SUCCESS;
		}

    XNextEvent(display, &event);
    XCloseDisplay(display);

    return EXIT_SUCCESS;
}
