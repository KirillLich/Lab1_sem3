#ifndef UI
#define UI
#include "..\sequence_based\LinkedListSequence.h"
#include "..\sequence_based\ArraySequence.h"
#include "..\ArraySequenceTest.h"
#include "..\LinkedListSequenceTest.h"
#include <chrono>
#include <algorithm>
#include <iostream>


bool comp(int a, int b) { return a < b; }

class UserInterface
{
	int action;
	int take()
	{
		char* t = new char;
		std::cin >> (*t);
		int T = 0;
		T = atoi(t);
		if (T == 0)
		{
			delete t;
			std::cout << "You need to use number from 1 to 9\n";
			T = take();
		}
		return T;
	}
	void printDialogMenu(const std::string dialogActions[], int n)
	{
		for (size_t i = 0; i < n; i++)
		{
			std::cout << dialogActions[i] << std::endl;
		}
	}

	template<typename T>
	void printSequence(Sequence<T>* seq)
	{
		std::cout << '[';
		for (size_t i = 0; i < seq->GetLenght(); i++)
		{
			std::cout << seq->Get(i);
			if (i != seq->GetLenght() - 1) std::cout << ", ";
		}
		std::cout << ']' << std::endl;
	}

	ArraySequence<int>* makeBaseIntSArr()
	{
		int* array = new int[4];
		array[0] = 1;
		array[1] = 5;
		array[2] = 3;
		array[3] = 4;

		ArraySequence<int>* arr = new ArraySequence<int>(array, 4);
		delete[] array;

		return arr;
	}
	ArraySequence<char>* makeBaseCharSArr()
	{
		char* array = new char[6];
		array[0] = 'L';
		array[1] = 'o';
		array[2] = 'v';
		array[3] = 'k';
		array[4] = 'o';
		array[5] = 'v';

		ArraySequence<char>* arr = new ArraySequence<char>(array, 6);
		delete[] array;

		return arr;
	}
	void useArraySequenceChar()
	{
		const std::string dialogActions[] = { "1. Exit", "2. Make new array", "3. Insert element" , "4. Change element"};
		ArraySequence<char>* charArr = makeBaseCharSArr();
		bool exit = false;
		int newSize;
		int position;
		char item;

		while (!exit)
		{
			printDialogMenu(dialogActions, 4);
			std::cout << "Started array: ";
			printSequence<char>(charArr);
			switch (take())
			{
			case 1:
				exit = true;
				break;
			case 2:
				delete charArr;
				charArr = new ArraySequence<char>;
				std::cout << "\nSet size for new array: ";
				std::cin >> newSize;
				std::cout << "\nWrite " << newSize << " elements of array.\n";
				for (size_t i = 0; i < newSize; i++)
				{
					std::cin >> item;
					charArr->Append(item);
				}
				newSize = 0;
				break;
			case 3:
				std::cout << "\nSet element and it's position: ";
				std::cin >> item >> position;
				try { charArr->InsertAt(item, position); }
				catch (std::exception& e)
				{
					std::cout << "\n" << e.what() << "\n";
				}
				break;
			case 4:
				std::cout << "\nSet element and it's position: ";
				std::cin >> item >> position;
				try { charArr->Get(position) = item; }
				catch (std::exception& e)
				{
					std::cout << "\n" << e.what() << "\n";
				}
				break;
			default:
				break;
			}
		}
		delete charArr;
	}
	void useArraySequenceInt()
	{
		const std::string dialogActions[] = { "1. Exit", "2. Make new array", "3. Insert element" , "4. Change element" };
		ArraySequence<int>* intArr = makeBaseIntSArr();
		bool exit = false;
		int newSize;
		int position;
		int item;

		while (!exit)
		{
			printDialogMenu(dialogActions, 4);
			std::cout << "Started array: ";
			printSequence<int>(intArr);
			switch (take())
			{
			case 1:
				exit = true;
				break;
			case 2:
				delete intArr;
				intArr = new ArraySequence<int>;
				std::cout << "\nSet size for new array: ";
				std::cin >> newSize;
				std::cout << "\nWrite " << newSize << " elements of array.\n";
				for (size_t i = 0; i < newSize; i++)
				{
					std::cin >> item;
					intArr->Append(item);
				}
				newSize = 0;
				break;
			case 3:
				std::cout << "\nSet element and it's position: ";
				std::cin >> item >> position;
				try { intArr->InsertAt(position, item); }
				catch (std::exception& e)
				{
					std::cout << "\n" << e.what() << "\n";
				}
				break;
			case 4:
				std::cout << "\nSet element and it's position: ";
				std::cin >> item >> position;
				try { intArr->Get(position) = item; }
				catch (std::exception& e)
				{
					std::cout << "\n" << e.what() << "\n";
				}
				break;
			default:
				break;
			}
		}
		delete intArr;
	}

