#pragma once


// CDlgInsert �Ի���

class CDlgInsert : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgInsert)

public:
	CDlgInsert(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgInsert();

// �Ի�������
	enum { IDD = IDD_INSERT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CButton m_btn1;
	CButton m_ch1;
	CButton m_ch2;
	CButton m_ch3;
	CButton m_ch4;
	CButton m_ch5;
	CButton m_ch6;
	CComboBox m_cb1;
	CEdit m_ed1;
	CEdit m_ed2;
	CEdit m_ed3;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
