// DrawPadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Hs_Pad.h"
#include "DrawPadDlg.h"
#include "Hs_PadDoc.h"
#include "Hs_PadView.h"

// CDrawPadDlg dialog

IMPLEMENT_DYNAMIC(CDrawPadDlg, CDialog)

CDrawPadDlg::CDrawPadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDrawPadDlg::IDD, pParent)
	
	, m_radiobutton(0)
	, m_line(0)
{
	m_pView = NULL;
	m_bDrawMode  = FALSE;
	m_pensize = 1;
	red = 0;
	green = 0;
	blue = 0;
	polygonCount = 0;
	polyPoint = 0;
	elementcount = 0;
	m_cx = m_cy = 0;
	figureLineType = 0;
}

CDrawPadDlg::~CDrawPadDlg()
{
}

void CDrawPadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DRAWING, drawing);
	DDX_Radio(pDX, IDC_PEN, m_radiobutton);
	DDX_CBIndex(pDX, IDC_LINESIZE, m_pensize);
	DDX_Radio(pDX, IDC_NOOUTLINE, m_line);
	DDX_Control(pDX, IDC_LINESIZE, selectLineSize);
	DDX_Control(pDX, IDC_SAVE, saveBtn);
	DDX_Control(pDX, IDC_LOAD, loadBtn);
	DDX_Control(pDX, IDC_UNDO, undo);
	DDX_Control(pDX, IDC_COLORSELECT, colorSelect);
	DDX_Control(pDX, IDC_BRUSHSELECT, brushColorSelect);
	DDX_Control(pDX, IDC_NEW, newPage);
}


BEGIN_MESSAGE_MAP(CDrawPadDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_COLORSELECT, &CDrawPadDlg::OnBnClickedColorselect)
	ON_BN_CLICKED(IDC_BRUSHSELECT, &CDrawPadDlg::OnBnClickedBrushselect)
	ON_CBN_SELCHANGE(IDC_LINESIZE, &CDrawPadDlg::OnCbnSelchangeLinesize)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_UNDO, &CDrawPadDlg::OnBnClickedUndo)
	ON_BN_CLICKED(IDC_LOAD, &CDrawPadDlg::OnBnClickedLoad)
	ON_BN_CLICKED(IDC_SAVE, &CDrawPadDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_NEW, &CDrawPadDlg::OnBnClickedNew)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDrawPadDlg message handlers

