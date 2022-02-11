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
  getResults(inputFile, date, 0);

  return 0;
}
