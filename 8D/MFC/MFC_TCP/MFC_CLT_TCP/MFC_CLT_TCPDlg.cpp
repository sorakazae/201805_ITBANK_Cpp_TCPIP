// MFC_CLT_TCPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_CLT_TCP.h"
#include "MFC_CLT_TCPDlg.h"

#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <stdio.h>

char buf[1024];

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
UINT func(LPVOID arg);
SOCKET s;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_CLT_TCPDlg dialog

CMFC_CLT_TCPDlg::CMFC_CLT_TCPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_CLT_TCPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_CLT_TCPDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_CLT_TCPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_CLT_TCPDlg)
	DDX_Control(pDX, IDC_LIST1, m_listbox);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_CLT_TCPDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_CLT_TCPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_CLT_TCPDlg message handlers

BOOL CMFC_CLT_TCPDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetDlgItemText(IDC_EDIT2,"ip 입력하세요");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_CLT_TCPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFC_CLT_TCPDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFC_CLT_TCPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFC_CLT_TCPDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	WSADATA wsa;
	WSAStartup(MAKEWORD(2,2), &wsa);

	/*소켓 생성*/
	s = socket(AF_INET, SOCK_STREAM, 0);
	if(s == INVALID_SOCKET){
		MessageBox("SOCKET","ERROR_MSG",MB_OK);
		return ;
	}
	char ip[100]={0};
		
	//	Sleep(5000);
		GetDlgItemText(IDC_EDIT2,ip,100);

	//169.254.86.190
	
	SOCKADDR_IN SRVAddr;
	memset(&SRVAddr, 0, sizeof(SRVAddr));
	/*서버 아이피, 포트 주소 정보 입력 */
	SRVAddr.sin_addr.s_addr = inet_addr(ip);
	SRVAddr.sin_port = htons(12345);
	SRVAddr.sin_family = AF_INET;

	int errch = 0;
	errch = connect(s,(SOCKADDR *)&SRVAddr, sizeof(SRVAddr));
	if(errch == SOCKET_ERROR){
		printf("connect error!\n");
		return ;
	}
	m_listbox.AddString("======== 연결되었습니다 ========");

	AfxBeginThread(func,this);
}

void CMFC_CLT_TCPDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	/*소켓 종료*/
	closesocket(s);
	/*dll 언로드 */
	WSACleanup();
	CDialog::OnCancel();
}

void CMFC_CLT_TCPDlg::OnOK() 
{
	// TODO: Add extra validation here
	int size;
	char sendbuf[100];
	
	memset(sendbuf, 0, sizeof(sendbuf));
	
	GetDlgItemText(IDC_EDIT1,sendbuf,100);
	
	size=send(s,sendbuf,strlen(sendbuf),0);
	if(size == SOCKET_ERROR)
		MessageBox("S_E_N_D","ERROR_MSG",MB_OK);
	SetDlgItemText(IDC_EDIT1,"");
	
	
//	CDialog::OnOK();
}
UINT func(LPVOID arg){
	CMFC_CLT_TCPDlg * th = (CMFC_CLT_TCPDlg*)arg;

	char recvbuf[1460];
	memset(recvbuf,0,sizeof(recvbuf));
	int check=0;

	while(1){
		check = recv(s, recvbuf, sizeof(recvbuf),0);
		if(check == SOCKET_ERROR){
			th->MessageBox("RECV","ERROR_MSG",MB_OK);
			break;
		}
		th->m_listbox.AddString(recvbuf);
	
		th->m_listbox.SetCurSel(th->m_listbox.GetCount()-1);

		memset(recvbuf,0,sizeof(recvbuf));
	}
	return 0;
}