BOOL CDrawPadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	GetDlgItem(IDC_DRAWING)->MoveWindow(100,10,610,430);
	GetDlgItem(IDC_DRAWING)->GetWindowRect(drawPicCtrl);//픽처컨트롤의 범위를 구함
	ScreenToClient(drawPicCtrl);

	rgn.CreateRectRgnIndirect(drawPicCtrl);//픽처컨트롤 내부를 리전으로 설정

	GetDlgItem(IDC_COLOR)->GetWindowRect(penPicCtrl);
	ScreenToClient(penPicCtrl);

	GetDlgItem(IDC_BRUSHCOLOR)->GetWindowRect(brushPicCtrl);
	ScreenToClient(brushPicCtrl);

	saveBtn.LoadBitmaps(IDB_BITMAP1, IDB_BITMAP2, NULL, NULL);
	saveBtn.SizeToContent();

	loadBtn.LoadBitmaps(IDB_BITMAP3, IDB_BITMAP4, NULL, NULL);
	loadBtn.SizeToContent();

	newPage.LoadBitmaps(IDB_BITMAP33, IDB_BITMAP34, NULL, NULL);
	newPage.SizeToContent();

	undo.LoadBitmaps(IDB_BITMAP20, IDB_BITMAP21, NULL, IDB_BITMAP22);
	undo.SizeToContent();

	colorSelect.LoadBitmaps(IDB_BITMAP29, IDB_BITMAP31, NULL, NULL);
	colorSelect.SizeToContent();

	brushColorSelect.LoadBitmaps(IDB_BITMAP30, IDB_BITMAP32, NULL, NULL);
	brushColorSelect.SizeToContent();

	selectLineSize.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDrawPadDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages
	
	CBrush brush_drawPicCtrl, brush_penPicCtrl, brush_brushPicCtrl;
	brush_drawPicCtrl.CreateSolidBrush(RGB(255, 255, 255));
	brush_penPicCtrl.CreateSolidBrush(penColor);			
	brush_brushPicCtrl.CreateSolidBrush(brushColor);	

	dc.SelectObject(&brush_drawPicCtrl);
	dc.FillRect(drawPicCtrl, &brush_drawPicCtrl);

	dc.SelectObject(&brush_penPicCtrl);			
	dc.FillRect(penPicCtrl, &brush_penPicCtrl);		

	dc.SelectObject(&brush_brushPicCtrl);				
	dc.FillRect(brushPicCtrl, &brush_brushPicCtrl);			

	CPen pen_drawPen, pen_drawBrush, eraser;
	CBrush mainbrush;
	
	drawing.RedrawWindow();
	
	dc.SelectStockObject(NULL_BRUSH);
	dc.SelectClipRgn(&rgn);//픽처컨트롤 안에만 그리게 만듬
	
	for(int i = 0, n = 0; i < startPoint.GetSize(); i++){
			
		pen_drawPen.CreatePen(PS_SOLID,pensizeArray[i],pencolorArray[i]);
		pen_drawBrush.CreatePen(PS_SOLID,pensizeArray[i],brushcolorArray[i]);
		eraser.CreatePen(PS_SOLID,pensizeArray[i],RGB(255,255,255));
		mainbrush.CreateSolidBrush(brushcolorArray[i]);		

		dc.SelectObject(&pen_drawPen);

		switch(selectDrawArray[i]){
			case SELECT_PEN:
				dc.MoveTo(startPoint[i].x, startPoint[i].y);
				dc.LineTo(endPoint[i].x, endPoint[i].y);
				break;
			case SELECT_RECT:
				switch(lineoff[i]){
					case SELECT_NO_OUTLINE:
						dc.SelectObject(&pen_drawBrush);
						dc.SelectObject(&mainbrush);
						break;
					case SELECT_FILL:
						dc.SelectObject(&mainbrush);
						break;
					case SELECT_OUTLINE:
						dc.SelectStockObject(NULL_BRUSH);
						break;
				}
				dc.Rectangle(startPoint[i].x, startPoint[i].y, 
					endPoint[i].x, endPoint[i].y);
				break;
			case SELECT_ELLIPSE:
				switch(lineoff[i]){
					case SELECT_NO_OUTLINE:
						dc.SelectObject(&pen_drawBrush);
						dc.SelectObject(&mainbrush);
						break;
					case SELECT_FILL:
						dc.SelectObject(&mainbrush);
						break;
					case SELECT_OUTLINE:
						dc.SelectStockObject(NULL_BRUSH);
						break;
				}
				dc.Ellipse(startPoint[i].x, startPoint[i].y, 
					endPoint[i].x, endPoint[i].y);
				break;
			case SELECT_ROUNDRECT:
				switch(lineoff[i]){
					case SELECT_NO_OUTLINE:
						dc.SelectObject(&pen_drawBrush);
						dc.SelectObject(&mainbrush);
						break;
					case SELECT_FILL:
						dc.SelectObject(&mainbrush);
						break;
					case SELECT_OUTLINE:
						dc.SelectStockObject(NULL_BRUSH);
						break;
				}
				dc.RoundRect(startPoint[i].x, startPoint[i].y, 
					endPoint[i].x, endPoint[i].y,
					((startPoint[i].x-endPoint[i].x)/2), ((startPoint[i].x-endPoint[i].x)/2));
				break;
			case SELECT_POLYGON:
				switch(lineoff[i]){
					case SELECT_NO_OUTLINE:
						dc.SelectObject(&pen_drawBrush);
						dc.SelectObject(&mainbrush);
						break;
					case SELECT_FILL:
						dc.SelectObject(&mainbrush);
						break;
					case SELECT_OUTLINE:
						dc.SelectStockObject(NULL_BRUSH);
						break;
				}

			
				dc.Polygon(polygon[n], polyPointCount[n]+1);
				n++;

				break;
			case SELECT_ERASER:
				dc.SelectObject(&eraser);
				dc.MoveTo(startPoint[i].x, startPoint[i].y);
				dc.LineTo(endPoint[i].x, endPoint[i].y);
				break;
			case SELECT_LINE:
				dc.MoveTo(startPoint[i].x, startPoint[i].y);
				dc.LineTo(endPoint[i].x, endPoint[i].y);
				
				break;
		}
		brush_brushPicCtrl.DeleteObject();
		pen_drawPen.DeleteObject();
		pen_drawBrush.DeleteObject();
		eraser.DeleteObject();
		mainbrush.DeleteObject();
	}
}


void CDrawPadDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetCapture();
	if(rgn.PtInRegion(point)){
		// TODO: Add your message handler code here and/or call default
		UpdateData(TRUE);
		
		m_bDrawMode = TRUE;

		m_x1 = m_x2 = point.x;
		m_y1 = m_y2 = point.y;
		pt1 = pt2 = point;
		
		if(m_radiobutton == SELECT_POLYGON){
			if(polyPoint == 0){
				startPoint.Add(point);
				elementcount++;
				element.Add(elementcount);
			}
			polygon[polygonCount][polyPoint] = point;
		}else if(m_radiobutton == SELECT_SPOID){
			
			CClientDC dc(this);
			spoid = dc.GetPixel(point);
			red = GetRValue(spoid); 
			blue = GetBValue(spoid);
			green = GetGValue(spoid);
			penColor = RGB(red,green,blue);
		
			Invalidate();

		}else{
			startPoint.Add(point);
			elementcount++;
			element.Add(elementcount);
		}
	}

	CDialog::OnLButtonDown(nFlags, point);
}

void CDrawPadDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
		if(m_bDrawMode){
			CClientDC dc(this);
			dc.SelectClipRgn(&rgn);

			dc.SelectStockObject(NULL_BRUSH);    
			
			CPen pen1, pen2, eraser;
			pen1.CreatePen(PS_SOLID, m_pensize, penColor);
			pen2.CreatePen(PS_SOLID, m_pensize, brushColor);
			eraser.CreatePen(PS_SOLID, m_pensize, RGB(255,255,255));
			dc.SelectObject(&pen1);
			
			CBrush brush;
			brush.CreateSolidBrush(brushColor);
			
			switch(m_radiobutton){
				case SELECT_PEN:
					dc.MoveTo(pt1);
					dc.LineTo(point);
					element.Add(elementcount);
					intserArray(SELECT_PEN, m_pensize, 
						NO_MEAN_NUMBER, penColor, brushColor);
					startPoint.Add(point);
					endPoint.Add(point);
					pt1 = point;   
					break;
				
				case SELECT_RECT:
					
					switch(m_line){
						case SELECT_NO_OUTLINE:
							dc.SelectObject(&pen2);
							dc.SelectObject(&brush);
							break;
						case SELECT_FILL:
							dc.SelectObject(&brush);
							break;
						case SELECT_OUTLINE:
							dc.SetROP2(R2_NOT);
					}
					dc.SetROP2(R2_NOT);
					dc.Rectangle(m_x1, m_y1, m_x2, m_y2);
					dc.SetROP2(R2_NOT);
					m_x2 = point.x;
					m_y2 = point.y;
					dc.Rectangle(m_x1, m_y1, m_x2, m_y2);
					break;
				case SELECT_ELLIPSE:

					switch(m_line){
						case SELECT_NO_OUTLINE:
							dc.SelectObject(&pen2);
							dc.SelectObject(&brush);
							break;
						case SELECT_FILL:
							dc.SelectObject(&brush);
							break;
						case SELECT_OUTLINE:
							dc.SetROP2(R2_NOT);
					}

					dc.SetROP2(R2_NOT);
					dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
					dc.SetROP2(R2_NOT);
					m_x2 = point.x;
					m_y2 = point.y;
					dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
					break;
				case SELECT_ROUNDRECT:

					switch(m_line){
						case SELECT_NO_OUTLINE:
							dc.SelectObject(&pen2);
							dc.SelectObject(&brush);
							break;
						case SELECT_FILL:
							dc.SelectObject(&brush);
							break;
						case SELECT_OUTLINE:
							dc.SetROP2(R2_NOT);
					}

					dc.SetROP2(R2_NOT);
					dc.RoundRect(m_x1, m_y1, m_x2, m_y2, ((m_x1-m_x2)/2), ((m_x1-m_x2)/2));
					dc.SetROP2(R2_NOT);
					m_x2 = point.x;
					m_y2 = point.y;
					dc.RoundRect(m_x1, m_y1, m_x2, m_y2, ((m_x1-m_x2)/2), ((m_x1-m_x2)/2));
					break;
				case SELECT_POLYGON :
					dc.SetROP2(R2_NOT);
					dc.MoveTo(pt1);
					dc.LineTo(pt2);
					dc.SetROP2(R2_NOT);
					pt2 = point;
					dc.MoveTo(pt1);
					dc.LineTo(point);
					break;
				case SELECT_ERASER:
					dc.SelectObject(&eraser);
					dc.MoveTo(pt1);
					dc.LineTo(point);
					
					element.Add(elementcount);
					intserArray(SELECT_ERASER, m_pensize, 
						NO_MEAN_NUMBER, penColor, brushColor);

					startPoint.Add(point);
					endPoint.Add(point);
					pt1 = point;   
					break;
				case SELECT_LINE:
					
					dc.SetROP2(R2_NOT);
					dc.MoveTo(pt1);
					dc.LineTo(pt2);
					dc.SetROP2(R2_NOT);
					pt2 = point;
					dc.MoveTo(pt1);
					dc.LineTo(point);

					break;
			}
			pen1.DeleteObject();
			pen2.DeleteObject();
			eraser.DeleteObject();
			brush.DeleteObject();

		}

	
	CDialog::OnMouseMove(nFlags, point);
}

void CDrawPadDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	CClientDC dc(this);
	dc.SelectClipRgn(&rgn);
	
	dc.SelectStockObject(NULL_BRUSH);
	dc.SetROP2(R2_COPYPEN);
	m_x2 = point.x;
	m_y2 = point.y;

	if(polyPoint == 0){
		endPoint.Add(point);
	}

	CPen pen1, pen2;
	pen1.CreatePen(PS_SOLID, m_pensize, penColor);
	pen2.CreatePen(PS_SOLID, m_pensize, brushColor);
	dc.SelectObject(&pen1);
			
	CBrush brush_drawPicCtrl, brush_penPicCtrl;
	brush_drawPicCtrl.CreateSolidBrush(brushColor);

	switch(m_radiobutton){
		case SELECT_PEN:
			intserArray(SELECT_PEN, m_pensize, 
				figureLineType, penColor, brushColor);
			break;
		case SELECT_RECT:
			switch(m_line){
				case SELECT_NO_OUTLINE:
					dc.SelectObject(&pen2);
					dc.SelectObject(&brush_drawPicCtrl);
					figureLineType = SELECT_NO_OUTLINE;
					break;
				case SELECT_FILL:
					dc.SelectObject(&brush_drawPicCtrl);
					figureLineType = SELECT_FILL;
					break;
				case SELECT_OUTLINE:
					figureLineType = SELECT_OUTLINE;
					break;
			}

			dc.Rectangle(m_x1, m_y1, m_x2, m_y2);
				
			intserArray(SELECT_RECT, m_pensize, 
			figureLineType, penColor, brushColor);
			break;
		case SELECT_ELLIPSE:
				
			switch(m_line){
				case SELECT_NO_OUTLINE:
					dc.SelectObject(&pen2);
					dc.SelectObject(&brush_drawPicCtrl);
					figureLineType = SELECT_NO_OUTLINE;
					break;
				case SELECT_FILL:
					dc.SelectObject(&brush_drawPicCtrl);
					figureLineType = SELECT_FILL;
					break;
				case SELECT_OUTLINE:
					figureLineType = SELECT_OUTLINE;
					break;
			}

			dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
			
			intserArray(SELECT_ELLIPSE, m_pensize, 
				figureLineType, penColor, brushColor);
			break;
		case SELECT_ROUNDRECT:

			switch(m_line){
				case SELECT_NO_OUTLINE:
					dc.SelectObject(&pen2);
					dc.SelectObject(&brush_drawPicCtrl);
					figureLineType = SELECT_NO_OUTLINE;
					break;
				case SELECT_FILL:
					dc.SelectObject(&brush_drawPicCtrl);
					figureLineType = SELECT_FILL;
					break;
				case SELECT_OUTLINE:
					figureLineType = SELECT_OUTLINE;
					break;
			}

			dc.RoundRect(m_x1, m_y1, m_x2, m_y2, ((m_x1-m_x2)/2), ((m_x1-m_x2)/2));
			
			intserArray(SELECT_ROUNDRECT, m_pensize, 
				figureLineType, penColor, brushColor);
			break;
		case SELECT_POLYGON:
			switch(m_line){
				case SELECT_NO_OUTLINE:
					dc.SelectObject(&pen1);
					dc.SelectObject(&brush_drawPicCtrl);
					figureLineType = SELECT_NO_OUTLINE;
					break;
				case SELECT_FILL:
					dc.SelectObject(&brush_drawPicCtrl);
					figureLineType = SELECT_FILL;
					break;
				case SELECT_OUTLINE:
					dc.SelectStockObject(NULL_BRUSH);
					figureLineType = SELECT_OUTLINE;
					break;
			}

			dc.MoveTo(pt1);
			dc.LineTo(point);
			
			if(polyPoint == 0){							
				intserArray(SELECT_POLYGON, m_pensize,
					figureLineType, penColor, brushColor);	
			}
			polyPoint++;
			break;
		case SELECT_ERASER:
			intserArray(SELECT_ERASER, m_pensize,
				NO_MEAN_NUMBER, penColor, brushColor);
			break;
		case SELECT_LINE:
			dc.MoveTo(pt1);
			dc.LineTo(point);
			element.Add(elementcount);
			intserArray(SELECT_LINE, m_pensize,
				NO_MEAN_NUMBER, penColor, brushColor);	
			break;
		case SELECT_SPOID:


			break;
	}
	m_bDrawMode = FALSE;

	pen1.DeleteObject();
	pen2.DeleteObject();
	brush_drawPicCtrl.DeleteObject();
	brush_penPicCtrl.DeleteObject();
	
	::ReleaseCapture();
	CDialog::OnLButtonUp(nFlags, point);
}


