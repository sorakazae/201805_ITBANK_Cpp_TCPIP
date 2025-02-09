// MFC_CLT_TCPDlg.h : header file
//

#if !defined(AFX_MFC_CLT_TCPDLG_H__A620F971_6029_4307_B195_62CD51772B07__INCLUDED_)
#define AFX_MFC_CLT_TCPDLG_H__A620F971_6029_4307_B195_62CD51772B07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_CLT_TCPDlg dialog

class CMFC_CLT_TCPDlg : public CDialog
{
// Construction
public:
	CMFC_CLT_TCPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_CLT_TCPDlg)
	enum { IDD = IDD_MFC_CLT_TCP_DIALOG };
	CListBox	m_listbox;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_CLT_TCPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_CLT_TCPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_CLT_TCPDLG_H__A620F971_6029_4307_B195_62CD51772B07__INCLUDED_)
