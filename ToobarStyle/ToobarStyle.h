// ToobarStyle.h : ToobarStyle Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CToobarStyleApp:
// �йش����ʵ�֣������ ToobarStyle.cpp
//

class CToobarStyleApp : public CWinApp
{
public:
	CToobarStyleApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CToobarStyleApp theApp;