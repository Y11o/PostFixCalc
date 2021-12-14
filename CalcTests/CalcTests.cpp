#include "pch.h"
#include "CppUnitTest.h"
#include "..\Calculator\ReversePolishNotation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalcTests
{
	TEST_CLASS(CalcTests)
	{
	public:
		
		TEST_METHOD(Sum)
		{
			Assert::IsTrue(postFix("5+5", 1) == 10);
		}
		TEST_METHOD(Dif)
		{
			Assert::IsTrue(postFix("2-5", 1) == -3);
		}
		TEST_METHOD(Div)
		{
			Assert::IsTrue(postFix("21/3", 1) == 7);
		}
		TEST_METHOD(Mult)
		{
			Assert::IsTrue(postFix("11*2", 1) == 22);
		}
		TEST_METHOD(Pow)
		{
			Assert::IsTrue(postFix("5^3", 1) == 125);
		}
		TEST_METHOD(UnoMin)
		{
			Assert::IsTrue(postFix("(-1)*2", 1) == -2);
		}
		TEST_METHOD(PI)
		{
			Assert::IsTrue(postFix("PI", 1) == 3.14159265);
		}
		TEST_METHOD(E)
		{
			Assert::IsTrue(postFix("E", 1) == 2.718);
		}
		TEST_METHOD(sqrt)
		{
			Assert::IsTrue(postFix("sqrt(4)", 1) == 2);
		}
		TEST_METHOD(cos)
		{
			Assert::IsTrue(postFix("cos(0)", 1) == 1);
		}
		TEST_METHOD(sin)
		{
			Assert::IsTrue(postFix("sin(pi)", 1) == 0);
		}
		TEST_METHOD(logten)
		{
			Assert::IsTrue(postFix("log(10)", 1) == 1);
		}
		TEST_METHOD(ln)
		{
			Assert::IsTrue(postFix("ln(e)", 1) == 0.999896);
		}
		TEST_METHOD(asin)
		{
			Assert::IsTrue(postFix("asin(0)", 1) == 0);
		}
	};
}
