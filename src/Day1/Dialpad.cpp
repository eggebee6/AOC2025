/**
 * @copyright Copyright (c) 2025 eggebee6
 *
 * @file Dialpad.cpp
 */

#include "Dialpad.hpp"
#include "Rotation.hpp"

#include <stdexcept>

namespace day1
{

void Dialpad::ApplyRotation(const Rotation& rotation)
{
  // Full rotations don't modify dial number, only keep remainder of clicks
  const unsigned int clicks = rotation.clicks % DIAL_NUMBER_MODULUS;

  switch (rotation.direction)
  {
  case Rotation::Direction::LEFT:
    // Subtract clicks directly or compensate for crossing 0
    if (m_dialNumber > clicks)
    {
      m_dialNumber -= clicks;
    }
    else
    {
      m_dialNumber = DIAL_NUMBER_MODULUS - (clicks - m_dialNumber);
    }
    break;

  case Rotation::Direction::RIGHT:
    // Add clicks
    m_dialNumber += clicks;
    break;

  default:
    throw std::runtime_error{"Unknown rotation"};
  }

  // Modulus to keep the dial number in range
  m_dialNumber %= DIAL_NUMBER_MODULUS;
}

unsigned int Dialpad::GetZeroCrossings(const Rotation& rotation) const
{
  const unsigned int fullRotations = rotation.clicks / DIAL_NUMBER_MODULUS;
  const unsigned int clicks = rotation.clicks % DIAL_NUMBER_MODULUS;

  // Each full rotation incurs a 0 crossing
  unsigned int zeroCrossings = fullRotations;

  // Don't check for another 0 crossing if starting at 0
  if (m_dialNumber != 0)
  {
    switch (rotation.direction)
    {
    case Rotation::Direction::LEFT:
      if (m_dialNumber <= clicks)
      {
        ++zeroCrossings;
      }
      break;

    case Rotation::Direction::RIGHT:
      if ((m_dialNumber + clicks) > MAX_DIAL_NUMBER)
      {
        ++zeroCrossings;
      }
      break;

    default:
      throw std::runtime_error{"Unknown rotation"};
    }
  }

  return zeroCrossings;
}

} // namespace day1
