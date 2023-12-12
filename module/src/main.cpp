#include "main.hpp"

#include "constants.hpp"
#include "data/actor.hpp"
#include "data/command.hpp"
#include "data/converter.hpp"
#include "data/help.hpp"
#include "data/rune.hpp"
#include "util/arg-parser.hpp"
#include "util/color.hpp"
#include "util/password-util.hpp"

using std::cerr;
using std::cout;
using std::endl;
using std::initializer_list;
using std::make_unique;
using std::string;

int main(int argc, const char **argv) {
  Settings settings;
  setConfig(argc, argv, settings);
  checkCommands(&settings);
  return 0;
}

void showVersion() {
  cout << "Binary Conversion App - v" << VERSION << endl;
  exit(0);
}

void setConfig(int argc, const char **argv, Settings &settings) {
  ArgParser parser;
  using args = initializer_list<string>;
  Help help;
  parser.setDefault(std::move(help));
  parser.addKey(make_unique<Key<void>>(args{"h", "help"}, std::move(help)));
  parser.addKey(make_unique<Key<void>>(args{"v", "version"}, showVersion));
  parser.addKey(make_unique<Key<void>>(
      args{"c", "convert"}, [&]() { settings.command = Command::Convert; }));
  parser.addKey(make_unique<Key<string>>(
      args{"-i", "--input"}, [&](string value) { settings.input = value; }));
  parser.addKey(make_unique<Key<string>>(
      args{"-o", "--output"}, [&](string value) { settings.output = value; }));
  parser.addKey(
      make_unique<Key<string>>(args{"-p", "--password"}, [&](string value) {
        settings.password = value;
      }));
  parser.addKey(make_unique<Key<int>>(
      args{"-e", "--expanded-password-size"},
      [&](int value) { settings.expandedPasswordSize = value; }));
  parser.parse(argc, argv);
}

void convert(Settings *settings) {
  Converter converter(settings);
  converter.convert();
}

void checkCommands(Settings *settings) {
  switch (settings->command) {
  case Command::Convert:
    convert(settings);
    break;
  default:
    cerr << payam::red << "Invalid command: '" << settings->command << "'"
         << endl;
    exit(1);
  }
}
