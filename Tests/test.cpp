#include "pch.h"
#include "Task.h"
#include <iostream>
using namespace std;


bool isEqual(int** m1, int** m2, int cols, int rows)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (m1[i][j] != m2[i][j])
				return false;
	return true;
}

int** ConvertStaticArrayToPointers(int* in, int cols, int rows)
{
	int** result = new int* [rows];
	for (int i = 0; i < rows; i++)
		result[i] = in + (i * cols);
	return result;
}

void Destroy2DArray(int** a, int rows)
{
	if (a)
	{
		for (int i = 0; i < rows; i++)
			delete[] a[i];
		delete[] a;
	}
}

TEST(TestTask,AddNullMatrix) {
	int** res;
	EXPECT_NO_THROW(res = MatrixAddition(nullptr, nullptr,1, 1));
	EXPECT_EQ(res, nullptr);
}

TEST(TestTask, AddZeroMatrix) {
	int a[3][3]{
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
	int** res;
	EXPECT_NO_THROW(res = MatrixAddition((int**)a, (int**)a, 0, -4));
	EXPECT_EQ(res, nullptr);
}

TEST(TestTask, Add3x3Matrix) {
	int a[3][3]{
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
	int b[3][3]{
		{2,4,6},
		{8,10,12},
		{14,16,18},
	};
	int r[3][3]{
		{3,6,9},
		{12,15,18},
		{21,24,27},
	};
	int** in1 = ConvertStaticArrayToPointers((int*)a,3,3);
	int** in2 = ConvertStaticArrayToPointers((int*)b, 3, 3);
	int** out = ConvertStaticArrayToPointers((int*)r, 3, 3);
	int** res;
	EXPECT_NO_THROW(res = MatrixAddition(in1, in2, 3, 3));
	EXPECT_FALSE(res == nullptr);
	EXPECT_TRUE(isEqual(out, res, 3, 3));
	delete[] in1;
	delete[]in2;
	delete[] out;
	EXPECT_NO_THROW(Destroy2DArray(res, 3));
}

TEST(TestTask, Add1x1Matrix) {
	int a[1][1]{
		{1},
	};
	int b[1][1]{
		{2},
	};
	int r[1][1]{
		{3},
	};
	int** in1 = ConvertStaticArrayToPointers((int*)a, 1, 1);
	int** in2 = ConvertStaticArrayToPointers((int*)b, 1, 1);
	int** out = ConvertStaticArrayToPointers((int*)r, 1, 1);
	int** res;
	EXPECT_NO_THROW(res = MatrixAddition(in1, in2, 1, 1));
	EXPECT_FALSE(res == nullptr);
	EXPECT_TRUE(isEqual(out, res, 1, 1));
	delete[] in1;
	delete[]in2;
	delete[] out;
	EXPECT_NO_THROW(Destroy2DArray(res, 1));
}

TEST(TestTask, Add3x2Matrix) {
	int a[2][3]{
		{1,2,3},
		{4,5,6},
	};
	int b[2][3]{
		{-2,4,-6},
		{8,-10,12},
	};
	int r[2][3]{
		{-1,6,-3},
		{12,-5,18},
	};
	int** in1 = ConvertStaticArrayToPointers((int*)a, 3, 2);
	int** in2 = ConvertStaticArrayToPointers((int*)b, 3, 2);
	int** out = ConvertStaticArrayToPointers((int*)r, 3, 2);
	int** res;
	EXPECT_NO_THROW(res = MatrixAddition(in1, in2, 3, 2));
	EXPECT_FALSE(res == nullptr);
	EXPECT_TRUE(isEqual(out, res, 3, 2));
	delete[] in1;
	delete[]in2;
	delete[] out;
	EXPECT_NO_THROW(Destroy2DArray(res, 2));
}
