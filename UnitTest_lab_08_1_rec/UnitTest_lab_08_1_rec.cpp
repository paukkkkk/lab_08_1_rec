#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_08_1_rec/lab_08_1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81rec
{
    TEST_CLASS(UnitTest81rec)
    {
    public:
        TEST_METHOD(CountOneGroup)
        {
            char s[101] = "a,b-c";
            Assert::AreEqual(1, Count(s, 0));
        }
        TEST_METHOD(CountTwoGroups)
        {
            char s[101] = "a,b-c,,x-d";
            Assert::AreEqual(2, Count(s, 0));
        }
        TEST_METHOD(CountNoGroups)
        {
            char s[101] = "abc";
            Assert::AreEqual(0, Count(s, 0));
        }
        TEST_METHOD(CountEmptyString)
        {
            char s[101] = "";
            Assert::AreEqual(0, Count(s, 0));
        }
        TEST_METHOD(ChangeOneGroup)
        {
            char s[101] = "a,b-c";
            char dest[101];
            char* r = Change(dest, s, 0, 0);
            Assert::AreEqual(string("a**c"), string(r));
            Assert::AreEqual(string("a**c"), string(dest));
        }
        TEST_METHOD(ChangeTwoGroups)
        {
            char s[101] = "a,b-c,,x-d";
            char dest[101];
            Assert::AreEqual(string("a**c,**d"), string(Change(dest, s, 0, 0)));
        }
        TEST_METHOD(ChangeNothingToChange)
        {
            char s[101] = "abc";
            char dest[101];
            Assert::AreEqual(string("abc"), string(Change(dest, s, 0, 0)));
        }
        TEST_METHOD(ChangeEmptyString)
        {
            char s[101] = "";
            char dest[101];
            Assert::AreEqual(string(""), string(Change(dest, s, 0, 0)));
        }
    };
}