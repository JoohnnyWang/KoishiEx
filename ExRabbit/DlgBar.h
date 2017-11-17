#pragma once


// CDlgBar �Ի���

class CDlgBar : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgBar)

public:
	CDlgBar(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgBar();

// �Ի�������
	enum { IDD = IDD_BAR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_title;
	CEdit m_info;
	CProgressCtrl m_pg;

public:
	void setTitle(CString str){
		m_title.SetWindowText(str);
	}
	void setInfo(CString str){
		m_info.SetWindowText(str);
	}
	void setPosi(int i){
		m_pg.SetPos(i);
	}
	virtual BOOL OnInitDialog();
};
