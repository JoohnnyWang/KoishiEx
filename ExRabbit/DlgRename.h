#pragma once


// CDlgRename �Ի���

class CDlgRename : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgRename)

public:
	CDlgRename(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgRename();

// �Ի�������
	enum { IDD = IDD_RENAME_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_ed1;
	CEdit m_ed2;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
