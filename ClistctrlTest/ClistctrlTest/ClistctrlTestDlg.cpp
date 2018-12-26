
// ClistctrlTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ClistctrlTest.h"
#include "ClistctrlTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CClistctrlTestDlg �Ի���



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


// CClistctrlTestDlg ��Ϣ�������

BOOL CClistctrlTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	InitList();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CClistctrlTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	m_listctl.InsertColumn(1, _T("����"), LVCFMT_LEFT, 60);
	m_listctl.InsertColumn(2, _T("��Ԫ����"), LVCFMT_LEFT, 80);
	m_listctl.InsertColumn(3, _T("����"), LVCFMT_LEFT, 80);
	m_listctl.InsertColumn(4, _T("λ�ã���,�У�"), LVCFMT_LEFT, 100);
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���������������

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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CClistctrlTestDlg::OnBnClickedButtonOutput()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
