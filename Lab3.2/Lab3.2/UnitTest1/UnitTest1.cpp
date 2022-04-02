#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab3.2\Lab3.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab32
{
	TEST_CLASS(UnitTestLab32)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

			int const N = 2;
			Student* S = new Student[N];

			S[0].prizv = "Yurii";
			S[0].kurs = 3;
			S[0].spec = (Specilnist)1;
			S[0].Physical = 3;
			S[0].Math = 4;
			S[0].Informatik = 5;

			S[1].prizv = "Billy";
			S[1].kurs = 2;
			S[1].spec = (Specilnist)2;
			S[1].Physical = 4;
			S[1].Math = 4;
			S[1].Informatik = 4;

			Assert::IsTrue(BinSearch(S, N, "Yurii", 4, 5) == 0);
		}
	};
}