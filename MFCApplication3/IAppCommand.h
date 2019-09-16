#pragma once
class IAppCommand
{
public:
	IAppCommand(VOID* CommandArg = NULL, VOID* Factory = NULL);

public:
	virtual	void	Execute(VOID* ExecuteArgument = NULL) = 0;

protected:
	VOID* m_CommandArg;
	VOID* m_Factory;
};

