/**
 * @copyright Copyright (c) 2025 eggebee6
 *
 * @file Range.hpp
 *
 * @brief An object representing a range of IDs
 */

#ifndef __RANGE_HPP__
#define __RANGE_HPP__

#include <string>

namespace day2
{

/**
 * @brief Simple object holding the first and last IDs in a range
 */
class Range
{
public:
  constexpr Range(const unsigned long long firstId, const unsigned long long lastId)
      : m_firstId(firstId), m_lastId(lastId)
  {
    // Swap IDs if the first ID is greater than the last ID
    if (m_firstId > m_lastId)
    {
      auto temp = m_firstId;
      m_firstId = m_lastId;
      m_lastId = temp;
    }
  }

  Range(const Range&) = default;
  Range& operator=(const Range&) = default;
  Range(Range&&) = default;
  Range& operator=(Range&&) = default;

  ~Range() {}

  inline unsigned long long GetFirstId() const { return m_firstId; }

  inline unsigned long long GetLastId() const { return m_lastId; }

  static Range FromString(const std::string& str);

private:
  unsigned long long m_firstId;
  unsigned long long m_lastId;
};

} // namespace day2

#endif
