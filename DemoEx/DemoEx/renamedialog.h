#pragma once


// renamedialog �Ի���

class renamedialog : public CDialogEx
{
	DECLARE_DYNAMIC(renamedialog)

public:
	renamedialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~renamedialog();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_e1;
	CEdit m_e2;
	PVOID para,para2,para3;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
