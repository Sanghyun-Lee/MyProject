// Hs_PadDoc.h : CHs_PadDoc Ŭ������ �������̽�
//


#pragma once


class CHs_PadDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CHs_PadDoc();
	DECLARE_DYNCREATE(CHs_PadDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CHs_PadDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};


