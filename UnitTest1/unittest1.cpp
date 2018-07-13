#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Trainings/stl_experience.h"

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

	};
}