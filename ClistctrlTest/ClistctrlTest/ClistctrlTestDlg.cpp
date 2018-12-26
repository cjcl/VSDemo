
// ClistctrlTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ClistctrlTest.h"
#include "ClistctrlTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_LIST, m_listctr);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CClistctrlTestDlg 对话框



CClistctrlTestDlg::CClistctrlTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClistctrlTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClistctrlTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_listctl);
	DDX_Control(pDX, IDC_BUTTON_INPUT, m_input);
	DDX_Control(pDX, IDC_BUTTON_OUTPUT, m_output);
}

BEGIN_MESSAGE_MAP(CClistctrlTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CONTEXTMENU()
	ON_NOTIFY(NM_RCLICK, IDC_LIST, &CClistctrlTestDlg::OnNMRClickList)
	ON_COMMAND(ID_32771, &CClistctrlTestDlg::On32771)
	ON_BN_CLICKED(IDC_BUTTON_INPUT, &CClistctrlTestDlg::OnBnClickedButtonInput)
	ON_BN_CLICKED(IDC_BUTTON_OUTPUT, &CClistctrlTestDlg::OnBnClickedButtonOutput)
END_MESSAGE_MAP()


// CClistctrlTestDlg 消息处理程序

BOOL CClistctrlTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	InitList();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CClistctrlTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CClistctrlTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CClistctrlTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CClistctrlTestDlg::InitList(void)
{
	DWORD dwStyle = m_listctl.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_listctl.SetExtendedStyle(dwStyle);

	m_listctl.InsertColumn(0, _T(" "), LVCFMT_LEFT, 25);
	m_listctl.InsertColumn(1, _T("单词"), LVCFMT_LEFT, 60);
	m_listctl.InsertColumn(2, _T("二元序列"), LVCFMT_LEFT, 80);
	m_listctl.InsertColumn(3, _T("类型"), LVCFMT_LEFT, 80);
	m_listctl.InsertColumn(4, _T("位置（行,列）"), LVCFMT_LEFT, 100);
	for (int i = 0; i < 10; i++)
	{
		m_listctl.InsertItem(i, _T("Java"));
		m_listctl.SetItemText(i, 1, _T("1"));
		m_listctl.SetItemText(i, 2, _T("1"));
		m_listctl.SetItemText(i, 3, _T("1"));
		m_listctl.SetItemText(i, 4, _T("1"));
	}


}




void CClistctrlTestDlg::OnNMRClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	if (pNMItemActivate->iItem != -1)
	{
		DWORD dwPos = GetMessagePos();
		CPoint point(LOWORD(dwPos), HIWORD(dwPos));

		CMenu menu;
		VERIFY(menu.LoadMenu(IDR_MENU));

		CMenu* popup = menu.GetSubMenu(0);
		ASSERT(popup != NULL);
		popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
	*pResult = 0;
}




void CClistctrlTestDlg::On32771()
{
	// TODO:  在此添加命令处理程序代码

	int i, iState;
	CString str1;
	LPTSTR str2;
	str2 = NULL;
	int nItemSelected = m_listctl.GetSelectedCount();
	int nItemCount = m_listctl.GetItemCount();
	if (nItemSelected<1)
		return;
	for (i = nItemCount - 1; i >= 0; i--)
	{
		iState = m_listctl.GetItemState(i, LVIS_SELECTED);
		if (iState != 0)
		{
			str1 = m_listctl.GetItemText(i, 1);
			m_listctl.GetItemText(i,1,str2, 10);
			m_listctl.DeleteItem(i);

		}
	}
}


void CClistctrlTestDlg::OnBnClickedButtonInput()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CClistctrlTestDlg::OnBnClickedButtonOutput()
{
	// TODO:  在此添加控件通知处理程序代码
}
