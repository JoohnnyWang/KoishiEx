#pragma once


// CScanDialog �Ի���

class CScanDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CScanDialog)

public:
	CScanDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CScanDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_e1;
	CEdit m_e2;
	CSpinButtonCtrl m_sp1;
	CSpinButtonCtrl m_sp2;
	CComboBox m_c1;

public:
	PVOID para;
	CButton m_ch1;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheck1();
};
