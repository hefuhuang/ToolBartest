// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "ToobarStyle.h"

#include "MainFrm.h"

#include <shlwapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static TCHAR ToolbarStyle[][20] = 
{
	_T("AlienMorph"),
	_T("Gant 风格版"),
	_T("Milk 风格版"),
	_T("PixOS 风格版"),
	_T("Jr_32x32"),
	_T("OS_X_32x32"),
	_T("Smile_d_32x32"),
	_T("XP_32x32")
};

static TCHAR BmpName[][20] = 
{
	_T("Add.bmp"),
	_T("Benchmark.bmp"),
	_T("Comment.bmp"),
	_T("Convert.bmp"),
	_T("Delete.bmp"),
	_T("Exit.bmp"),
	_T("Extract.bmp"),
	_T("ExtractTo.bmp"),
	_T("Find.bmp"),
	_T("Info.bmp"),
	_T("Lock.bmp"),
	_T("Print.bmp"),
	_T("Protect.bmp"),
	_T("Repair.bmp"),
	_T("Report.bmp"),
	_T("SFX.bmp"),
	_T("Test.bmp"),
	_T("View.bmp"),
	_T("VirusScan.bmp"),
	_T("Wizard.bmp")
};

static TBBUTTON tb[] =
{
	{  0,  4000,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  1,  4001,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  2,  4002,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  3,  4003,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  4,  4004,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  5,  4005,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  6,  4006,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  7,  4007,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  8,  4008,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  9,  4009,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  10, 4010,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  11, 4011,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  12, 4012,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  13, 4013,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  14, 4014,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  15, 4015,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  16, 4016,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  17, 4017,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  18, 4018,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 },
	{  19, 4019,	TBSTATE_ENABLED, TBSTYLE_BUTTON,	0, 0 }
};

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND_RANGE(4000, 4019, OnStyleButton)
	ON_COMMAND(ID_ALIENMORPH, &CMainFrame::OnAlienmorph)
	ON_COMMAND(ID_GANT, &CMainFrame::OnGant)
	ON_COMMAND(ID_MILK, &CMainFrame::OnMilk)
	ON_COMMAND(ID_PIXOS, &CMainFrame::OnPixos)
	ON_COMMAND(ID_JR3232, &CMainFrame::OnJr3232)
	ON_COMMAND(ID_OSX3232, &CMainFrame::OnOsx3232)
	ON_COMMAND(ID_SMILE_D3232, &CMainFrame::OnSmileD3232)
	ON_COMMAND(ID_XP3232, &CMainFrame::OnXp3232)
	ON_UPDATE_COMMAND_UI_RANGE(ID_ALIENMORPH, ID_XP3232, OnSelectStyle)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame 构造/析构

CMainFrame::CMainFrame() : m_iIndex(0)
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}

	// TODO: 如果不需要工具栏可停靠，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	m_wndStyleToolbar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD|WS_VISIBLE|CBRS_TOP
		|CBRS_GRIPPER|CBRS_TOOLTIPS|CBRS_FLYBY|CBRS_SIZE_DYNAMIC);
	m_imgToobar.Create(32, 32, ILC_COLOR32|ILC_MASK, 0, 0);
	LoadImageList(m_iIndex);
	SetStyleToolbar();
	
	m_wndStyleToolbar.SetSizes(CSize(32+7, 32+6), CSize(32, 32));
	m_wndStyleToolbar.EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndStyleToolbar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}


// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame 消息处理程序



void CMainFrame::OnStyleButton(UINT nID)
{
}

void CMainFrame::OnAlienmorph()
{
	// TODO: 在此添加命令处理程序代码
	if(m_iIndex != 0)
	{
		m_iIndex = 0;
		LoadImageList(m_iIndex);
		SetStyleToolbar();
	}
}

void CMainFrame::OnGant()
{
	// TODO: 在此添加命令处理程序代码
	if(m_iIndex != 1)
	{
		m_iIndex = 1;
		LoadImageList(m_iIndex);
		SetStyleToolbar();
	}
}

void CMainFrame::OnMilk()
{
	// TODO: 在此添加命令处理程序代码
	if(m_iIndex != 2)
	{
		m_iIndex = 2;
		LoadImageList(m_iIndex);
		SetStyleToolbar();
	}
}

void CMainFrame::OnPixos()
{
	// TODO: 在此添加命令处理程序代码
	if(m_iIndex != 3)
	{
		m_iIndex = 3;
		LoadImageList(m_iIndex);
		SetStyleToolbar();
	}
}

void CMainFrame::OnJr3232()
{
	// TODO: 在此添加命令处理程序代码
	if(m_iIndex != 4)
	{
		m_iIndex = 4;
		LoadImageList(m_iIndex);
		SetStyleToolbar();
	}
}

void CMainFrame::OnOsx3232()
{
	// TODO: 在此添加命令处理程序代码
	if(m_iIndex != 5)
	{
		m_iIndex = 5;
		LoadImageList(m_iIndex);
		SetStyleToolbar();
	}
}

void CMainFrame::OnSmileD3232()
{
	// TODO: 在此添加命令处理程序代码
	if(m_iIndex != 6)
	{
		m_iIndex = 6;
		LoadImageList(m_iIndex);
		SetStyleToolbar();
	}
}

void CMainFrame::OnXp3232()
{
	// TODO: 在此添加命令处理程序代码
	if(m_iIndex != 7)
	{
		m_iIndex = 7;
		LoadImageList(m_iIndex);
		SetStyleToolbar();
	}
}


BOOL CMainFrame::LoadImageList(int iIndex)
{
	int			iTotal				= sizeof(BmpName) / sizeof(BmpName[0]);
	int			i					= 0;
	TCHAR		strPath[MAX_PATH]	= { 0 };
	TCHAR		strFull[MAX_PATH]	= { 0 };
	HBITMAP		hBitmap				= NULL;
	
	while(m_imgToobar.Remove(0));
	GetCurrentDirectory(MAX_PATH, strPath);
	StrCat(strPath, _T("\\Themes\\"));
	StrCat(strPath, ToolbarStyle[iIndex]);
	StrCat(strPath, _T("\\Toolbar\\"));
	for(i=0; i<iTotal; ++i)
	{
		StrCpy(strFull, strPath);
		StrCat(strFull, BmpName[i]);
		hBitmap = (HBITMAP)LoadImage(AfxGetResourceHandle(), strFull, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR|LR_LOADFROMFILE);
		CBitmap		bmp;
		bmp.Attach(hBitmap);
		m_imgToobar.Add(&bmp, RGB(0, 0, 0));
		bmp.DeleteObject();
	}

	return TRUE;
}

BOOL CMainFrame::SetStyleToolbar()
{
	CToolBarCtrl&	tbc	= m_wndStyleToolbar.GetToolBarCtrl();
	while(tbc.DeleteButton(0));
	tbc.SetImageList(&m_imgToobar);
	int		i			= 0;
	int		iButtons	= sizeof(tb) / sizeof(tb[0]);
	for(i=0; i<iButtons; ++i)
	{
		tbc.AddButtons(1, &tb[i]);
	}
	return TRUE;
}

void CMainFrame::OnSelectStyle(CCmdUI* pCmdUI)
{
	if(pCmdUI->m_nID == m_iIndex+ID_ALIENMORPH)
	{
		pCmdUI->SetCheck(1);
	}
	else
	{
		pCmdUI->SetCheck(0);
	}
}