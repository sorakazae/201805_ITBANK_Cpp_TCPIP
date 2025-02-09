// MFC_SRV.h : main header file for the MFC_SRV application
//

#if !defined(AFX_MFC_SRV_H__35E32CA9_E0D6_4EA5_8C44_834D95E056C5__INCLUDED_)
#define AFX_MFC_SRV_H__35E32CA9_E0D6_4EA5_8C44_834D95E056C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_SRVApp:
// See MFC_SRV.cpp for the implementation of this class
//

class CMFC_SRVApp : public CWinApp
{
public:
	CMFC_SRVApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_SRVApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_SRVApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SRV_H__35E32CA9_E0D6_4EA5_8C44_834D95E056C5__INCLUDED_)
