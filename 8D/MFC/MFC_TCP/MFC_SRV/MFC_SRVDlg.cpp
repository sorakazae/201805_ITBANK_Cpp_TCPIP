// MFC_SRVDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_SRV.h"
#include "MFC_SRVDlg.h"

#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <stdio.h>

UINT func(LPVOID arg);
UINT accept_func(LPVOID arg);

SOCKET totSock[256];
int sockCnt=0;
SOCKADDR_IN CLTaddr;
SOCKET CLTS;
SOCKET s;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CMFC_SRVDlg dialog

CMFC_SRVDlg::CMFC_SRVDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_SRVDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_SRVDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_SRVDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_SRVDlg)
	DDX_Control(pDX, IDC_LIST1, m_LISTBOX);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_SRVDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_SRVDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_SRVDlg message handlers

BOOL CMFC_SRVDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_SRVDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_SRVDlg::OnPaint() 
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
HCURSOR CMFC_SRVDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFC_SRVDlg::OnOK() 
{
	// TODO: Add extra validation here
	WSADATA wsa;
	
	/* 윈속 dll 로드*/ 
	WSAStartup( MAKEWORD(2,2) ,&wsa);
	
	/* 소켓 생성*/
	s = socket(AF_INET, SOCK_STREAM,0);
	if(s == INVALID_SOCKET){
		MessageBox("SOCKET","ERROR_MSG",MB_OK);
		return ;
	}
	
	struct hostent * hp;
	char host[1024];
	
	gethostname(host,sizeof(host));
	hp = gethostbyname(host);
	char ip_[100];

	sprintf(ip_,"%s",inet_ntoa(*(struct in_addr*)hp->h_addr_list[0]));
	/*주소 결합*/
	SOCKADDR_IN SRVaddr;
	memset(&SRVaddr, 0, sizeof(SRVaddr));
	
	SRVaddr.sin_family = AF_INET;
	SRVaddr.sin_port = htons(12345);
	SRVaddr.sin_addr.s_addr = inet_addr(ip_);
	
	int errch = 0;
	errch = bind(s, (SOCKADDR*)&SRVaddr, sizeof(SRVaddr));
	if(errch == SOCKET_ERROR){
		MessageBox("BIND","ERROR_MSG",MB_OK);
		return ;
	}
	
	/*포트 오픈*/
	errch = listen(s,SOMAXCONN);
	if(errch == SOCKET_ERROR){
		MessageBox("LISTEN","ERROR_MSG",MB_OK);
		return ;
	}
	
	/*연결 허용*/
	AfxBeginThread(accept_func,this);
	
	
	/*소켓 종료 및 dll 언로드*/
	
//	CDialog::OnOK();
}
UINT accept_func(LPVOID arg){

	time_t tm;
	struct tm * lt;
	char time_ch[512];

	memset(time_ch,0, sizeof(time_ch));

	CMFC_SRVDlg *th = (CMFC_SRVDlg*)arg;
	int size = sizeof(CLTaddr);

	while(1){
		CLTS = accept(s, (SOCKADDR * )&CLTaddr, &size);
		if(CLTS == INVALID_SOCKET){
			th->MessageBox("ACCEPT","ERROR_MSG",MB_OK);
			return 0;
		}
		time(&tm);
		lt= localtime(&tm);
		
		sprintf(time_ch,"%d년 %d월 %d일 %d시 %d분 %s 접속하였습니다.",
			lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday,lt->tm_hour, lt->tm_min,inet_ntoa(CLTaddr.sin_addr));
		
		th->m_LISTBOX.AddString(time_ch);
		th->m_LISTBOX.SetCurSel(th->m_LISTBOX.GetCount()-1);
		totSock[sockCnt++] = CLTS;
	
		AfxBeginThread(func,th);
		memset(time_ch,0, sizeof(time_ch));
	}
}
UINT func(LPVOID arg)
{
	CMFC_SRVDlg *th = (CMFC_SRVDlg*)arg;
	int recvlen = 0, i;
	char recvbuf[1460]={0};
	memset(recvbuf,0,sizeof(recvbuf));
	
	SOCKET clt_s = CLTS;

	char str[512]={0};

	while(1){
		recvlen = recv(clt_s, recvbuf, sizeof(recvbuf),0);
	
		if(recvbuf[0] != NULL){
			sprintf(str,"%s : %s",inet_ntoa(CLTaddr.sin_addr),recvbuf);
			
			th->m_LISTBOX.AddString(str);
			th->m_LISTBOX.SetCurSel(th->m_LISTBOX.GetCount()-1);
			
			for(i=0; i<sockCnt; i++)
				send(totSock[i], str, strlen(str),0);
			
			memset(recvbuf,0,sizeof(recvbuf));
			memset(str,0,sizeof(str));
		}
	}
	
	return 0;
}

void CMFC_SRVDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	closesocket(CLTS);
	closesocket(s);
	WSACleanup();
	CDialog::OnCancel();
}