	LinkedListSequence<char>* makeBaseCharList()
	{
		char* array = new char[6];
		array[0] = 'L';
		array[1] = 'o';
		array[2] = 'v';
		array[3] = 'k';
		array[4] = 'o';
		array[5] = 'v';

		LinkedListSequence<char>* list = new LinkedListSequence<char>;
		for (size_t i = 0; i < 6; i++)
		{
			list->Append(array[i]);
		}
		delete[] array;

		return list;
	}
	LinkedListSequence<int>* makeBaseIntList()
	{
		int* array = new int[4];
		array[0] = 1;
		array[1] = 5;
		array[2] = 3;
		array[3] = 4;

		LinkedListSequence<int>* list = new LinkedListSequence<int>;
		for (size_t i = 0; i < 4; i++)
		{
			list->Append(array[i]);
		}

		delete[] array;

		return list;
	}
	void useListSequenceChar()
	{
		const std::string dialogActions[] = { "1. Exit", "2. Make new list", "3. Insert element" , "4. Change element" };
		LinkedListSequence<char>* charList = makeBaseCharList();
		bool exit = false;
		int newSize;
		int position;
		char item;

		while (!exit)
		{
			printDialogMenu(dialogActions, 4);
			std::cout << "Started array: ";
			printSequence<char>(charList);
			switch (take())
			{
			case 1:
				exit = true;
				break;
			case 2:
				delete charList;
				charList = new LinkedListSequence<char>;
				std::cout << "\nSet size for new array: ";
				std::cin >> newSize;
				std::cout << "\nWrite " << newSize << " elements of array.\n";
				for (size_t i = 0; i < newSize; i++)
				{
					std::cin >> item;
					charList->Append(item);
				}
				newSize = 0;
				break;
			case 3:
				std::cout << "\nSet element and it's position: ";
				std::cin >> item >> position;
				try { charList->InsertAt(item, position); }
				catch (std::exception& e)
				{
					std::cout << "\n" << e.what() << "\n";
				}
				break;
			case 4:
				std::cout << "\nSet element and it's position: ";
				std::cin >> item >> position;
				try { charList->Get(position) = item; }
				catch (std::exception& e)
				{
					std::cout << "\n" << e.what() << "\n";
				}
				break;
			default:
				break;
			}
		}
		delete charList;
	}
	void useListSequenceInt()
	{
		const std::string dialogActions[] = { "1. Exit", "2. Make new list", "3. Insert element" , "4. Change element" };
		LinkedListSequence<int>* intList = makeBaseIntList();
		bool exit = false;
		int newSize;
		int position;
		char item;

		while (!exit)
		{
			printDialogMenu(dialogActions, 4);
			std::cout << "Started array: ";
			printSequence<int>(intList);
			switch (take())
			{
			case 1:
				exit = true;
				break;
			case 2:
				delete intList;
				intList = new LinkedListSequence<int>;
				std::cout << "\nSet size for new array: ";
				std::cin >> newSize;
				std::cout << "\nWrite " << newSize << " elements of array.\n";
				for (size_t i = 0; i < newSize; i++)
				{
					std::cin >> item;
					intList->Append(item);
				}
				newSize = 0;
				break;
			case 3:
				std::cout << "\nSet element and it's position: ";
				std::cin >> item >> position;
				try { intList->InsertAt(position, item); }
				catch (std::exception& e)
				{
					std::cout << "\n" << e.what() << "\n";
				}
				break;
			case 4:
				std::cout << "\nSet element and it's position: ";
				std::cin >> item >> position;
				try { intList->Get(position) = item; }
				catch (std::exception& e)
				{
					std::cout << "\n" << e.what() << "\n";
				}
				break;
			default:
				break;
			}
		}
		delete intList;
	}

	void chooseStartAction(bool &exit)
	{
		const std::string dialogActions[] = { "1. Run tests", "2. Use char array", "3. Use int array", "4. Use char list", "5. Use int list", "6. Run time test", "7. Exit"};
		printDialogMenu(dialogActions, 7);
		switch (take())
		{
		case 1:
			runTests();
			break;
		case 2:
			useArraySequenceChar();
			break;
		case 3:
			useArraySequenceInt();
			break;
		case 4:
			useListSequenceChar();
			break;
		case 5:
			useListSequenceInt();
			break;
		case 6:
			runTimeTest();
			break;
		case 7:
			exit = true;
			break;
		default:
			std::cout << "Use number from 1 to 6\n";
			break;
		}
	}

	void runTests()
	{
		LinkedListSequenceTester testListS;
		ArraySequenceTester testArrayS;
		std::cout << "\n\tAll tests finished. No errors found.\n\n";
	}

	void runTimeTest()
	{
		for (size_t i = 10; i < 100000000; i *= 10)
		{

			std::cout << "Test for " << i << " elements\n";
			auto startRawArray = std::chrono::high_resolution_clock::now();

			int* rawArray = new int[i];

			for (int j = 0; j < i; j++) {
				rawArray[j] = (rand() % 1000);
			}

			std::sort(rawArray, rawArray + i, comp);

			delete[] rawArray;

			auto stopRawArray = std::chrono::high_resolution_clock::now();
			auto durationRaw = std::chrono::duration_cast<std::chrono::milliseconds>(stopRawArray - startRawArray);

			std::cout << "Time taken by raw pointers: " << durationRaw.count() << " milliseconds" << std::endl;


			auto startSmrtPtr = std::chrono::high_resolution_clock::now();

			SmrtPtr<int[]> smrtPtrArray(i);

			for (int j = 0; j < i; j++) {
				smrtPtrArray[j] = rand() % 1000;
			}

			smrtPtrArray.sort(i, comp);

			auto stopSmrtPtr = std::chrono::high_resolution_clock::now();
			auto durationSmart = std::chrono::duration_cast<std::chrono::milliseconds>(stopSmrtPtr - startSmrtPtr);

			std::cout << "Time taken by smart pointers: " << durationSmart.count() << " milliseconds" << std::endl;
		}
	}
public:
	UserInterface()
	{
		bool exit = false;
		while(!exit) chooseStartAction(exit);
	}
};

#endif