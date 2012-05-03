// Hs_PadView.cpp : CHs_PadView Ŭ������ ����
//

#include "stdafx.h"
#include "Hs_Pad.h"

#include "Hs_PadDoc.h"
#include "Hs_PadView.h"
#include "TextPadDlg.h"
#include "UrlSearchDlg.h"
#include "DrawPadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHs_PadView

IMPLEMENT_DYNCREATE(CHs_PadView, CView)

BEGIN_MESSAGE_MAP(CHs_PadView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_URL, &CHs_PadView::OnUrl)
	ON_COMMAND(ID_TEXTPAD, &CHs_PadView::OnTextpad)
	ON_COMMAND(ID_DRAWPAD, &CHs_PadView::OnDrawpad)
END_MESSAGE_MAP()

// CHs_PadView ����/�Ҹ�

CHs_PadView::CHs_PadView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	UrlSearchDlg = NULL;
	TextPadDlg = NULL;
	DrawPadDlg = NULL;
}

CHs_PadView::~CHs_PadView()
{
}

BOOL CHs_PadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CHs_PadView �׸���

void CHs_PadView::OnDraw(CDC* /*pDC*/)
{
	CHs_PadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CHs_PadView �μ�

BOOL CHs_PadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CHs_PadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CHs_PadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CHs_PadView ����

#ifdef _DEBUG
void CHs_PadView::AssertValid() const
{
	CView::AssertValid();
}

void CHs_PadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHs_PadDoc* CHs_PadView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHs_PadDoc)));
	return (CHs_PadDoc*)m_pDocument;
}
#endif //_DEBUG


// CHs_PadView �޽��� ó����

void CHs_PadView::OnUrl()
{
	// TODO: Add your command handler code here
	UrlSearchDlg = new CUrlSearchDlg();
	UrlSearchDlg->m_pView = this;
	UrlSearchDlg->Create(IDD_URLSEARCHDLG);
	UrlSearchDlg->ShowWindow(SW_SHOW);
	
}

void CHs_PadView::OnTextpad()
{
	// TODO: Add your command handler code here
	TextPadDlg = new CTextPadDlg();
	TextPadDlg->m_pView = this;
	TextPadDlg->Create(IDD_TEXTPADDLG);
	TextPadDlg->ShowWindow(SW_SHOW);
}

void CHs_PadView::OnDrawpad()
{
	// TODO: Add your command handler code here
	DrawPadDlg = new CDrawPadDlg();
	DrawPadDlg->m_pView = this;
	DrawPadDlg->Create(IDD_DRAWPADDLG);
	DrawPadDlg->ShowWindow(SW_SHOW);
}
