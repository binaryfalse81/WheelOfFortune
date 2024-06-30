#include "pch.h"
#include "../Project1/wheel.cpp"

TEST(TestCaseName, TestName) {
	//arrange
	Wheel app;
	vector<string> strs = {
		"BUILDLEV", "EATREALROBOT"
	};
	string userdata = "ERABCDFGHIJKLMNOPQSTUVWXYZ";

	//act
	int actual = app.Solve(strs, userdata);

	//assertion
	EXPECT_EQ(actual, 6500);
}

TEST(TestCaseName, TestName2) {
	//arrange
	Wheel app;
	vector<string> strs = {
		"ABS", "ABS", "AAAAAKBA"
	};
	string userdata = "XASBKQDJHMNPTLVUCGEWFORIYZ";

	//act
	int actual = app.Solve(strs, userdata);

	//assertion
	EXPECT_EQ(actual, 9500);
}

TEST(TestCaseName, TestName3) {
	//arrange
	Wheel app;
	vector<string> strs = {
		"IOEW", "JLKXD", "JWKLE"
	};
	string userdata = "PTLVUCGWFXORIBYASEKQDJHMNZ";

	//act
	int actual = app.Solve(strs, userdata);

	//assertion
	EXPECT_EQ(actual, 1900);
}