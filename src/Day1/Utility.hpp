/**
 * @copyright Copyright (c) 2025 eggebee6
 *
 * @file Utility.hpp
 *
 * @brief Utility methods
 */

#ifndef __UTILITY_HPP__
#define __UTILITY_HPP__

#include "Rotation.hpp"
#include <ostream>

namespace day1
{

/**
 * @brief Output stream operator for outputting a rotation
 *
 * @param out Output stream
 * @param rotation Rotation to output
 * @return The output stream provided in the out parameter
 */
std::ostream& operator<<(std::ostream& out, const Rotation& rotation)
{
  switch (rotation.direction)
  {
  case Rotation::Direction::LEFT:
    out << "Left ";
    break;

  case Rotation::Direction::RIGHT:
    out << "Right ";
    break;

  default:
    out << "(Unknown rotation) ";
    break;
  }

  out << rotation.clicks;

  return out;
}

} // namespace day1

#endif
