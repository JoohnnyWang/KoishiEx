#pragma once


// CDlgExpand �Ի���

class CDlgExpand : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgExpand)

public:
	CDlgExpand(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgExpand();

// �Ի�������
	enum { IDD = IDD_EXPAND_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_a1;
	CEdit m_a2;
	CEdit m_a3;
	CEdit m_a4;
	CEdit m_a5;
	CEdit m_a6;
	CEdit m_b1;
	CEdit m_b2;
	CEdit m_b3;
	CEdit m_b4;
	CEdit m_b5;
	CEdit m_b6;
	CEdit m_c1;
	CEdit m_c2;
	CEdit m_c3;
	CEdit m_c4;
	CStatic m_s1;
	CStatic m_s2;
	CStatic m_s3;
	CStatic m_s4;
	CComboBox m_cb;
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
