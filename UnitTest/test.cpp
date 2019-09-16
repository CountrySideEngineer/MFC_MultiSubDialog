#include "pch.h"
#include "gtest/gtest.h"
#include "CSection.h"
#include "CDepartment.h"

TEST(CDepartment, CreateCopy_001) {
	CDepartment Department(
		CString(_T("部署名")),
		CString(_T("部署の説明")),
		CString(_T("ボスの名前")),
		CString(_T("部署の仕事の説明")));
	CDepartment SubDepartment1(
		CString(_T("課名1")),
		CString(_T("課の説明1")),
		CString(_T("課長の名前1")),
		CString(_T("課の仕事の説明1")));
	CDepartment SubDepartment2(
		CString(_T("課名2")),
		CString(_T("課の説明2")),
		CString(_T("課長の名前2")),
		CString(_T("課の仕事の説明2")));
	CSection Member1(
		CString(_T("課員1")),
		CString(_T("課員その1")));
	CSection Member2(
		CString(_T("課員2")),
		CString(_T("課員その2")));
	CSection Member3(
		CString(_T("課員3")),
		CString(_T("課員その3")));
	CSection Member4(
		CString(_T("課員4")),
		CString(_T("課員その4")));
	SubDepartment1.AddDetail(&Member1);
	SubDepartment1.AddDetail(&Member2);
	SubDepartment1.AddDetail(&Member3);
	SubDepartment2.AddDetail(&Member4);
	Department.AddDetail(&SubDepartment1);
	Department.AddDetail(&SubDepartment2);

	CDepartment NewDepartment((CDepartment*)&Department);

	ASSERT_EQ(NewDepartment.GetNumOfMember(), 2);
	ASSERT_STREQ(NewDepartment.GetName(), CString(_T("部署名")));
	ASSERT_STREQ(NewDepartment.GetExplain(), CString(_T("部署の説明")));
	ASSERT_STREQ(NewDepartment.GetManager(), CString(_T("ボスの名前")));
	ASSERT_STREQ(NewDepartment.GetBussDesc(), CString(_T("部署の仕事の説明")));

	CArray<CSection*>& DetailInfo = NewDepartment.GetDetail();
	CSection* DetailInfoItem = DetailInfo.GetAt(0);
	CDepartment* DepartmentDetailInfoItem = dynamic_cast<CDepartment*>(DetailInfoItem);
	ASSERT_EQ(DepartmentDetailInfoItem->GetName(), CString(_T("課名1")));
	ASSERT_EQ(DepartmentDetailInfoItem->GetExplain(), CString(_T("課の説明1")));
	ASSERT_EQ(DepartmentDetailInfoItem->GetManager(), CString(_T("課長の名前1")));
	ASSERT_EQ(DepartmentDetailInfoItem->GetBussDesc(), CString(_T("課の仕事の説明1")));
	ASSERT_NE(DetailInfoItem, &SubDepartment1);

	_tprintf(_T("DetailInfoItem = 0x%08p\r\n"), (VOID*)DetailInfoItem);
	_tprintf(_T("SubDepartment1 = 0x%08p\r\n"), (VOID*)(&SubDepartment1));
}


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}