// Hs_Pad.h : Hs_Pad ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CHs_PadApp:
// �� Ŭ������ ������ ���ؼ��� Hs_Pad.cpp�� �����Ͻʽÿ�.
//

class CHs_PadApp : public CWinApp
{
public:
	CHs_PadApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHs_PadApp theApp;