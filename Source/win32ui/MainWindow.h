#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "win32/Window.h"
#include "NiceStatus.h"
#include "OutputWnd.h"
#include "EventHandler.h"
#ifdef DEBUGGER_INCLUDED
#include "Debugger.h"
#endif

class CMainWindow : public Framework::CWindow
{
public:
									CMainWindow(char*);
									~CMainWindow();
	int								Loop();

protected:
	long							OnTimer();
	long							OnCommand(unsigned short, unsigned short, HWND);
	long							OnActivateApp(bool, unsigned long);

private:
	void							OpenELF();
	void							BootCDROM();
	void							ResumePause();
	void							Reset();
	void							PauseWhenFocusLost();
	void							SaveState();
	void							LoadState();
	void							ChangeStateSlot(unsigned int);
	void							ShowDebugger();
	void							ShowSysInfo();
	void							ShowAbout();
	void							ShowRendererSettings();
	void							ShowVfsManager();
	void							ShowMcManager();

	void							LoadELF(const char*);
	void							RefreshLayout();
	void							PrintVersion(xchar*, size_t);
	void							PrintStatusTextA(const char*, ...);
	void							SetStatusText(xchar*);
	void							CreateAccelerators();
	
	void							CreateDebugMenu();

	void							CreateStateSlotMenu();
	void							GenerateStatePath(char*);
	void							UpdateUI();

	void							OnNewFrame(int);
	void							OnOutputWndSizeChange(int);
	void							OnExecutableChange(int);

	Framework::CEventHandler<int>*	m_pOnOutputWndSizeChangeHandler;
	Framework::CEventHandler<int>*	m_pOnNewFrameHandler;
	Framework::CEventHandler<int>*	m_pOnExecutableChange;

	unsigned int					m_nFrames;
	HACCEL							m_nAccTable;

	unsigned int					m_nStateSlot;

	bool							m_nPauseFocusLost;
	bool							m_nDeactivatePause;

	CNiceStatus*					m_pStatusBar;
	COutputWnd*						m_pOutputWnd;
#ifdef DEBUGGER_INCLUDED
	CDebugger*						m_pDebugger;
#endif
};

#endif
