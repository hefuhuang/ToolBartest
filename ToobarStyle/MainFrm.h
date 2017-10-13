// MainFrm.h : CMainFrame ��Ľӿ�
//


#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:
	CToolBar		m_wndStyleToolbar;
	CImageList		m_imgToobar;
	int				m_iIndex;

// ����
public:
	BOOL LoadImageList(int iIndex);
	BOOL SetStyleToolbar();

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// ���ɵ���Ϣӳ�亯��
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