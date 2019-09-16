#pragma once
#include "IAppCommand.h"

class CEditDataCommand :
	public IAppCommand
{
public:
	CEditDataCommand(VOID* CommandData = NULL);
	virtual ~CEditDataCommand() {}

	virtual VOID	Execute(VOID* ExecuteArg = NULL);
};

