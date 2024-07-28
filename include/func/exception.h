#ifndef CLASSFUNCTION_EXCEPTION_H_
#define CLASSFUNCTION_EXCEPTION_H_

#include <exception>
#include <string>
namespace charlotte {

namespace exception {
  class Exception : public std::exception {
    private:
      std::string where_;
      mutable std::string msg_;
    public:

    Exception(const std::string& where ) : where_{where}, msg_{} {}
    virtual const char* what() const noexcept override {
      msg_.clear();
      msg_ += "IN ";
      msg_ += where_;
      msg_ += ": ";
      msg_ += this->type_description();
      msg_ += "!";
    return msg_.c_str();
    }
    virtual std::string type_description() const = 0;
  };

}

}
