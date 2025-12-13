#include "ProductId.hpp"
#include "Utility.hpp"

#include <cmath>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<std::string>
ProductId::GenerateInvalidIds(const unsigned long long rangeMin, const unsigned long long rangeMax)
{
  if (rangeMax <= rangeMin)
  {
    throw std::invalid_argument{"Invalid range"};
  }

  const std::string strMin{std::to_string(rangeMin)};
  const std::string strMax{std::to_string(rangeMax)};

  const unsigned int charsMin = strMin.length();
  const unsigned int charsMax = strMax.length();

  if (charsMax < 2)
  {
    // Need at least double digits high side for any symmetry to possibly exist in range
    return std::vector<std::string>{};
  }

  const unsigned int powerMin = (charsMin + 1) / 2;
  const unsigned int powerMax = (charsMax + 1) / 2;

  // Note precedence:  10 ^ (powerMin - 1)
  const unsigned long long valMin = static_cast<decltype(valMin)>(std::pow(10, powerMin - 1));

  // Note precedence:  (10 ^ powerMax) - 1
  const unsigned long long valMax = static_cast<decltype(valMax)>(std::pow(10, powerMax)) - 1;

  // Container for ids
  std::vector<std::string> ids{};

  for (unsigned long long i = valMin; i <= valMax; ++i)
  {
    // Convert i to a string and append the string to itself to form the ID
    const std::string str{std::to_string(i)};
    const std::string id{str + str};

    // Skip IDs less than the range minimum
    if (static_cast<const unsigned long long>(std::stoull(id)) < rangeMin)
    {
      continue;
    }

    // Stop if ID exceeds range maximum
    if (static_cast<const unsigned long long>(std::stoull(id)) > rangeMax)
    {
      break;
    }

    // Add ID to container
    ids.push_back(id);
  }

  return ids;
}
