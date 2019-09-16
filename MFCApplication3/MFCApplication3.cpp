
// MFCApplication3.cpp : アプリケーションのクラス動作を定義します。
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "CMFCAppInputDlg.h"
#include "CPerson.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3App

BEGIN_MESSAGE_MAP(CMFCApplication3App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMFCApplication3App の構築

CMFCApplication3App::CMFCApplication3App()
{
	// 再起動マネージャーをサポートします
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}


// 唯一の CMFCApplication3App オブジェクト

CMFCApplication3App theApp;


// CMFCApplication3App の初期化

BOOL CMFCApplication3App::InitInstance()
{
	// アプリケーション マニフェストが visual スタイルを有効にするために、
	// ComCtl32.dll Version 6 以降の使用を指定する場合は、
	// Windows XP に InitCommonControlsEx() が必要です。さもなければ、ウィンドウ作成はすべて失敗します。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// アプリケーションで使用するすべてのコモン コントロール クラスを含めるには、
	// これを設定します。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ダイアログにシェル ツリー ビューまたはシェル リスト ビュー コントロールが
	// 含まれている場合にシェル マネージャーを作成します。
	CShellManager *pShellManager = new CShellManager;

	// MFC コントロールでテーマを有効にするために、"Windows ネイティブ" のビジュアル マネージャーをアクティブ化
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 標準初期化
	// これらの機能を使わずに最終的な実行可能ファイルの
	// サイズを縮小したい場合は、以下から不要な初期化
	// ルーチンを削除してください。
	// 設定が格納されているレジストリ キーを変更します。
	// TODO: 会社名または組織名などの適切な文字列に
	// この文字列を変更してください。
	SetRegistryKey(_T("アプリケーション ウィザードで生成されたローカル アプリケーション"));

	CMFCAppInputDlg dlg;
	m_pMainWnd = &dlg;

	CPerson YamadaSun(CString(_T("山田")), CString(_T("息子")), 10, CPerson::PERSON_SEX_TYPE_MALE);
	YamadaSun.AddRelations(CPerson(CString(_T("山田")), CString(_T("父")), 35, CPerson::PERSON_SEX_TYPE_MALE));
	YamadaSun.AddRelations(CPerson(CString(_T("山田")), CString(_T("母")), 35, CPerson::PERSON_SEX_TYPE_FEMALE));
	YamadaSun.AddRelations(CPerson(CString(_T("山田")), CString(_T("祖父")), 60, CPerson::PERSON_SEX_TYPE_MALE));
	YamadaSun.AddRelations(CPerson(CString(_T("山田")), CString(_T("祖母")), 60, CPerson::PERSON_SEX_TYPE_FEMALE));
	YamadaSun.AddRelations(CPerson(CString(_T("山田")), CString(_T("弟")), 7, CPerson::PERSON_SEX_TYPE_MALE));
	CPerson SuzukiSun(CString(_T("鈴木")), CString(_T("息子")), 7, CPerson::PERSON_SEX_TYPE_MALE);
	SuzukiSun.AddRelations(CPerson(CString(_T("鈴木")), CString(_T("父")), 39, CPerson::PERSON_SEX_TYPE_MALE));
	SuzukiSun.AddRelations(CPerson(CString(_T("鈴木")), CString(_T("母")), 38, CPerson::PERSON_SEX_TYPE_FEMALE));
	SuzukiSun.AddRelations(CPerson(CString(_T("鈴木")), CString(_T("祖父")), 70, CPerson::PERSON_SEX_TYPE_MALE));
	SuzukiSun.AddRelations(CPerson(CString(_T("鈴木")), CString(_T("祖母")), 64, CPerson::PERSON_SEX_TYPE_FEMALE));
	SuzukiSun.AddRelations(CPerson(CString(_T("鈴木")), CString(_T("妹")), 6, CPerson::PERSON_SEX_TYPE_FEMALE));
	CPerson TankaDaughter(CString(_T("鈴木")), CString(_T("娘")), 15, CPerson::PERSON_SEX_TYPE_FEMALE);
	TankaDaughter.AddRelations(CPerson(CString(_T("鈴木")), CString(_T("父")), 45, CPerson::PERSON_SEX_TYPE_MALE));
	TankaDaughter.AddRelations(CPerson(CString(_T("鈴木")), CString(_T("母")), 42, CPerson::PERSON_SEX_TYPE_FEMALE));
	TankaDaughter.AddRelations(CPerson(CString(_T("鈴木")), CString(_T("祖母")), 64, CPerson::PERSON_SEX_TYPE_FEMALE));
	TankaDaughter.AddRelations(CPerson(CString(_T("鈴木")), CString(_T("妹")), 12, CPerson::PERSON_SEX_TYPE_FEMALE));

	CPersonInfo PersonInfo;
	PersonInfo.Add(0, new CPerson(&YamadaSun));
	PersonInfo.Add(1, new CPerson(&SuzukiSun));
	PersonInfo.Add(2, new CPerson(&TankaDaughter));

	dlg.SetPersonInfo(PersonInfo);
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ダイアログが <キャンセル> で消された時のコードを
		//  記述してください。
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "警告: ダイアログの作成に失敗しました。アプリケーションは予期せずに終了します。\n");
		TRACE(traceAppMsg, 0, "警告: ダイアログで MFC コントロールを使用している場合、#define _AFX_NO_MFC_CONTROLS_IN_DIALOGS を指定できません。\n");
	}

	// 上で作成されたシェル マネージャーを削除します。
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// ダイアログは閉じられました。アプリケーションのメッセージ ポンプを開始しないで
	//  アプリケーションを終了するために FALSE を返してください。
	return FALSE;
}

