#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab3.1\Lab3.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab31
{
	TEST_CLASS(UnitTestLab31)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			string expected_predm = "physics";
			int expected_stud = 0;
			
			
			int const i = 1;
			Student* S = new Student[i];

			S->prizvandname = "Yurii";
			S->kurs = 3;
			S->spec = (Specilnist)1;
			S->Physical = 5;
			S->Math = 4;
			S->Informatik = 3;
			
			int counter = Count(S, i);
			string max1 = Highest(S, i);

			Assert::AreEqual(expected_stud, counter);
			Assert::AreEqual(expected_predm, max1);
			
		}
	
	};
}
