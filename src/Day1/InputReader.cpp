/**
 * @copyright Copyright (c) 2025 eggebee6
 *
 * @file InputReader.cpp
 */

#include "InputReader.hpp"
#include "Rotation.hpp"

#include <fstream>
#include <stdexcept>

std::vector<Rotation> InputReader::ReadRotations()
{
  constexpr unsigned int BUFFER_LEN = 32; // Input file buffer length
  char buffer[BUFFER_LEN];                // Buffer for reading lines from input file

  // Open input file
  std::ifstream fIn{m_fileName};
  if (!fIn.is_open())
  {
    throw std::runtime_error{"Failed to open input file"};
  }

  std::vector<Rotation> rotations{}; // Container for rotations read from file

  try
  {
    while (!fIn.eof())
    {
      // Read line from file
      fIn.getline(buffer, BUFFER_LEN);
      const std::string line{buffer};

      // Create rotation from line and push into vector
      rotations.push_back(CreateRotation(line));
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
  return rotations;
}

Rotation InputReader::CreateRotation(const std::string& line)
{
  Rotation::Direction dir = Rotation::Direction::LEFT;
  unsigned int clicks = 0;

  const std::size_t lineLen = line.length();

  // Need at least a rotation character and a digit character
  if (lineLen < 2)
  {
    throw std::invalid_argument{"Line length too short"};
  }

  // Set rotation enum based on rotation character
  const std::string lineDir = line.substr(0, 1);
  if (lineDir.compare("L") == 0)
  {
    dir = Rotation::Direction::LEFT;
  }
  else if (lineDir.compare("R") == 0)
  {
    dir = Rotation::Direction::RIGHT;
  }
  else
  {
    throw std::runtime_error{"Invalid direction in line"};
  }

  // Use remainder of line as an integer number of clicks
  const std::string lineClicks = line.substr(1, lineLen - 1);
  try
  {
    clicks = std::stoi(lineClicks);
  }
  catch (const std::invalid_argument& ex)
  {
    throw std::runtime_error{"Invalid clicks in line"};
  }

  return Rotation{dir, clicks};
}
