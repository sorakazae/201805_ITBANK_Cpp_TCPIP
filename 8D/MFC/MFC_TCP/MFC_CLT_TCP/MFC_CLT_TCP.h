// MFC_CLT_TCP.h : main header file for the MFC_CLT_TCP application
//

#if !defined(AFX_MFC_CLT_TCP_H__5DE98F3E_1C22_4E14_BC3C_2BA5AD1DFE69__INCLUDED_)
#define AFX_MFC_CLT_TCP_H__5DE98F3E_1C22_4E14_BC3C_2BA5AD1DFE69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_CLT_TCPApp:
// See MFC_CLT_TCP.cpp for the implementation of this class
//

class CMFC_CLT_TCPApp : public CWinApp
{
public:
	CMFC_CLT_TCPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_CLT_TCPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_CLT_TCPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_CLT_TCP_H__5DE98F3E_1C22_4E14_BC3C_2BA5AD1DFE69__INCLUDED_)
