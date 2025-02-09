// MFC_SRVDlg.h : header file
//

#if !defined(AFX_MFC_SRVDLG_H__6CFB752B_26E8_41A0_AC1C_383C6B3D923B__INCLUDED_)
#define AFX_MFC_SRVDLG_H__6CFB752B_26E8_41A0_AC1C_383C6B3D923B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_SRVDlg dialog

class CMFC_SRVDlg : public CDialog
{
// Construction
public:
	CMFC_SRVDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_SRVDlg)
	enum { IDD = IDD_MFC_SRV_DIALOG };
	CListBox	m_LISTBOX;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_SRVDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_SRVDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SRVDLG_H__6CFB752B_26E8_41A0_AC1C_383C6B3D923B__INCLUDED_)
