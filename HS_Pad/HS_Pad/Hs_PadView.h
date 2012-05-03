// Hs_PadView.h : CHs_PadView 클래스의 인터페이스
//


#pragma once
class CTextPadDlg;
class CUrlSearchDlg;
class CDrawPadDlg;

class CHs_PadView : public CView
{
protected: // serialization에서만 만들어집니다.
	CHs_PadView();
	DECLARE_DYNCREATE(CHs_PadView)

// 특성입니다.
public:
	CHs_PadDoc* GetDocument() const;
	CTextPadDlg *TextPadDlg;
	CUrlSearchDlg *UrlSearchDlg;
	CDrawPadDlg *DrawPadDlg;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CHs_PadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnUrl();
	afx_msg void OnTextpad();
	afx_msg void OnDrawpad();
};

#ifndef _DEBUG  // Hs_PadView.cpp의 디버그 버전
inline CHs_PadDoc* CHs_PadView::GetDocument() const
   { return reinterpret_cast<CHs_PadDoc*>(m_pDocument); }
#endif

