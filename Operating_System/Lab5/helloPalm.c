//helloPalm.c#
#include <PalmOS.h>
UInt32 PilotMain(UInt16 cmd,void *cmdPBP, UInt16 launchFlags)
{
	EventType event;
	if (cmd==sysAppLaunchCmdNormalLaunch){
		WinDrawChars("Hello Palm!",10,55,60);
		do{
			EvtGetEvent(&event, evtWaitForever);
			SysHandleEvent(&event);
		} while (event.eType!=appStopEvent);
	}
	return 0;
}
