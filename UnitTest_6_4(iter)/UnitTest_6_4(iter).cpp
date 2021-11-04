#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Home\source\repos\Lab_6_4(iter)\Lab_6_4(iter)\Lab_6_4(iter).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64iter
{
	TEST_CLASS(UnitTest64iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 3;
			int a[n];
			a[0] = 0;
			a[1] = -9;
			a[2] = 9;

			Assert::AreEqual(Min(a, n), 0);
		}
	};
}
