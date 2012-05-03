#pragma once


// CDrawPad 대화 상자입니다.

class CHS_Padview;

class CDrawPad : public CDialog
{
	DECLARE_DYNAMIC(CDrawPad)

public:
	CDrawPad(CWnd* pParent = NULL);   // 표준 생성자입니다.
	CHS_Padview *m_pView;
// 대화 상자 데이터입니다.
	enum { IDD = IDD_DRAWPAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
