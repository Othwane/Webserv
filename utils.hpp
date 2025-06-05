#pragma once

#include "server/Server.hpp"

std::vector<std::string> split(const std::string &toSplit, std::string delimiter);
std::string trim(const std::string &str);
std::string normalizeUrl(const std::string &uri);