// ToobarStyleDoc.cpp : CToobarStyleDoc ���ʵ��
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


// CToobarStyleDoc ����/����

CToobarStyleDoc::CToobarStyleDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CToobarStyleDoc::~CToobarStyleDoc()
{
}

BOOL CToobarStyleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CToobarStyleDoc ���л�

void CToobarStyleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CToobarStyleDoc ���

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


// CToobarStyleDoc ����
