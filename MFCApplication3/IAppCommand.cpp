#include "pch.h"
#include "IAppCommand.h"

IAppCommand::IAppCommand(VOID* CommandArg, VOID* Factory)
	: m_CommandArg(CommandArg)
	, m_Factory(Factory)
{}