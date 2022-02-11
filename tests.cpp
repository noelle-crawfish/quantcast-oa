#include "cookie_data.h"

#include <set>

void noDateTest() {
  bool pass = 1;
  std::vector<std::string> results;
  std::set<std::string> resultSet;

  results = getResults("data.csv", "", 1);
  for(auto it = results.begin(); it != results.end(); it++) resultSet.insert(*it);

  std::cout << "No Date Test: ";

  if(resultSet.size() != 3) pass = 0;
  if(!resultSet.count("4sMM2LxV07bPJzwf")) pass = 0;
  if(!resultSet.count("AtY0laUfhglK3lC7")) pass = 0;
  if(!resultSet.count("SAZuXPGUrfbcn5UA")) pass = 0;

  if(pass) std::cout << "PASS\n";
  else std::cout << "FAIL\n";
}

void generalTest1() {
  bool pass = 1;
  std::vector<std::string> results;
  std::set<std::string> resultSet;

  results = getResults("data.csv", "2018-12-08", 1);
  for(auto it = results.begin(); it != results.end(); it++) resultSet.insert(*it);

  std::cout << "General Test 1: ";

  if(resultSet.size() != 3) pass = 0;
  if(!resultSet.count("4sMM2LxV07bPJzwf")) pass = 0;
  if(!resultSet.count("SAZuXPGUrfbcn5UA")) pass = 0;
  if(!resultSet.count("fbcn5UAVanZf6UtG")) pass = 0;

  if(pass) std::cout << "PASS\n";
  else std::cout << "FAIL\n";
}

void generalTest2() {
  bool pass = 1;
  std::vector<std::string> results;
  std::set<std::string> resultSet;

  results = getResults("data.csv", "2018-12-07", 1);
  for(auto it = results.begin(); it != results.end(); it++) resultSet.insert(*it);

  std::cout << "General Test 2: ";

  if(!resultSet.size() == 1) pass = 0;
  if(!resultSet.count("4sMM2LxV07bPJzwf")) pass = 0;

  if(pass) std::cout << "PASS\n";
  else std::cout << "FAIL\n";
}

void generalTest3() {
  bool pass = 1;
  std::vector<std::string> results;
  std::set<std::string> resultSet;

  results = getResults("data.csv", "2018-12-09", 1);
  for(auto it = results.begin(); it != results.end(); it++) resultSet.insert(*it);

  std::cout << "General Test 3: ";

  if(resultSet.size() != 1) pass = 0;
  if(!resultSet.count("AtY0laUfhglK3lC7")) pass = 0;

  if(pass) std::cout << "PASS\n";
  else std::cout << "FAIL\n";
}

void noCookiesTest() {
  bool pass = 1;
  std::vector<std::string> results;

  results = getResults("data.csv", "2020-12-09", 1);
  if(results.size() != 0) pass = 0;

  std::cout << "No Cookies Returned Test: ";
  if(pass) std::cout << "PASS\n";
  else std::cout << "FAIL\n";
}


int main() {
  noDateTest();
  generalTest1();
  generalTest2();
  generalTest3();
  noCookiesTest();

  return 0;
}
