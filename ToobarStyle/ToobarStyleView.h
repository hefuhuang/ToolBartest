// ToobarStyleView.h : CToobarStyleView ��Ľӿ�
//


#pragma once


class CToobarStyleView : public CView
{
protected: // �������л�����
	CToobarStyleView();
	DECLARE_DYNCREATE(CToobarStyleView)

// ����
public:
	CToobarStyleDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CToobarStyleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ToobarStyleView.cpp �еĵ��԰汾
inline CToobarStyleDoc* CToobarStyleView::GetDocument() const
   { return reinterpret_cast<CToobarStyleDoc*>(m_pDocument); }
#endif

