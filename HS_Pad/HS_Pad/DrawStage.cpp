// DrawStage.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HS_Pad.h"
#include "DrawStage.h"


// CDrawStage

IMPLEMENT_DYNAMIC(CDrawStage, CStatic)

CDrawStage::CDrawStage()
{

}

CDrawStage::~CDrawStage()
{
}


BEGIN_MESSAGE_MAP(CDrawStage, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CDrawStage �޽��� ó�����Դϴ�.



void CDrawStage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	dc.LineTo(100, 100);
	dc.MoveTo(200,200);

}
