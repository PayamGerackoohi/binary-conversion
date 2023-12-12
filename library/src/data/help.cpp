#include "data/help.hpp"
#include "constants.hpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string makeHelp();

string help = makeHelp();

string makeHelp() {
  stringstream ss;
  ss << "Binary Conversion App - v" << VERSION << "\n"
     << "It simply converts file binaries using xor and a password.\n\n"
     << "Usage: ./binary-conversion [command] <arguments>\n\n"
     << "Available commands:\n"
     << "	h, help                          It shows the help manual\n"
     << "	v, version                       It shows the app version\n"
     << "	c, convert                       It converts the file using "
        "the password\n"
     << "\n"
     << "Available arguments:\n"
     << "	-i, --input                      The input file\n"
     << "	-o, --output                     The output file (if not "
        "provided, the "
     << "input file will\n"
     << "	                                 be overriden)\n"
     << "	-p, --password                   The conversion password. The "
        "default "
     << "value is 123 but,\n"
     << "	                                 it would be expanded to the "
     << "expanded-password-size.\n"
     << "	-e, --expanded-password-size     The desired password size "
        "after "
     << "expansion, in order to\n"
     << "	                                 make password longer and less "
     << "predictable.\n"
     << "	                                 The default value is 10.\n"
     << "\n"
     << "Samples:\n"
     << "	./binary-conversion\n"
     << "	./binary-conversion h\n"
     << "	./binary-conversion v\n"
     << "	./binary-conversion c -i data/in.txt; echo The file is "
        "overriden.\n"
     << "	./binary-conversion c -i data/in.txt -o data/out.txt -p "
        "password\n";
  return ss.str();
}

void Help::showHelp() {
  cout << help << endl;
  exit(0);
}

void Help::action() { showHelp(); }
