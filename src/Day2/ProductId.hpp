/**
 * @copyright Copyright (c) 2025 eggebee6
 *
 * @file ProductId.hpp
 *
 * @brief An object representing a product ID
 */

#ifndef __PRODUCTID_HPP__
#define __PRODUCTID_HPP__

#include <string>
#include <vector>

/**
 * @brief Encapsulates a string containing the product ID
 */
class ProductId
{
public:
  static constexpr unsigned int MAX_ID_CHARS = 64; ///< Maximum number of characters in a product ID

  /**
   * @brief Construct a product ID from the given value
   *
   * @param id Unsigned integer with the value of the ID
   */
  ProductId(const unsigned long id) : m_id{std::to_string(id)} {}

  ProductId(const ProductId&) = default;
  ProductId& operator=(const ProductId&) = default;
  ProductId(ProductId&&) = default;
  ProductId& operator=(ProductId&&) = default;

  ~ProductId() {}

  /**
   * @brief Check if the product ID is valid
   *
   * @return True if the ID is valid, false otherwise
   */
  bool IsValid() const;

  inline const std::string& GetId() const { return m_id; }

  /**
   * @brief Return the ID as an unsigned integer
   *
   * This method does not handle exceptions encountered when converting the ID string
   *
   * @return Unsigned integer represented by the characters of the ID
   */
  inline unsigned long long ToInteger() const { return std::stoull(m_id); }

  /**
   * @brief Generate a collection of invalid IDs within a range
   *
   * @param rangeMin Minimum value of range (inclusive)
   * @param rangeMax Maximum value of range (inclusive)
   * @return Collection of invalid IDs within the specified range
   */
  static std::vector<std::string>
  GenerateInvalidIds(const unsigned long long rangeMin, const unsigned long long rangeMax);

private:
  std::string m_id; ///< Product ID
};

#endif
