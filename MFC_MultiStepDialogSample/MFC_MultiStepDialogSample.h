
// MFC_MultiStepDialogSample.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CMFCMultiStepDialogSampleApp:
// このクラスの実装については、MFC_MultiStepDialogSample.cpp を参照してください
//

class CMFCMultiStepDialogSampleApp : public CWinApp
{
public:
	CMFCMultiStepDialogSampleApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMFCMultiStepDialogSampleApp theApp;
