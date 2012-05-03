// Hs_PadView.h : CHs_PadView Ŭ������ �������̽�
//


#pragma once
class CTextPadDlg;
class CUrlSearchDlg;
class CDrawPadDlg;

class CHs_PadView : public CView
{
protected: // serialization������ ��������ϴ�.
	CHs_PadView();
	DECLARE_DYNCREATE(CHs_PadView)

// Ư���Դϴ�.
public:
	CHs_PadDoc* GetDocument() const;
	CTextPadDlg *TextPadDlg;
	CUrlSearchDlg *UrlSearchDlg;
	CDrawPadDlg *DrawPadDlg;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CHs_PadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnUrl();
	afx_msg void OnTextpad();
	afx_msg void OnDrawpad();
};

#ifndef _DEBUG  // Hs_PadView.cpp�� ����� ����
inline CHs_PadDoc* CHs_PadView::GetDocument() const
   { return reinterpret_cast<CHs_PadDoc*>(m_pDocument); }
#endif

