#pragma once
#include "GoodListCtrl.h"

// CDlgMix �Ի���

class CDlgMix : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMix)

public:
	CDlgMix(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgMix();

// �Ի�������
	enum { IDD = IDD_MIX_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit m_e1;
	CGoodListCtrl m_l1;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
