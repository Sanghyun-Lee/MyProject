#pragma once


// CDrawPad ��ȭ �����Դϴ�.

class CHS_Padview;

class CDrawPad : public CDialog
{
	DECLARE_DYNAMIC(CDrawPad)

public:
	CDrawPad(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	CHS_Padview *m_pView;
// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DRAWPAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
