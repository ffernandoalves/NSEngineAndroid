//
// Created by ffernandoalves on 16/11/2023.
//

#ifndef NSENGINE_EXCEPTION_HPP
#define NSENGINE_EXCEPTION_HPP

#include "debug.hpp"

class ExceptionBase {
private:
    std::string exception_msg;
public:
    virtual void setMessage(const std::string&);
    virtual void showMessage(void);
};


class GLException: public ExceptionBase {
public:
    void showMessage() override;
};

#endif //NSENGINE_EXCEPTION_HPP