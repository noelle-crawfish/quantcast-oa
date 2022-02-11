#include <unistd.h>

#include "cookie_data.h"

int main(int argc, char* argv[]) {
  std::string inputFile;
  std::string date = "";

  /* Parse all command line arguments */
  int flag;
  while((flag = getopt(argc, argv, "d:h")) != -1) {
    switch(flag) {
      case 'd': // flag to set a date
        if(optarg) date = optarg;
        else return 0;
        break;
      case 'h': // flag to print usage info
        std::cout << "Usage: ./most_active_cookie [log file] -d YYYY-MM-DD\n";
        return 0;
    }
  }

  if(optind-argc != -1) { // ensure input file is provided
    std::cout << "Usage: ./most_active_cookie [log file] -d YYYY-MM-DD\n";
    return 0;
  }
  inputFile = argv[optind]; // get input file


  /* Open and parse CSV file */
  std::map<std::string, int> cookies;
  std::fstream inputData;
  inputData.open(inputFile, std::fstream::in);
  if(parseCookieData(cookies, inputData, date) == -1) return 0;

  std::vector<std::string> mostActive;
  getMostActive(cookies, mostActive);
  for(auto it = mostActive.begin(); it != mostActive.end(); it++) 
    std::cout << *it << "\n";

  return 0;
}
