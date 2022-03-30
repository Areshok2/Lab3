
#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Politeh\PKR\Lab3.1\Lab3.1\Lab3.1\Lab3.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			string expected_predm = "physics";
			int expected_stud = 0;
			
			
			int const i = 1;
			Student* S = new Student[1];

			S->prizvandname = "Yurii";
			S->kurs = 3;
			S->spec = (Specilnist)1;
			S->Physical = 5;
			S->Math = 4;
			S->Informatik = 4;
			
			int counter = SearchStudentAverageScoreAbove(S, i);
			Assert::AreEqual(expected_stud,counter);

			string max1 = SearchPredmetAverageScoreHighest(S, i);
			Assert::AreEqual(expected_predm, max1);
			
		}
	
	};
}
