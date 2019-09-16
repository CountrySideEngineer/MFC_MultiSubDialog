#pragma once
#include "CPerson.h"
#include "CPersonInfo.h"

// CMFCAppInputDlg ダイアログ

class CMFCAppInputDlg : public CDialog
{
	DECLARE_DYNAMIC(CMFCAppInputDlg)

public:
	CMFCAppInputDlg(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CMFCAppInputDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION_INPUT_DIALOG };
#endif
public:
	void SetPersonInfo(const CPersonInfo& SrcData);
	const CPersonInfo& GetPersonInfo() const { return this->m_PersonInfo; }

protected:
	//CArray<CPerson*>	m_PersonDataMaster;
	CPersonInfo m_PersonInfo;	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	virtual	BOOL OnInitDialog();

	virtual void OnListDataUpdate();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAddNewData();
	afx_msg void OnLbnSelchangeListItem();
	afx_msg void OnBnClickedButtonAddRelation();
	afx_msg void OnBnClickedUpdateChange();
};
