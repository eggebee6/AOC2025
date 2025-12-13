/**
 * @copyright Copyright (c) 2025 eggebee6
 *
 * @file Rotation.hpp
 *
 * @brief An object representing a rotation which may be applied to the dialpad
 */

#ifndef __ROTATION_HPP__
#define __ROTATION_HPP__

namespace day1
{

/**
 * @brief A struct containing the direction and number of clicks in a rotation
 */
struct Rotation
{
  /**
   * @brief Enum for rotation directions
   */
  enum class Direction
  {
    LEFT, ///< Rotate dialpad left
    RIGHT ///< Rotation dialpad right
  };

  /**
   * @brief Create a rotation with the given direction and number of clicks
   *
   * @param dir Rotation direction
   * @param numClicks Number of clicks
   */
  constexpr Rotation(const Direction dir, const unsigned int numClicks) : direction(dir), clicks(numClicks) {}

  Rotation(const Rotation&) = default;
  Rotation& operator=(const Rotation&) = default;
  Rotation(Rotation&&) = default;
  Rotation& operator=(Rotation&&) = default;

  ~Rotation() = default;

  /**
   * @brief Create a left rotation with the given number of clicks
   *
   * @param numClicks Number of clicks
   * @return Left rotation
   */
  static Rotation Left(const unsigned int numClicks) { return Rotation{Direction::LEFT, numClicks}; }

  /**
   * @brief Create a right rotation with the given number of clicks
   *
   * @param numClicks Number of clicks
   * @return Right rotation
   */
  static Rotation Right(const unsigned int numClicks) { return Rotation{Direction::RIGHT, numClicks}; }

  const Direction direction; ///< Rotation direction
  const unsigned int clicks; ///< Number of clicks
};

} // namespace day1

#endif
