#include <X11/X.h>
#include <X11/Xlib.h>
#include <stdbool.h>
#include <X11/keysym.h>

Display *display;
bool running = true;

void key_press(XEvent *event){
	running = false;
}

void run() {
	while(running){
		XEvent event;
		XNextEvent(display, &event);
		switch (event.type) {
			case MapNotify:
				break;
			case UnmapNotify:
				break;
			case MapRequest:
				break;
			case ConfigureRequest:
				break;
			case ConfigureNotify:
				break;
			case CreateNotify:
				break;
			case ReparentNotify:
				break;
			case DestroyNotify:
				break;
			case ButtonPress:
				break;
			case ButtonRelease:
				break;
			case KeyPress:
				key_press(&event);
				break;
			case KeyRelease:
				break;
			case MotionNotify:
				break;
		}
	}
}

void setup_hotkey(){
	XGrabKey(display, XKeysymToKeycode(display, XK_q), Mod4Mask | ShiftMask, DefaultRootWindow(display), true, GrabModeAsync, GrabModeAsync);
}
int main() {
	if(!(display = XOpenDisplay(NULL))) return 1;
	setup_hotkey();
	run();
	return 0;
}
