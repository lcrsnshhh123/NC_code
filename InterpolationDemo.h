
// InterpolationDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CInterpolationDemoApp:
// �йش����ʵ�֣������ InterpolationDemo.cpp
//

class CInterpolationDemoApp : public CWinApp
{
public:
	CInterpolationDemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CInterpolationDemoApp theApp;