void CDrawPadDlg::OnBnClickedColorselect()
{
	CColorDialog dlg;
	dlg.DoModal();
	penColor = dlg.GetColor();
	Invalidate();
}

void CDrawPadDlg::OnBnClickedBrushselect()
{
	CColorDialog dlg;
	dlg.DoModal();
	brushColor = dlg.GetColor();
	Invalidate();
}

void CDrawPadDlg::OnCbnSelchangeLinesize()
{
	int nIndex = selectLineSize.GetCurSel();
	if(nIndex == -1){
		return;
	}

	CString str;
	selectLineSize.GetLBText(nIndex, str);
	m_pensize = _ttoi(str);
}


void CDrawPadDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);

	polygon[polygonCount][polyPoint] = point;
	polyPointCount[polygonCount] = polyPoint;
	polygonCount++;
	polyPoint = 0;
	Invalidate();
	CDialog::OnRButtonDown(nFlags, point);
}

void CDrawPadDlg::OnBnClickedUndo()
{
	int felement = 0;
	int elementsize = 0;
	
	elementsize =selectDrawArray.GetSize()-1;

	for(int n=elementsize; n >= 0; n--){
		felement = element.GetAt(n);
		if(elementcount != felement){			
			break;
		}else{
			if(selectDrawArray[n] == SELECT_POLYGON){
				for(int m =0; m<polyPointCount[polygonCount]; m++){
					polygon[polygonCount][m]=(0,0);
				}
				polyPointCount[polygonCount]=0;
				polygonCount--;
				polyPoint=0;
					
			}

			element.RemoveAt(n);
			selectDrawArray.RemoveAt(n);

			startPoint.RemoveAt(n);
			endPoint.RemoveAt(n);

			lineoff.RemoveAt(n);			
			pencolorArray.RemoveAt(n);
			brushcolorArray.RemoveAt(n);
			pensizeArray.RemoveAt(n);			
		}
	}

	if(elementcount > 0){
		elementcount--;
	}
	Invalidate();	
}

