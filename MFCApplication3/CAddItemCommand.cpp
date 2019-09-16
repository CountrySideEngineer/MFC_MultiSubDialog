#include "pch.h"
#include "CAddItemCommand.h"
#include "CPerson.h"

//コンストラクタ
CAddItemCommand::CAddItemCommand(VOID* CommandArg, VOID* Factory)
	: IAppCommand(CommandArg, Factory)
{}

//追加コマンドを実行します。
VOID CAddItemCommand::Execute(VOID* ExecuteArg)
{
	if (NULL == ExecuteArg) {
		AfxThrowInvalidArgException();
	}
	else {
		WORD* IndexToAdd = (WORD*)ExecuteArg;
		CArray<CPerson*>* CommandData = (CArray<CPerson*> *)(IAppCommand::m_CommandArg);
		CPerson* ConcreteFactory = (CPerson*)this->m_Factory;
		CPerson* NewItem = ConcreteFactory->CreateNewItem();
		CommandData->InsertAt(*IndexToAdd, NewItem);
	}
}