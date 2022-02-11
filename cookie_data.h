#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int parseCookieData(std::map<std::string, int> &cookies, std::fstream &file, std::string day);
void getMostActive(std::map<std::string, int> &cookies, std::vector<std::string> &mostActive);
