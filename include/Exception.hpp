#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <stdexcept>

namespace cpp_template
{

  class Exception : public std::runtime_error
  {
  public:
    explicit Exception(const std::string &arg) : std::runtime_error(arg) {};
  };

} // namespace cpp_template

#endif // _EXCEPTION_H_
