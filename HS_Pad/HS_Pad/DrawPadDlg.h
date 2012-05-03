#pragma once
#include "afxwin.h"

#define SELECT_PEN 0
#define SELECT_RECT 1
#define SELECT_ELLIPSE 2
#define SELECT_ROUNDRECT 3
#define SELECT_POLYGON 4
#define SELECT_ERASER 5
#define SELECT_LINE 7
#define SELECT_SPOID 8

#define SELECT_NO_OUTLINE 0
#define SELECT_FILL 1
#define SELECT_OUTLINE 2
#define ROUNDRECT_DELIMETER 10
#define NO_MEAN_NUMBER 4


// CDrawPadDlg dialog
class CHs_PadView;

class CDrawPadDlg : public CDialog
{
	DECLARE_DYNAMIC(CDrawPadDlg)
public:
	CDrawPadDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDrawPadDlg();
	CHs_PadView *m_pView;
	CRect drawPicCtrl, penPicCtrl, brushPicCtrl; //------------------------> 추가
	
	BOOL m_bDrawMode;
	
	int m_x1, m_y1, m_x2, m_y2;
	CRgn rgn;
	CArray <CPoint, CPoint&> startPoint;
	CArray <CPoint, CPoint&> endPoint;
	CArray <UINT, UINT> selectDrawArray;
	CArray <COLORREF, COLORREF> pencolorArray;
	CArray <COLORREF, COLORREF> brushcolorArray;
	int figureLineType;
	CPoint pt1, pt2;
	CArray <UINT, UINT> lineoff;
	CArray <UINT, UINT> pensizeArray;
	COLORREF penColor, brushColor, spoid;  //------------------------->추가

	CPoint polygon[255][255];
	int polygonCount;
	int polyPoint;
	int polyPointCount[255];
	
	int m_pensize;
	int red, green, blue;	
	CArray <UINT, UINT> element;
	int elementcount;
	int m_cx, m_cy;

	CDC memDC;
	CBitmap bitmap;
	BITMAP bmpinfo;
// Dialog Data
	enum { IDD = IDD_DRAWPADDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic drawing;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	int m_radiobutton;
	afx_msg void OnBnClickedColorselect();
	afx_msg void OnBnClickedBrushselect();
	void CDrawPadDlg::SaveBitmapToDirectFIle(CDC *pDC, CRect BitmapSize, int BitCount, CString strFilePath);

	int m_line;
	afx_msg void OnCbnSelchangeLinesize();
	CComboBox selectLineSize;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedUndo();
	afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedSave();
	void intserArray(int drawType, int penSize, int figureLine, COLORREF penColor, COLORREF brushColor);
	CBitmapButton saveBtn;
	CBitmapButton loadBtn;
	CBitmapButton undo;

	CBitmapButton colorSelect;
	CBitmapButton brushColorSelect;
	afx_msg void OnBnClickedNew();
	CBitmapButton newPage;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
