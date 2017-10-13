// ToobarStyleView.cpp : CToobarStyleView ���ʵ��
//

#include "stdafx.h"
#include "ToobarStyle.h"

#include "ToobarStyleDoc.h"
#include "ToobarStyleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CToobarStyleView

IMPLEMENT_DYNCREATE(CToobarStyleView, CView)

BEGIN_MESSAGE_MAP(CToobarStyleView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CToobarStyleView ����/����

CToobarStyleView::CToobarStyleView()
{
	// TODO: �ڴ˴���ӹ������

}

CToobarStyleView::~CToobarStyleView()
{
}

BOOL CToobarStyleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CToobarStyleView ����

void CToobarStyleView::OnDraw(CDC* /*pDC*/)
{
	CToobarStyleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CToobarStyleView ��ӡ

BOOL CToobarStyleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CToobarStyleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CToobarStyleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CToobarStyleView ���

#ifdef _DEBUG
void CToobarStyleView::AssertValid() const
{
	CView::AssertValid();
}

void CToobarStyleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToobarStyleDoc* CToobarStyleView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToobarStyleDoc)));
	return (CToobarStyleDoc*)m_pDocument;
}
#endif //_DEBUG


// CToobarStyleView ��Ϣ�������
