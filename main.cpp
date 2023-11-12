//for tracing memory leaks
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW


#include <iostream>
#include <string>
#include "SmartPointer.h"
#include "SmartPtrTester.h"
#include "sequence_based/ArraySequence.h"
#include "based_struct/Sequence.h"
#include "sequence_based/LinkedListSequence.h"
#include "LinkedListSequenceTest.h"
#include "ArraySequenceTest.h"
#include "UI\UI.h"
using namespace std;

class Letter
{
public :
	virtual void pop() { std::cout << 0; };
	Letter() {};
};

class AnotherLetter 
{
public:
	AnotherLetter() {};
	~AnotherLetter() { std::cout << 100; }
	virtual void make() {};
};

class SubLetter : public Letter
{
	AnotherLetter AL;
public :
	void pop() { std::cout << 1; };
	SubLetter() { };
	~SubLetter() { std::cout << 89; }
};

int main()
{
	/*SmrtPtrTester Tester1;
	Tester1.RunTests();

	cout << Tester1.GetPassedTests();


	SmrtPtrArrayTester Tester2;
	Tester2.RunTests();*/
	{
		UserInterface ui;
	}

	_CrtDumpMemoryLeaks();//comment this line if writing something except tests
}

