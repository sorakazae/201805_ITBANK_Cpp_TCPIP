// MFC_CLTDlg.h : header file
//

#if !defined(AFX_MFC_CLTDLG_H__365CA382_4137_4F79_BE56_D28629BB4FCC__INCLUDED_)
#define AFX_MFC_CLTDLG_H__365CA382_4137_4F79_BE56_D28629BB4FCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_CLTDlg dialog

class CMFC_CLTDlg : public CDialog
{
// Construction
public:
	CMFC_CLTDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_CLTDlg)
	enum { IDD = IDD_MFC_CLT_DIALOG };
	CListBox	m_LISTBOX;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_CLTDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_CLTDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_CLTDLG_H__365CA382_4137_4F79_BE56_D28629BB4FCC__INCLUDED_)
