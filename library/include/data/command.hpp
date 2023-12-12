#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <ostream>
#include <string>

enum class Command { None, Convert };

std::string toString(const Command &command);

std::ostream &operator<<(std::ostream &os, const Command &command);

#endif
