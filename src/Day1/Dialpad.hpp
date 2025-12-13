/**
 * @copyright Copyright (c) 2025 eggebee6
 *
 * @file Dialpad.hpp
 *
 * @brief Class representing a dialpad lock
 */

#ifndef __DIALPAD_HPP__
#define __DIALPAD_HPP__

#include "Rotation.hpp"

namespace day1
{

/**
 * @brief Lock with a rotating dial
 *
 * Rotations applied to the dial will change the number it is pointing to.  Left rotations will decrease the number
 * while right rotations will increase the number.  The dial number will wrap around between 0 and 99 (i.e. one click
 * left from 0 gives 99, one click right from 99 gives 0).  By default, the dial starts at 50.
 */
class Dialpad
{
public:
  static constexpr unsigned int MAX_DIAL_NUMBER = 99;     ///< Maximum number on the dialpad
  static constexpr unsigned int INITIAL_DIAL_NUMBER = 50; ///< Default starting number for the dialpad

  /**
   * @brief Create a dialpad starting on the given number
   *
   * @param startNum Starting number
   */
  Dialpad(const unsigned int startNum = INITIAL_DIAL_NUMBER) : m_dialNumber(startNum % MAX_DIAL_NUMBER) {}
  ~Dialpad() {}

  /**
   * @brief Get the number the dial is currently pointing to
   *
   * @return Dial number
   */
  inline unsigned int GetDialNumber() const { return m_dialNumber; }

  /**
   * @brief Apply a rotation to the dial
   *
   * @param rotation Rotation to apply
   */
  void ApplyRotation(const Rotation& rotation);

  /**
   * @brief Get the number of times a rotation would cause the dial to cross 0
   *
   * @param rotation Rotation to check
   */
  unsigned int GetZeroCrossings(const Rotation& rotation) const;

private:
  static constexpr unsigned int DIAL_NUMBER_MODULUS = MAX_DIAL_NUMBER + 1; ///< Modulus for wrapping the dial number

  unsigned int m_dialNumber; ///< Number the dialpad is currently pointing to
};

} // namespace day1

#endif
