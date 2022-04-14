#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab3.2b\Lab3.2b.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			int N = 2;
			Student* k = new Student[N];
			k[0].prizv = "a";
			k[0].kurs = (Kurs)1;
			k[0].spec = (Spec)1;
			k[0].physics = 5;
			k[0].maths = 4;
			k[0].numMethods = 3;

			k[1].prizv = "c";
			k[1].kurs = (Kurs)2;
			k[1].spec = (Spec)2;
			k[1].physics = 5;
			k[1].maths = 5;
			k[1].programming = 5;

			Assert::IsTrue(BinSearch(k, N, "a",4,3) == 0);
		}
	};
}
