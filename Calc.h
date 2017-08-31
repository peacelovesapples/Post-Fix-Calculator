// 
// Calc.h
// nicholas waters 
// cs110c 3/18/2017
//
#include "CharStack.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;



class Calc
{
	
	public:
		CharStack *calc;
		Calc(){ calc = new CharStack;}
		string postFix(string);
		int compute(string);
		bool isLowerPrec(char,char);
		int convInt(char);
		char convChar(int n);
		int getOp(char);
};			
int Calc::getOp(char c)
{
	int resOp;
	if ( c == '-' )
		return 1;
	else if ( c == '+' )
		return 2;
	else if ( c == '*' )
		return 3;
	else if ( c == '/' )
		return 4;
return 0;
}
int Calc::compute(string s)
{

	while ( calc->isEmpty() != 1 )
	{
		calc->pop();
	}
	int operand2 = 0;
	int operand1 = 0;
	string temp = postFix(s);

	for ( int i=0; i<temp.length();i++)
	{
		if (  temp[i] != '\0' && temp[i] != '*' && temp[i] != '/' && temp[i] != '+' && temp[i] != '-' && temp[i] != '(' && temp[i] != ')' )			
			calc->push(temp[i]);
		else 
		{
			
			operand2 = convInt( calc->peek() );
			calc->pop();
			operand1 = convInt( calc->peek() );
			calc->pop();
			if ( getOp( temp[i] ) == 1 )
				calc->push( convChar( operand1-operand2) );	
			else if ( getOp( temp[i] ) == 2 )
				calc->push( convChar( operand1+operand2) );	
			else if ( getOp( temp[i] ) == 3 )
				calc->push( convChar( operand1*operand2) );	
			else if ( getOp( temp[i] ) == 4 )
				calc->push( convChar( operand1/operand2) );	
			 
		}

	}
	return ( convInt( calc->peek() ) );
}

char Calc::convChar(int n)
{
	return (n + '0');
}
int Calc::convInt(char c)
{
	return ( c - '0');
}
bool Calc::isLowerPrec( char c, char d)                           // helper function to determine operator precedence
{

	int precC = 0;
	int precD = 0;

	if ( c == '-' || c == '+' )
		precC = 1;
	else{ 
		precC = 2;
	}
	 if ( d == '*' || d == '/' )
		precD = 2;
	 else{
		 precD = 1;
	 }

	if ( precC < precD )
		return 1;
	return 0;
}
string Calc::postFix(string s)   // takes string infix return string postfix
{
	
	bool isGreater;
	string postFix;	
	for ( int i=0; i<=s.length(); i++)
	{

//		cout << " this iternation, s[" << i << "] == " << s[i] << endl;
//		cout << " the cuurent stack at iteration " << i << " is equal to: " << calc->peek() << endl;	
//		cout << " currently  postFix is equal to: " << postFix << endl << endl << endl;
		//calc->push(s[i]);
		//cout << calc->peek() << endl;
		//cout << postFix;
	isGreater = false;
		if (  s[i] != '\0' && s[i] != '*' && s[i] != '/' && s[i] != '+' && s[i] != '-' && s[i] != '(' && s[i] != ')' )			
		{
			//postFix[i] = s[i];
		//	cout << "putting operand in postFix" << endl;
			postFix.push_back(s[i]);

		//	cout << "postFix is now: "<< endl;
		//	cout << postFix <<endl;
		}
		else if ( s[i] == '(')
			{
		//		cout << "pushing ( to stack" << endl;
			calc->push(s[i]);
		 //       cout << calc->peek() << endl;
			}
		else if (  s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' )
		{
			if ( calc->isEmpty() )
			{
		//		cout << "pushed :" << s[i]  << " to stack" << endl;
		      		calc->push(s[i]);
			}
			else while ( isGreater == false )
				{ 

					if ( calc->peek() == '(' || isLowerPrec( calc->peek(), s[i] ) || calc->isEmpty()==true )
					{
		//				cout << "peeking at stack, stack is: " << calc->peek() << endl;
						if ( calc->push(s[i]) )
		//					cout << "push was a success" << endl;
							
		//				cout << "stack is now: " << calc->peek() << endl;
						isGreater= true;	
					}
					else 
					{	
		//				cout << "my program is fucked heres the push" << endl;
						postFix.push_back( calc->peek() );
						calc->pop();
					}
					
				}
		}else if ( s[i] == ')')
			{
				while ( calc->peek() != '(' )
				{
					postFix.push_back( calc->peek() );
					calc->pop();
				}
				if ( calc->peek() == '(' )
						calc->pop();


			}
		else if ( s[i] == '\0' )
				{
					while ( calc->isEmpty() != true )
					{
						postFix.push_back( calc->peek() );
						calc->pop();
					}
				}

//		cout << "at the end of iteration " << i << " stack is: " << calc->peek() << " postFix is: " << postFix << endl << endl;
       }
	
return (postFix);


}
