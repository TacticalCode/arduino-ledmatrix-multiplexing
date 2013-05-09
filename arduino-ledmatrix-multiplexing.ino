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

// 1-Dimensional Array, Bits represent LEDs
const char image[num_rows] ={B11111111,\
							 B10000011,\
							 B10000101,\
							 B10001001,\
							 B10010001,\
							 B10100001,\
							 B11000001,\
							 B11111111};

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
	// Repeat displaying a single image
	for(int i = 0; i < 500; i++)
	{
		// Iterate rows
		for(int r = 0; r < num_rows; r++)
		{
			// Switch on a row
			digitalWrite(start_rows + 2*r, HIGH);
			
			// Iterate Cols
			for(int c = 0; c < num_cols; c++)
			{
				// Check which cols have to be switched on
				if(image[r][c])
					digitalWrite(start_cols + 2*c, HIGH);
				else
					digitalWrite(start_cols + 2*c, LOW);
			}
			
			// Iterate Cols
			for(int c = 0; c < num_cols; c++)
			{
				// Switch off cols again
				digitalWrite(start_cols + 2*c, LOW);
			}
			
			// Switch off row again
			digitalWrite(start_rows + 2*r, LOW);
		}
	}
}