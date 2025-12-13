/**
 * @copyright Copyright (c) 2025 eggebee6
 *
 * @file InputReader.cpp
 */

#include "InputReader.hpp"
#include "Range.hpp"

#include <fstream>
#include <stdexcept>
#include <string>

namespace day2
{

std::vector<Range> InputReader::ReadRanges()
{
  constexpr char RANGE_DELIMITER = ',';

  constexpr unsigned int BUFFER_LEN = 256; // Input file buffer length
  char buffer[BUFFER_LEN];                 // Buffer for reading lines from input file

  // Open input file
  std::ifstream fIn{m_fileName};
  if (!fIn.is_open())
  {
    throw std::runtime_error{"Failed to open input file"};
  }

  std::vector<Range> ranges{}; // Container for ranges

  try
  {
    while (!fIn.eof())
    {
      // Read range from file and discard delimiter
      fIn.get(buffer, BUFFER_LEN, RANGE_DELIMITER);
      fIn.get();

      // Create range from string and push into vector
      const std::string str{buffer};
      ranges.push_back(Range::FromString(str));
    }
  }
  catch (...)
  {
    // Close file before re-throwing
    fIn.close();
    throw;
  }

  // Close file and return rotation collection
  fIn.close();
  return ranges;
}

} // namespace day2