// ToobarStyleDoc.cpp : CToobarStyleDoc 类的实现
//

#include "stdafx.h"
#include "ToobarStyle.h"

#include "ToobarStyleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CToobarStyleDoc

IMPLEMENT_DYNCREATE(CToobarStyleDoc, CDocument)

BEGIN_MESSAGE_MAP(CToobarStyleDoc, CDocument)
END_MESSAGE_MAP()


// CToobarStyleDoc 构造/析构

CToobarStyleDoc::CToobarStyleDoc()
{
	// TODO: 在此添加一次性构造代码

}

CToobarStyleDoc::~CToobarStyleDoc()
{
}

BOOL CToobarStyleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CToobarStyleDoc 序列化

void CToobarStyleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CToobarStyleDoc 诊断

#ifdef _DEBUG
void CToobarStyleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CToobarStyleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CToobarStyleDoc 命令
