#include "Range.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace day2
{

Range Range::FromString(const std::string& str)
{
  constexpr char ID_SEPARATOR = '-';

  constexpr unsigned int BUFFER_LEN = 64;
  char bufferFirst[BUFFER_LEN];
  char bufferLast[BUFFER_LEN];

  std::istringstream strIn{str};

  strIn.get(bufferFirst, BUFFER_LEN, ID_SEPARATOR); // Get first ID
  strIn.get();                                      // Discard delimeter
  strIn.get(bufferLast, BUFFER_LEN);                // Get second ID

  unsigned long long firstId = 0;
  unsigned long long lastId = 0;

  try
  {
    firstId = std::stoull(bufferFirst);
  }
  catch (...)
  {
    throw std::runtime_error{"Exception while converting first ID"};
  }

  try
  {
    lastId = std::stoull(bufferLast);
  }
  catch (...)
  {
    throw std::runtime_error{"Exception while converting last ID"};
  }

  return Range{firstId, lastId};
}

} // namespace day2
