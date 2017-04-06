# Plinko
Project code sample from intro level CS course at BYU 

Author: Nathan Marrs

Purpose:  This lab uses loops. These control structures facilitate powerful programs.
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
