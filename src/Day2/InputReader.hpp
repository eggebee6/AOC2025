/**
 * @copyright Copyright (c) 2025 eggebee6
 *
 * @file InputReader.hpp
 *
 * @brief An object for reading product ID ranges from an input file
 */

#ifndef __INPUTREADER_HPP__
#define __INPUTREADER_HPP__

#include "Range.hpp"
#include "Utility.hpp"

#include <string>
#include <vector>

/**
 * @brief An object for reading the input file and creating ranges from its contents
 */
class InputReader
{
public:
  /**
   * @brief Construct the reader to read from the specified file
   *
   * @param fileName Name of input file
   */
  InputReader(const std::string& fileName) : m_fileName(fileName) {}
  ~InputReader() {}

  /**
   * @brief Read the rotations from the input file
   *
   * @return Collection of rotations iterable in the order they were read
   */
  std::vector<Range> ReadRanges();

private:
  std::string m_fileName; ///< Input filename
};

#endif
