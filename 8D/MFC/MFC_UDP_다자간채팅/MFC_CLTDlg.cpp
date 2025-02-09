// MFC_CLTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_CLT.h"
#include "MFC_CLTDlg.h"

#pragma comment(lib,"ws2_32.lib")
#include <winsock2.h>
#include <stdio.h>
#include <ws2tcpip.h>
#include <process.h>

UINT func(LPVOID arg);

char ip_[100];
HANDLE hThread[2];
SOCKET UDPs;
SOCKADDR_IN SRVAddr;
SOCKADDR_IN sendAddr;
SOCKADDR_IN recvAddr;
	int recvLen;

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
// CMFC_CLTDlg dialog

CMFC_CLTDlg::CMFC_CLTDlg(CWnd* pParent /*=NULL*/)
: CDialog(CMFC_CLTDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_CLTDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_CLTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_CLTDlg)
	DDX_Control(pDX, IDC_LIST1, m_LISTBOX);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_CLTDlg, CDialog)
//{{AFX_MSG_MAP(CMFC_CLTDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_CLTDlg message handlers

BOOL CMFC_CLTDlg::OnInitDialog()
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

void CMFC_CLTDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_CLTDlg::OnPaint() 
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
HCURSOR CMFC_CLTDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFC_CLTDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	/*윈속 시작*/
	WSADATA wsa;
	WSAStartup(MAKEWORD(2,2), &wsa);
	
	/*소켓 생성*/
	
	UDPs = socket(AF_INET,SOCK_DGRAM,0);
	if(UDPs == INVALID_SOCKET){
		MessageBox("SOCKET","ERROR_MSG",MB_OK);
		//printf("SOCKET ERROR!!\n");
		return ;
	}
	struct hostent * hp;
	char host[1024];
	
	gethostname(host,sizeof(host));
	hp = gethostbyname(host);
	
	//	printf("hp->h_addr_list[0] = %s\n",inet_ntoa(*(struct in_addr*)hp->h_addr_list[0]));
	sprintf(ip_,"%s",inet_ntoa(*(struct in_addr*)hp->h_addr_list[0]));
	MessageBox(ip_,"HOST_IP_ADDR",MB_OK);
	/*서버 주소 구조체*/
	
	SRVAddr.sin_family = AF_INET;
	SRVAddr.sin_port = htons(22222);
	SRVAddr.sin_addr.s_addr = inet_addr(ip_);
	
	
	/*주소 결합*/
	int error=0;
	error=bind(UDPs,(sockaddr *)(&SRVAddr),sizeof(SRVAddr));
	if(error == SOCKET_ERROR){
		MessageBox("BIND","ERROR_MSG",MB_OK);
		//printf("BIND ERROR!!\n");
		return ;
	}
	/*멀티캐스트 TTL*/
	int ttl = 128;
	setsockopt(UDPs,IPPROTO_IP,IP_MULTICAST_TTL,(char*)ttl,sizeof(ttl));
	
	
	/*통신할 대상의 주소 구조체*/
	
	sendAddr.sin_addr.s_addr = inet_addr("233.3.3.3");
	sendAddr.sin_port = htons(22222);
	sendAddr.sin_family = AF_INET;

	struct ip_mreq mt;
	mt.imr_interface.s_addr = inet_addr(ip_);
	mt.imr_multiaddr.s_addr = inet_addr("233.3.3.3");
	
	
	setsockopt(UDPs,IPPROTO_IP,IP_ADD_MEMBERSHIP,(char*)&mt,sizeof(mt));
	
	/*통신 대상의 주소 구조체*/
	
	recvLen = sizeof(recvAddr);
	AfxBeginThread(func,this);
}
UINT func(LPVOID arg){
	CMFC_CLTDlg * th = (CMFC_CLTDlg*)arg;
	char str[512]={0};
	char recvBuf[512];

	memset(recvBuf,0,sizeof(recvBuf));
	int error=0;
	while(1){
		memset(str,0,sizeof(str));
		error=recvfrom(UDPs,recvBuf,sizeof(recvBuf),0,(sockaddr*)(&recvAddr),&recvLen);
		if(error == SOCKET_ERROR){
			th->MessageBox("RECVFROM","ERROR_MSG",MB_OK);
		//	printf("RECVFROM ERROR!!\n");
			return -1;
		}
		strcat(str,inet_ntoa(recvAddr.sin_addr));
		strcat(str," : ");
		strcat(str,recvBuf);
		th->m_LISTBOX.AddString(str);
		th->m_LISTBOX.SetCurSel(th->m_LISTBOX.GetCount()-1);
		//printf("[UDP %s:%d]\n", inet_ntoa(recvAddr.sin_addr), ntohs(recvAddr.sin_port));
		//printf("[출력] > %s\n", recvBuf);
		memset(recvBuf,0,sizeof(recvBuf));
		
	}
}
void CMFC_CLTDlg::OnOK() 
{
	// TODO: Add extra validation here
	char sendBuf[512];
	memset(sendBuf,0,sizeof(sendBuf));
	int error=0;
	//	while(1)
	//	{
//	printf("[입력] > ");
//	gets(sendBuf);
	/*데이터 전송*/
	GetDlgItemText(IDC_EDIT1,sendBuf,sizeof(sendBuf));
	error=sendto(UDPs,sendBuf,sizeof(sendBuf),0,(sockaddr*)(&sendAddr),sizeof(sendAddr));
	if(error == SOCKET_ERROR){
		MessageBox("SENDTO","ERROR_MSG",MB_OK);
		//	printf("SENDTO ERROR!!\n");
		return ;
	}
	SetDlgItemText(IDC_EDIT1,"");
//	if(strcmp(sendBuf,"exit") == 0)
//	{
//		sprintf(sendBuf,"%s님이 채팅방 나감",inet_ntoa(SRVAddr.sin_addr));
//		sendto(UDPs,sendBuf,sizeof(sendBuf),0,(sockaddr*)(&sendAddr),sizeof(sendAddr));
//		closesocket(UDPs);
//		printf("프로그램 종료\n");
//		break;
//	}
	
	//	}
	//	CDialog::OnOK();
}
