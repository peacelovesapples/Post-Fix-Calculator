//
//
// CalcMain.cpp
// Nicholas Waters
//
//
//
#include "CharStack.h"
#include "Calc.h"		
#include <iostream>
#include <string>
using namespace std;




int main()
{
	Calc calcOb;
	char eight = '8';	
	string test = "8+3*3-9";
	string test1 = "(1+4)*(5-2)";
	string test2 = "(9-7)";
	string test3 = "7-(3+2*1)/9";	
	string test4 = "3-(2/7*5)";

string report = calcOb.postFix(test);
string report1 = calcOb.postFix(test1);
string report2 = calcOb.postFix(test2);
string report3 = calcOb.postFix(test3);
string report4 = calcOb.postFix(test4);

int result = calcOb.compute(test2);
int result1 = calcOb.compute(test3);
int result2 = calcOb.compute(test1);
int result3 = calcOb.compute(test);
int result4 = calcOb.compute(test4);

cout << "the infix is: " << test2 << " postfix is: " << report2 << " the calculated result is: "<< result << endl;

cout << "the infix is: " << test3 << " postfix is: " << report3 << " the calculated result is: "<< result1 << endl;

cout << "the infix is: " << test1 << " postfix is: " << report1 << " the calculated result is: "<< result2 << endl;

cout << "the infix is: " << test << " postfix is: " << report << " the calculated result is: "<< result3 << endl;

cout << "the infix is: " << test4 << " postfix is: " << report4 << " the calculated result is: "<< result4 << endl;

return 0;
}
