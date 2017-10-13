// ToobarStyleView.cpp : CToobarStyleView 类的实现
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CToobarStyleView 构造/析构

CToobarStyleView::CToobarStyleView()
{
	// TODO: 在此处添加构造代码

}

CToobarStyleView::~CToobarStyleView()
{
}

BOOL CToobarStyleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CToobarStyleView 绘制

void CToobarStyleView::OnDraw(CDC* /*pDC*/)
{
	CToobarStyleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CToobarStyleView 打印

BOOL CToobarStyleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CToobarStyleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CToobarStyleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CToobarStyleView 诊断

#ifdef _DEBUG
void CToobarStyleView::AssertValid() const
{
	CView::AssertValid();
}

void CToobarStyleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToobarStyleDoc* CToobarStyleView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToobarStyleDoc)));
	return (CToobarStyleDoc*)m_pDocument;
}
#endif //_DEBUG


// CToobarStyleView 消息处理程序
