// aaaDlg.h : header file
//

#if !defined(AFX_AAADLG_H__325A20E3_F7F5_45F9_BA0C_7926635EFA09__INCLUDED_)
#define AFX_AAADLG_H__325A20E3_F7F5_45F9_BA0C_7926635EFA09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAaaDlg dialog

class CAaaDlg : public CDialog
{
// Construction
public:
	CAaaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAaaDlg)
	enum { IDD = IDD_AAA_DIALOG };
	CListBox	m_LIST_BOX;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAaaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAaaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AAADLG_H__325A20E3_F7F5_45F9_BA0C_7926635EFA09__INCLUDED_)
