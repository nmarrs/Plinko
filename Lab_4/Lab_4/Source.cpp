/*

Nathan Marrs

Purpose:  This lab introduces you to loops. These control structures facilitate powerful programs.
It is important that you become comfortable with the various kinds of loops, as each has its own uses.
This is a C++ program to simulate a game of Plinko and to compute average winnings based on where you drop your chips.
The user can either drop a single chip or drop multiple chips down a chosen slot.

Input:

Menu Item Choice

Slot to drop chip in

How many chips to drop

Output:

Chip path as it falls (1 decimal place)

Amount of money won by chip (nearest penny)

Total money won by all chips (nearest penny)

Average money won per chip (nearest penny)

*/

/*

Test Cases

Test 1:
Input: The following test case is a stream of inputs which tests the possible erroneous input situations:  -1, 4, 1, -3, 9, 4, 2, -9, 9, 0, -2, 100

Expected Output: Verify that an appropriate error message is given for each error and that there is an appropriate re-request until a correct input is given.

Actual Output: An appropriate error message is given for each error and there is an appropriate re-request until a correct input is given.

Test 2: The following test case is to test for randomness in the single chip drop
Input: Slot 4 (3x)

Expected Output: There should be a random slot path and destination every time program is run.

Actual Output: There was a random slot path and destination every time program was run.

Test 3: The following test case is to test if the multiple chips program matches the bell curve values provided on LS,
as well as to ensure program can be ran correctly more than once
Input: Number of chips: 10000, Slot: 0, 4, 7

Expected Output: Avg winnings per chip: ~750, ~2550, ~1000

Actual Output: Avg winnings per chip: 779.33, 2525.25, 1014.46

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const int MENU_DROP_MULTIPLE_CHIP = 2;
	const int MENU_DROP_SINGLE_CHIP = 1;
	const int MENU_EXIT = 0;
	const int MIN_SLOT_NUM = 0;
	const int MAX_SLOT_NUM = 8;
	const int NUM_PEGS = 12;
	const int ONE_DECIMAL_PLACE = 1;
	const int TWO_DECIMAL_PLACE = 2;
	const int SLOT_0_WINNINGS = 100.0;
	const int SLOT_1_WINNINGS = 500.0;
	const int SLOT_2_WINNINGS = 1000.0;
	const int SLOT_3_WINNINGS = 0.0;
	const int SLOT_4_WINNINGS = 10000.0;
	const int SLOT_5_WINNINGS = 0.0;
	const int SLOT_6_WINNINGS = 1000.0;
	const int SLOT_7_WINNINGS = 500.0;
	const int SLOT_8_WINNINGS = 100.0;
	const double PEG_VALUE = 0.5;
	// Declaring and initializing constants used in program

	int userMenuChoice = 0;
	int numSlot = 0;
	int numChip = 0;
	int randNum = 0;
	double winnings = 0.0;
	double totalWinnings = 0.0;
	double totalAvgWinnings = 0.0;
	double numSlotForLoop = 0.0;
	// Declaring and initializing variables used in program

	srand(time(NULL));
	// Providing random seed so new random numbers are generated every time program is run

	cout << "Welcome to the plinko simulator!" << endl;

	do
	{
		cout << "MENU: Please select one of the following options:" << endl;
		cout << "0 - Quit the program" << endl;
		cout << "1 - Drop a single chip into one slot" << endl;
		cout << "2 - Drop multiple chips into one slot" << endl;

		cout << "Enter your selection now: ";
		cin >> userMenuChoice;

		while (userMenuChoice < MENU_EXIT || userMenuChoice > MENU_DROP_MULTIPLE_CHIP)
		{
			cout << "INVALID SELECTION.  Please enter 0, 1, or 2" << endl;

			cout << "MENU: Please select one of the following options:" << endl;
			cout << "0 - Quit the program" << endl;
			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;

			cout << "Enter your selection now: ";
			cin >> userMenuChoice;
		}
		//Error handling for user menu choice

		if (userMenuChoice == MENU_DROP_SINGLE_CHIP)
		{
			cout << "*** DROP SINGLE CHIP ***" << endl;
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> numSlot;

			if (numSlot < MIN_SLOT_NUM || numSlot > MAX_SLOT_NUM)
			{
				cout << "INVALID SLOT." << endl;
			}
			//Error handling for user slot choice
			else
			{
				cout << "*** DROPPING CHIP INTO SLOT " << numSlot << " ***" << endl;
				numSlotForLoop = numSlot;

				cout << "PATH: [";
				for (int i = 1; i <= NUM_PEGS; i++)
				{
					cout << fixed << setprecision(ONE_DECIMAL_PLACE) << numSlotForLoop << " ";
					randNum = rand() % 2;
					if (randNum == 0 && numSlotForLoop > MIN_SLOT_NUM || numSlotForLoop == MAX_SLOT_NUM)
					{
						numSlotForLoop = numSlotForLoop - PEG_VALUE;
					}
					else if (randNum == 1 && numSlotForLoop < MAX_SLOT_NUM || numSlotForLoop == MIN_SLOT_NUM)
					{
						numSlotForLoop = numSlotForLoop + PEG_VALUE;
					}
				}
				cout << fixed << setprecision(ONE_DECIMAL_PLACE) << numSlotForLoop << "]" << endl;
				// For loop that randomly determines chip path on virtual board using rand() method

				if (numSlotForLoop == 0.0)
				{
					winnings = SLOT_0_WINNINGS;
				}
				else if (numSlotForLoop == 1.0)
				{
					winnings = SLOT_1_WINNINGS;
				}
				else if (numSlotForLoop == 2.0)
				{
					winnings = SLOT_2_WINNINGS;
				}
				else if (numSlotForLoop == 3.0)
				{
					winnings = SLOT_3_WINNINGS;
				}
				else if (numSlotForLoop == 4.0)
				{
					winnings = SLOT_4_WINNINGS;
				}
				else if (numSlotForLoop == 5.0)
				{
					winnings = SLOT_5_WINNINGS;
				}
				else if (numSlotForLoop == 6.0)
				{
					winnings = SLOT_6_WINNINGS;
				}
				else if (numSlotForLoop == 7.0)
				{
					winnings = SLOT_7_WINNINGS;
				}
				else if (numSlotForLoop == 8.0)
				{
					winnings = SLOT_8_WINNINGS;
				}
				// Logic that determines amount of winnings based on chip final location
				cout << fixed << setprecision(TWO_DECIMAL_PLACE) << "WINNINGS: $" << winnings << endl;
				winnings = 0.0;
				numSlotForLoop = 0.0;
				// Reseting user input
			}
		}
		else if (userMenuChoice == MENU_DROP_MULTIPLE_CHIP)
		{
			cout << "*** DROP MULTIPLE CHIPS ***" << endl;
			cout << "How many chips do you want to drop (>0)? ";
			cin >> numChip;

			if (numChip <= 0)
			{
				cout << "INVALID NUMBER OF CHIPS." << endl;
			}
			//Error handling for user chip choice
			else
			{
				cout << "Which slot do you want to drop the chip in (0-8)? ";
				cin >> numSlot;

				if (numSlot < MIN_SLOT_NUM || numSlot > MAX_SLOT_NUM)
				{
					cout << "INVALID SLOT." << endl;
				}
				//Error handling for user slot choice
				else
				{
					numSlotForLoop = numSlot;

					for (int j = 1; j < numChip; j++)
					{
						for (int i = 1; i <= NUM_PEGS; i++)
						{
							randNum = rand() % 2;
							if (randNum == 0 && numSlotForLoop > MIN_SLOT_NUM || numSlotForLoop == MAX_SLOT_NUM)
							{
								numSlotForLoop = numSlotForLoop - PEG_VALUE;
							}
							else if (randNum == 1 && numSlotForLoop < MAX_SLOT_NUM || numSlotForLoop == MIN_SLOT_NUM)
							{
								numSlotForLoop = numSlotForLoop + PEG_VALUE;
							}
						}
						// For loop that randomly determines chip path on virtual board using rand() method

						if (numSlotForLoop == 0.0)
						{
							winnings = SLOT_0_WINNINGS;
						}
						else if (numSlotForLoop == 1.0)
						{
							winnings = SLOT_1_WINNINGS;
						}
						else if (numSlotForLoop == 2.0)
						{
							winnings = SLOT_2_WINNINGS;
						}
						else if (numSlotForLoop == 3.0)
						{
							winnings = SLOT_3_WINNINGS;
						}
						else if (numSlotForLoop == 4.0)
						{
							winnings = SLOT_4_WINNINGS;
						}
						else if (numSlotForLoop == 5.0)
						{
							winnings = SLOT_5_WINNINGS;
						}
						else if (numSlotForLoop == 6.0)
						{
							winnings = SLOT_6_WINNINGS;
						}
						else if (numSlotForLoop == 7.0)
						{
							winnings = SLOT_7_WINNINGS;
						}
						else if (numSlotForLoop == 8.0)
						{
							winnings = SLOT_8_WINNINGS;
						}
						// Logic that determines amount of winnings based on chip final location
						totalWinnings = totalWinnings + winnings;
						// Adding up each chip winnings value until all chips have been tested
						winnings = 0.0;
						// Reseting winnings
						numSlotForLoop = numSlot;
						// Reseting slot number to match original input in order to fix bell curve distribution of data
					}

					cout << fixed << setprecision(TWO_DECIMAL_PLACE) << "Total Winnings on " << numChip << " chips: $" << totalWinnings << endl;

					totalAvgWinnings = totalWinnings / numChip;

					cout << fixed << setprecision(TWO_DECIMAL_PLACE) << "Average winnings per chip: $" << totalAvgWinnings << endl;

					totalWinnings = 0.0;
					totalAvgWinnings = 0.0;
					// Reseting winnings numbers to 0.0 to avoid invalid output
				}
			}
		}
	} while (userMenuChoice != MENU_EXIT);

	cout << "GOODBYE!" << endl;
	system("pause");
	return 0;
}