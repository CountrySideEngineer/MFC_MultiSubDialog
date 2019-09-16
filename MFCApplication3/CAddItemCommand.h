#pragma once
#include "IAppCommand.h"
class CAddItemCommand :
	public IAppCommand
{
public:
	CAddItemCommand(VOID* CommandArg = NULL, VOID* Factory = NULL);
	virtual ~CAddItemCommand() {}

public:
	virtual VOID	Execute(VOID* ExecuteArg = NULL);


};
