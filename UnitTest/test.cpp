#include "pch.h"
#include "gtest/gtest.h"
#include "CSection.h"
#include "CDepartment.h"

TEST(CDepartment, CreateCopy_001) {
	CDepartment Department(
		CString(_T("������")),
		CString(_T("�����̐���")),
		CString(_T("�{�X�̖��O")),
		CString(_T("�����̎d���̐���")));
	CDepartment SubDepartment1(
		CString(_T("�ۖ�1")),
		CString(_T("�ۂ̐���1")),
		CString(_T("�ے��̖��O1")),
		CString(_T("�ۂ̎d���̐���1")));
	CDepartment SubDepartment2(
		CString(_T("�ۖ�2")),
		CString(_T("�ۂ̐���2")),
		CString(_T("�ے��̖��O2")),
		CString(_T("�ۂ̎d���̐���2")));
	CSection Member1(
		CString(_T("�ۈ�1")),
		CString(_T("�ۈ�����1")));
	CSection Member2(
		CString(_T("�ۈ�2")),
		CString(_T("�ۈ�����2")));
	CSection Member3(
		CString(_T("�ۈ�3")),
		CString(_T("�ۈ�����3")));
	CSection Member4(
		CString(_T("�ۈ�4")),
		CString(_T("�ۈ�����4")));
	SubDepartment1.AddDetail(&Member1);
	SubDepartment1.AddDetail(&Member2);
	SubDepartment1.AddDetail(&Member3);
	SubDepartment2.AddDetail(&Member4);
	Department.AddDetail(&SubDepartment1);
	Department.AddDetail(&SubDepartment2);

	CDepartment NewDepartment((CDepartment*)&Department);

	ASSERT_EQ(NewDepartment.GetNumOfMember(), 2);
	ASSERT_STREQ(NewDepartment.GetName(), CString(_T("������")));
	ASSERT_STREQ(NewDepartment.GetExplain(), CString(_T("�����̐���")));
	ASSERT_STREQ(NewDepartment.GetManager(), CString(_T("�{�X�̖��O")));
	ASSERT_STREQ(NewDepartment.GetBussDesc(), CString(_T("�����̎d���̐���")));

	CArray<CSection*>& DetailInfo = NewDepartment.GetDetail();
	CSection* DetailInfoItem = DetailInfo.GetAt(0);
	CDepartment* DepartmentDetailInfoItem = dynamic_cast<CDepartment*>(DetailInfoItem);
	ASSERT_EQ(DepartmentDetailInfoItem->GetName(), CString(_T("�ۖ�1")));
	ASSERT_EQ(DepartmentDetailInfoItem->GetExplain(), CString(_T("�ۂ̐���1")));
	ASSERT_EQ(DepartmentDetailInfoItem->GetManager(), CString(_T("�ے��̖��O1")));
	ASSERT_EQ(DepartmentDetailInfoItem->GetBussDesc(), CString(_T("�ۂ̎d���̐���1")));
	ASSERT_NE(DetailInfoItem, &SubDepartment1);

	_tprintf(_T("DetailInfoItem = 0x%08p\r\n"), (VOID*)DetailInfoItem);
	_tprintf(_T("SubDepartment1 = 0x%08p\r\n"), (VOID*)(&SubDepartment1));
}


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}