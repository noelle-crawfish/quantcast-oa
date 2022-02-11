#include "cookie_data.h"

/* parseCookieData(std::map<std::string, int> &cookies, std::fstream &file, std::string day)
 *  DESCRIPTION: Populates a map of cookies to num of occurences from a file
 *  OUTPUTS: returns -1 on error, 0 on success
 *  SIDE EFFECTS: Populates cookies
 */
int parseCookieData(std::map<std::string, int> &cookies, std::fstream &file, std::string day) {
  std::string line, date;

  file >> line;
  // Ensure CSV file has expected format
  if(line.compare("cookie,timestamp")) {
    std::cout << "Bad input file.\n";
    return -1;
  }

  while(file >> line) {
    // parse date
    date = line.substr(line.find(',')+1, line.length());
    line = line.substr(0, line.find(','));
    // if on correct day or no day is provided, add to map
    if(!date.substr(0, 10).compare(day) || !day.compare("")) {
      if(cookies.find(line) != cookies.end()) cookies[line] += 1;
      else cookies[line] = 1;
    }
  }
  return 0;
}

/* getMostActive(std::map<std::string, int> &cookies, std::vector<std::string> &mostActive)
 *  DESCRIPTION: Finds the most active cookies in the map
 *  OUTPUTS: None
 *  SIDE EFFECTS: Populates mostActive
 */
void getMostActive(std::map<std::string, int> &cookies, std::vector<std::string> &mostActive) {
  if(!cookies.size()) {
    std::cout << "No cookies matching selected date\n";
    return;
  }

  int maxCount = 0;
  for(auto it = cookies.begin(); it != cookies.end(); it++) {
    if(it->second > maxCount) {
      maxCount = it->second;
      mostActive.clear();
      mostActive.push_back(it->first);
    } else if(it->second == maxCount) mostActive.push_back(it->first);
  }
}

std::vector<std::string> getResults(std::string inputFile, std::string date, int silent) {
  std::map<std::string, int> cookies;
  std::vector<std::string> mostActive;
  std::fstream inputData;
  inputData.open(inputFile, std::fstream::in);
  if(parseCookieData(cookies, inputData, date) == -1) return mostActive;

  getMostActive(cookies, mostActive);
  if(!silent) {
    for(auto it = mostActive.begin(); it != mostActive.end(); it++) 
      std::cout << *it << "\n";
  }

  return mostActive;
}
