#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xfixes.h>

static enum selections {
    NONE                = 0,
    SELECTION_CHANGE = (1 << 0),
    SELECTION_EMPTY   = (1 << 1),
} selections = NONE;

int main(int argc, char *argv[]) {
    static const char USAGE[] = "Usage: %s -s [change/empty]\n";

    static const char SEL_OPT_CHANGE[] = "change";
    static const char SEL_OPT_EMPTY[]   = "empty";
    static const char SEL_OPT_SEPARATOR[] = ",";

    int optchar;
    while ((optchar = getopt(argc, argv, "hs:")) != -1) {
        switch (optchar)
        {
        case 'h':
            printf(USAGE, argv[0]);
            return EXIT_SUCCESS;
        /* We need the pair of braces because C does not allow a declaration after a labeled statement. */
        case 's': {
            char *token = strtok(optarg, SEL_OPT_SEPARATOR);
            while(token != NULL) {
                if (strcmp(token, SEL_OPT_CHANGE) == 0) {
                    selections |= SELECTION_CHANGE;
                } else if (strcmp(token, SEL_OPT_EMPTY) == 0) {
                    selections |= SELECTION_EMPTY;
                } else {
                    fprintf(stderr, "Unrecognized option '%s'. Available: change, empty.\n", token);
                    return EXIT_FAILURE;
                }
                token = strtok(NULL, SEL_OPT_SEPARATOR);
            }
            break;
        }
        default: /* '?' */
            fprintf(stderr, USAGE, argv[0]);
            return EXIT_FAILURE;
        }
    }
    Display *display = XOpenDisplay(NULL);

    if (!display) {
        fprintf(stderr, "Can't open X display\n");
        return EXIT_FAILURE;
    }

    XEvent event;
    Window root         = DefaultRootWindow(display);
    Atom   xa_clipboard = XInternAtom(display, "CLIPBOARD", False);

    /* Monitor all selections by default if -s was not specified. */
    if (selections == NONE) { 
            printf(USAGE, argv[0]);
            return EXIT_SUCCESS;
			}

    if (selections & SELECTION_CHANGE)
        XFixesSelectSelectionInput(display, root, xa_clipboard, XFixesSetSelectionOwnerNotifyMask);
    if (selections & SELECTION_EMPTY)
    	XFixesSelectSelectionInput(display, root, xa_clipboard, XFixesSelectionClientCloseNotifyMask);

    XNextEvent(display, &event);
    XCloseDisplay(display);

    return EXIT_SUCCESS;
}
