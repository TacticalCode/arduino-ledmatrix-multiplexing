/*****************************
 *
 * LED Matrix multiplexing demo
 * Author: Damon Dransfeld
 * License: CC-BY-SA 3.0
 * Web: http://tacticalcode.de
 *
 *****************************/


// Offsets for rows/cols
const int start_rows = 38;
const int start_cols = 22;

// Amount of rows/cols
const int num_rows = 8;
const int num_cols = 8;

void setup()
{
	// Set up rows
	for(int i = 0; i < num_rows; i++)
	{
		pinMode(start_rows + (2*i), OUTPUT);
		digitalWrite(start_rows + (2*i), LOW);
	}

	// Set up cols
	for(int i = 0; i < num_cols; i++)
	{
		pinMode(start_cols + (2*i), OUTPUT);
		digitalWrite(start_cols + (2*i), LOW);
	}
}

void loop()
{
}