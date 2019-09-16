
// MFCApplication3.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CMFCApplication3App:
// このクラスの実装については、MFCApplication3.cpp を参照してください
//

class CMFCApplication3App : public CWinApp
{
public:
	CMFCApplication3App();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication3App theApp;
