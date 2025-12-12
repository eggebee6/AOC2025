/**
 * @copyright Copyright (c) 2025 eggebee6
 *
 * @file main.cpp
 *
 * @brief Advent of Code 2025, Day 1
 *
 * The input file should be a text file named "Input.txt" and should be located in the same directory as the executable.
 * There should be no trailing line at the end of the file (e.g. the last line in the file is the last rotation, not a
 * blank line)
 */

#include "Dialpad.hpp"
#include "InputReader.hpp"
#include "Rotation.hpp"
#include "Utility.hpp"

#include <cstdlib>
#include <iostream>

int main()
{
  Dialpad dialpad{};
  InputReader reader{"Input.txt"};

  try
  {
    // Read rotations from input file
    auto rotations = reader.ReadRotations();

    std::cout << "Dial starting at " << dialpad.GetDialNumber() << std::endl;

    unsigned int zeroCount = 0;
    for (const auto& rotation : rotations)
    {
      // Get number of zero crossings this rotation would incur and add them to the total
      // Zero crossings may be ignored for Part 1
      unsigned int zeroCrossings = dialpad.GetZeroCrossings(rotation);
      zeroCount += zeroCrossings;

      // Apply rotation to dialpad
      dialpad.ApplyRotation(rotation);

      // Increment the zero count if landing on zero, except if any zero crossings have occurred (don't double count)
      if ((dialpad.GetDialNumber() == 0) && (zeroCrossings == 0))
      {
        ++zeroCount;
      }

      // Display rotation and new dialpad state
      std::cout << rotation << ", dial " << dialpad.GetDialNumber() << std::endl;
    }

    // Display zero count
    std::cout << "Pointed to zero " << zeroCount << " times" << std::endl;

    return EXIT_SUCCESS;
  }
  catch (const std::exception& ex)
  {
    std::cerr << "Failed due to unhandled exception:  " << ex.what() << std::endl;

    return EXIT_FAILURE;
  }
}
