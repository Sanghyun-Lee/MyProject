// Hs_PadDoc.cpp : CHs_PadDoc Ŭ������ ����
//

#include "stdafx.h"
#include "Hs_Pad.h"

#include "Hs_PadDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHs_PadDoc

IMPLEMENT_DYNCREATE(CHs_PadDoc, CDocument)

BEGIN_MESSAGE_MAP(CHs_PadDoc, CDocument)
END_MESSAGE_MAP()


// CHs_PadDoc ����/�Ҹ�

CHs_PadDoc::CHs_PadDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CHs_PadDoc::~CHs_PadDoc()
{
}

BOOL CHs_PadDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CHs_PadDoc serialization

void CHs_PadDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CHs_PadDoc ����

#ifdef _DEBUG
void CHs_PadDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHs_PadDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHs_PadDoc ���
