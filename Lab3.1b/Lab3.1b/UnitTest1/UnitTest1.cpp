#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab3.1b\Lab3.1b.cpp"

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
			Student* S = new Student[i];

			S->prizv = "a";
			S->kurs = (Kurs)1;
			S->spec = (Spec)1;
			S->physics = 5;
			S->maths = 4;
			S->numMethods = 3;

			int counter = Count(S, i);
			string max1 = Highest(S, i);

			Assert::AreEqual(expected_stud, counter);
			Assert::AreEqual(expected_predm, max1);
		}
	};
}
