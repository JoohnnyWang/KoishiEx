#pragma once


// CDlgSetXY �Ի���

class CDlgSetXY : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSetXY)

public:
	CDlgSetXY(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgSetXY();

// �Ի�������
	enum { IDD = IDD_SERXY_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedCancel();
	CEdit m_e1;
};
