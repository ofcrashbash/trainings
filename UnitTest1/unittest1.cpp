#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Trainings/stl_experience.h"
#include "../Trainings/theEulerProject.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Assert::AreEqual(vetor_test(), 0, L"mesage");
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(multipliers_of_5_and_3(10), 23, L"sum of mulitpliers isn't equal to 23");
		}

	};
}