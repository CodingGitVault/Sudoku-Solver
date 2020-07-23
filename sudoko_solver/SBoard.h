/* ======================================
* Author : Richard Chin
* Date   : July 2020
* =======================================*/
#pragma once
#include <vector>

// How many cells per side on our board
#define BOARD_SIZE 9

// The size of each sub-blocks
#define BLOCK_SIZE (BOARD_SIZE / 3)

/*******************************
* Integer value of a sudoko cell
********************************/
enum class SValueEnum {
	SValue_Empty = 0,
	SValue_1 = 1,
	SValue_2 = 2,
	SValue_3 = 3,
	SValue_4 = 4,
	SValue_5 = 5,
	SValue_6 = 6,
	SValue_7 = 7,
	SValue_8 = 8,
	SValue_9 = 9,
};

/*
*/
enum class SStateEnum {
	SState_Fixed,		// Cannot be changed.
	SState_Free			// Free to change
};

/*
* Each cell will have a 'state'.
* This includes any indicated value, but could also store if the current value
* was from the user, or have been calculated.
*/
struct SCellStruct {

	SCellStruct(SValueEnum v = SValueEnum::SValue_Empty, SStateEnum s = SStateEnum::SState_Free)
		: value(v), state(s)
	{
	}

	SValueEnum value;
	SStateEnum state;
};

/******************************************
* Encapsulates the sudoko board
*******************************************/
class SBoard
{
public:

	SBoard();

	// Returns the array of cells for board row
	std::vector<SCellStruct> GetRow(int);

	// Returns the array of cells for board row
	std::vector<SCellStruct> GetCol(int);

	/*
	* Returns the cell information structure
	* col and row are the zero-based index of the board cell.
	* This must be in the range 0 - 8.
	*/
	SCellStruct GetCell(int col, int row);
		
	/*
	* Sets the cell value or state of the given board cell.
	*/
	void SetCell(int col, int row, SCellStruct cell);

	/*
	* Clears the entire board with empty values
	*/
	void ClearBoard();

protected:
	std::vector<SCellStruct> m_boarddata;
};