void CDrawPadDlg::OnBnClickedLoad()
{	
	char szFilter[] = "Image (*.BMP)|*.BMP|All Files(*.*)|*.*||";
	CFileDialog filedlg(TRUE,"Bmp file(*.bmp)","*.bmp",OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, szFilter ,NULL);
	if(IDOK == filedlg.DoModal())
	{
	CString szFilePath = filedlg.GetPathName();
	HBITMAP hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), szFilePath,IMAGE_BITMAP,0,0, 
		LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	
		if(hBmp){
			HBITMAP hBmpOld = drawing.GetBitmap();
			drawing.SetBitmap(hBmp);
			if(hBmpOld){
				DeleteObject(hBmpOld);
			}
		}
		CDrawPadDlg::OnSize(SIZE_RESTORED, m_cx, m_cy);
	}	
}

void CDrawPadDlg::OnBnClickedSave()
{
	CDC *pDC = drawing.GetDC();
	GetDlgItem(IDC_DRAWING)->GetWindowRect(drawPicCtrl);
	ScreenToClient(drawPicCtrl);

	LPCTSTR lpszFilter = "BMP FILE(*.bmp) | *.bmp | All FIles | *.*||";
	CString strPath;
	bool m_bDraw = FALSE;

	CFileDialog dlg(FALSE, ".pt", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, lpszFilter);

	if(dlg.DoModal() == IDOK){
		strPath.Format("%s", dlg.GetFileName());
		m_bDraw = TRUE;
	}

	RedrawWindow();
	if(m_bDraw){
		CDrawPadDlg::SaveBitmapToDirectFIle(pDC, drawPicCtrl, 0, strPath);	
	}
}
void CDrawPadDlg::SaveBitmapToDirectFIle(CDC *pDC, CRect BitmapSize, int BitCount, CString strFilePath)
{
	CBitmap bmp, *pOldBmp;
	CDC dcMem;
	BITMAP bm;
	BITMAPINFOHEADER bi;
	LPBITMAPINFOHEADER lpbi;
	DWORD dwLen;
	HANDLE handle;
	HANDLE hDIB;
	HPALETTE hPal = NULL;

	dcMem.CreateCompatibleDC(pDC);
	bmp.CreateCompatibleBitmap(pDC, BitmapSize.Width(), BitmapSize.Height());
	pOldBmp = (CBitmap *)dcMem.SelectObject(&bmp);
	dcMem.BitBlt(0, 0, BitmapSize.Width(), BitmapSize.Height(), pDC, 0, 0, SRCCOPY);
	dcMem.SelectObject(pOldBmp);

	if(strFilePath == ""){
		return;
	}

	if(hPal == NULL)
	hPal = (HPALETTE) GetStockObject(DEFAULT_PALETTE);
	GetObject(HBITMAP(bmp), sizeof(BITMAP), &bm);
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = bm.bmWidth;
	bi.biHeight = bm.bmHeight;
	bi.biPlanes = 1;
	bi.biBitCount = 32;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = bm.bmWidth *bm.bmHeight * 3;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;

	int nColors = (1 << bi.biBitCount);
	if(nColors > 256)
		nColors = 0;
	
	dwLen = bi.biSize + nColors * sizeof(RGBQUAD);
	hPal = SelectPalette(pDC->GetSafeHdc(), hPal, FALSE);
	RealizePalette(pDC->GetSafeHdc());
	hDIB = GlobalAlloc(GMEM_FIXED, dwLen);
	lpbi = (LPBITMAPINFOHEADER)hDIB;
	*lpbi = bi;
	GetDIBits(pDC->GetSafeHdc(),
		HBITMAP(bmp),
		0,
		(DWORD)bi.biHeight,
		(LPBYTE)NULL,
		(LPBITMAPINFO)lpbi,
		(DWORD)DIB_RGB_COLORS);
	bi = *lpbi;
	if(bi.biSizeImage == 0){
		bi.biSizeImage = ((((bi.biWidth * bi.biBitCount) + 31) & ~31) / 8) * bi.biHeight;
	}

	dwLen += bi.biSizeImage;

	if(handle = GlobalReAlloc(hDIB, dwLen, GMEM_MOVEABLE))
		hDIB = handle;

	lpbi = (LPBITMAPINFOHEADER)hDIB;
	GetDIBits(pDC->GetSafeHdc(),
		HBITMAP(bmp),
		0,
		(DWORD)bi.biHeight,
		(LPBYTE)lpbi + (bi.biSize + nColors * sizeof(RGBQUAD)),
		(LPBITMAPINFO)lpbi,
		(DWORD)DIB_RGB_COLORS);

	BITMAPFILEHEADER hdr;
	hdr.bfType = ((WORD)('M' << 8) | 'B');
	hdr.bfSize = (DWORD)(GlobalSize(hDIB) + sizeof(hdr));
	hdr.bfReserved1 = 0;
	hdr.bfReserved2 = 0;
	hdr.bfOffBits = (DWORD)(sizeof(hdr) + lpbi->biSize + nColors * sizeof(RGBQUAD));

	char* pBmpBuf;
	DWORD FileSize;
	FileSize = (DWORD)(sizeof(hdr) + GlobalSize(hDIB));
	pBmpBuf = new char[FileSize];
	memcpy(pBmpBuf, &hdr, sizeof(hdr));
	memcpy(pBmpBuf + sizeof(hdr), lpbi, GlobalSize(hDIB));

	CFile file;
	file.Open(strFilePath, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
	file.Write(pBmpBuf, FileSize);
	file.Close();

	delete[] pBmpBuf;

	if(hDIB){
		GlobalFree(hDIB);
	}

	SelectPalette(pDC->GetSafeHdc(), hPal, FALSE);
	
}


void CDrawPadDlg::intserArray(int drawType, int penSize, int figureLine, COLORREF penColor, COLORREF brushColor)
{
	selectDrawArray.Add(drawType);
	pensizeArray.Add(penSize);
	lineoff.Add(figureLine);
	pencolorArray.Add(penColor);
	brushcolorArray.Add(brushColor);	
}

void CDrawPadDlg::OnBnClickedNew()
{
	// TODO: Add your control notification handler code here
	CClientDC dc(this);
		

	bitmap.LoadBitmap(IDB_BITMAP35);
	HBITMAP hBmp = (HBITMAP)bitmap;

	drawing.SetBitmap(hBmp);
	CDrawPadDlg::OnSize(SIZE_RESTORED, m_cx, m_cy);

	bitmap.DeleteObject();

	selectDrawArray.RemoveAll();
	pensizeArray.RemoveAll();
	element.RemoveAll();
	lineoff.RemoveAll();
	startPoint.RemoveAll();
	endPoint.RemoveAll();
	pencolorArray.RemoveAll();
	brushcolorArray.RemoveAll();

	for(int i = 0; i < 255; i++){
		for(int j = 0; j < 255; j++){
			polygon[i][j] = (0,0);
		}
	}
	polygonCount = 0;
	polyPoint = 0;
	*polyPointCount = 0;
	
	elementcount = 0;
	Invalidate(TRUE);
}

void CDrawPadDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	m_cx = cx;
	m_cy = cy;
	drawPicCtrl.SetRect(100,10, cx-10,cy-10);
	CStatic *m_draw = (CStatic*)GetDlgItem(IDC_DRAWING);
	
	if(m_draw->GetSafeHwnd())
	{
		m_draw->MoveWindow(drawPicCtrl);

	}
	// TODO: Add your message handler code here
}
