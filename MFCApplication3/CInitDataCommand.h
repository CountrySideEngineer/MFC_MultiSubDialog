#pragma once
#include "IAppCommand.h"

class CInitDataCommand :
	public IAppCommand
{
public:
	CInitDataCommand(VOID* CommandArg = NULL);
	virtual ~CInitDataCommand() {}

public:
	virtual VOID	Execute(VOID* ExecuteArg = NULL) {}
};

