//
// Created by ffernandoalves on 16/11/2023.
//

#include "exception.hpp"

void ExceptionBase::setMessage(const std::string& msg) {
    exception_msg = msg;
}

void ExceptionBase::showMessage() {
    std::cerr << exception_msg << std::endl;
}

void GLException::showMessage() {
}