#ifndef _EXCEPTIONS_HPP
#define _EXCEPTIONS_HPP

#include <stdexcept>

class end_of_file : public std::exception {};

class unknown_color : public std::exception {
public:
    unknown_color(const std::string & name):
        s{std::string{ "entity file contained unknown color [" }+ name + "]"}
    {}
    
    const char * what() const noexcept override {
        return s.c_str();
    }
private:
    std::string s;
};

class invalid_formatting : public std::exception {
public:
    invalid_formatting(const char & c):
        s{std::string {"entity file contained invalid formatting at character \""} + c + "\" - use (x,y) for twodimensional coordinates and sizes"}
    {}
    const char * what() const noexcept override {
        return s.c_str();
    }
private:
    std::string s;
};

class invalid_shape : public std::exception {
public:
    invalid_shape(const std::string & name):
        s{std::string{ "shape [" }+ name + "] does not exist"}
    {}
    
    const char * what() const noexcept override {
        return s.c_str();
    }
private:
    std::string s;
};

class file_not_found : public std::exception {
public:
    file_not_found(const std::string & name):
        s{std::string{ "couldn't find or open file [" }+ name + "]"}
    {}
    
    const char * what() const noexcept override {
        return s.c_str();
    }
private:
    std::string s;
};

#endif
