// ToobarStyleDoc.h : CToobarStyleDoc ��Ľӿ�
//


#pragma once


class CToobarStyleDoc : public CDocument
{
protected: // �������л�����
	CToobarStyleDoc();
	DECLARE_DYNCREATE(CToobarStyleDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CToobarStyleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


