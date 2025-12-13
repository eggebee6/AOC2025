/**
 * @copyright Copyright (c) 2025 eggebee6
 *
 * @file Utility.hpp
 *
 * @brief Utility code
 */

#ifndef __UTILITY_HPP__
#define __UTILITY_HPP__

template <typename TL, typename TR> inline constexpr auto MIN(const TL& lhs, const TR& rhs)
{
  return (lhs < rhs) ? lhs : rhs;
}

template <typename TL, typename TR> inline constexpr auto MAX(const TL& lhs, const TR& rhs)
{
  return (lhs > rhs) ? lhs : rhs;
}

#endif
