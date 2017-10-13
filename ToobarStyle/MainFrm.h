// MainFrm.h : CMainFrame 类的接口
//


#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
public:
	CToolBar		m_wndStyleToolbar;
	CImageList		m_imgToobar;
	int				m_iIndex;

// 操作
public:
	BOOL LoadImageList(int iIndex);
	BOOL SetStyleToolbar();

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	afx_msg void OnStyleButton(UINT nID);
	afx_msg void OnSelectStyle(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAlienmorph();
public:
	afx_msg void OnGant();
public:
	afx_msg void OnMilk();
public:
	afx_msg void OnPixos();
public:
	afx_msg void OnJr3232();
public:
	afx_msg void OnOsx3232();
public:
	afx_msg void OnSmileD3232();
public:
	afx_msg void OnXp3232();
};