#include "pch.h"
#include "CEditDataCommand.h"
#include "CMFCAppInputDlg.h"

CEditDataCommand::CEditDataCommand(VOID* CommandData)
	: IAppCommand(CommandData)
{
}

VOID CEditDataCommand::Execute(VOID* ExecuteArg)
{
	CMFCAppInputDlg* InputDlg = (CMFCAppInputDlg*)(ExecuteArg);

	INT_PTR InputOkCancel = InputDlg->DoModal();
	if (IDOK == InputOkCancel) {

	}
	else {

	}
}
