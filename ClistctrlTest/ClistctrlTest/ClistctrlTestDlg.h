
// ClistctrlTestDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CClistctrlTestDlg 对话框
class CClistctrlTestDlg : public CDialogEx
{
// 构造
public:
	CClistctrlTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CLISTCTRLTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()



public:
	void InitList(void);
	CListCtrl m_listctl;

	afx_msg void OnNMRClickList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void On32771();
	afx_msg void OnBnClickedButtonInput();
	CButton m_input;
	CButton m_output;
	afx_msg void OnBnClickedButtonOutput();
};
