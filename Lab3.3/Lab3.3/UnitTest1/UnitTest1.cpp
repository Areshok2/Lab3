#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab3.3\Lab3.3.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab33
{
	TEST_CLASS(UnitTestLab33)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			const int N = 1;


			Zodiac* Z = new Zodiac[N];

			Z[0].date[0] = 14;
			Z[0].date[1] = 11;
			Z[0].date[2] = 2002;

			Z[0].name = "Billy";
			Z[0].surname = "Herington";
			Z[0].zodiac_sign = "Scorpio";


			Assert::IsTrue(Search(Z, N, "Scorpio") == 1);
		}
	};
}
