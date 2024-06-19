#include "Exception.hpp"

#include <boost/math/special_functions/prime.hpp>

namespace cpp_template
{

  int get_nth_prime(int n)
  {
    namespace bm = boost::math;
    namespace b = boost;

    if (n < 0)
    {
      throw Exception("non-negative argument required");
    }

    if (static_cast<b::uint32_t>(n) > bm::max_prime)
    {
      throw Exception("argument less than " + std::to_string(bm::max_prime) +
                      " required");
    }

    return static_cast<int>(boost::math::prime(static_cast<unsigned>(n)));
  }

} // namespace cpp_template
