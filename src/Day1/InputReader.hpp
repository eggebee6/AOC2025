/**
 * @copyright Copyright (c) 2025 eggebee6
 *
 * @file InputReader.hpp
 *
 * @brief An object for creating rotation objects based on the text in an input file
 */

#ifndef __INPUTREADER_HPP__
#define __INPUTREADER_HPP__

#include "Rotation.hpp"

#include <string>
#include <vector>

/**
 * @brief An object for reading the input file and creating rotations from its contents
 */
class InputReader
{
public:
  /**
   * @brief Construct the reader
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
  std::vector<Rotation> ReadRotations();

private:
  /**
   * @brief Create a rotation from a line of text
   *
   * @param line Text encoding of a single rotation
   * @return Rotation encoded by the text
   */
  Rotation CreateRotation(const std::string& line);

  std::string m_fileName; ///< Input filename
};

#endif
