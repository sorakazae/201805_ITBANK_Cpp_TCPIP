// MFC_CLT.h : main header file for the MFC_CLT application
//

#if !defined(AFX_MFC_CLT_H__F1390B47_4F05_4546_8B9F_08CBAF12DD8F__INCLUDED_)
#define AFX_MFC_CLT_H__F1390B47_4F05_4546_8B9F_08CBAF12DD8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_CLTApp:
// See MFC_CLT.cpp for the implementation of this class
//

class CMFC_CLTApp : public CWinApp
{
public:
	CMFC_CLTApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_CLTApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_CLTApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_CLT_H__F1390B47_4F05_4546_8B9F_08CBAF12DD8F__INCLUDED_)
