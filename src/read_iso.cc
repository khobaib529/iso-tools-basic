#include <cstddef>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include "iso-tools-basic/primary-volume-descriptor.h"

using namespace std;

// Might represent a key-value pair or just a key --print-raw-pvd.
class KeyValuePair {
 public:
  KeyValuePair(string kvp) {
    size_t pos = kvp.find('=');
    key_ = kvp.substr(0, pos);
    value_ = kvp.substr(pos + 1, kvp.size());
  }

  string key() { return key_; }
  string value() { return value_; }
  bool operator<(const KeyValuePair& other) const { return key_ < other.key_; }

 private:
  string key_;
  string value_;
};

void PrintUsage(const char* program_name) {
  cout << "Usage: " << program_name << " --path=<iso_file_path>\n";
}
namespace iso_tools {
// Runs the iso_read program with given iso_path and options
void RunISORead(string iso_path, set<KeyValuePair>& options) {
  FILE* fp = fopen(iso_path.data(), "rb");
  PrimaryVolumeDescriptor pvd;
  fread(&pvd, sizeof(PrimaryVolumeDescriptor), 1, fp);
  if (options.count(KeyValuePair("--print-raw-pvd"))) {
    pvd.PrintRaw();
  }
}
}  // namespace iso_tools

int main(int argc, char* argv[]) {
  string iso_path;
  set<KeyValuePair> options;
  for (int i = 1; i < argc; i++) {
    KeyValuePair kvp(argv[i]);
    if (kvp.key() == "--path") {
      iso_path = kvp.value();
      continue;
    }
    // only key is present in case of a option.
    options.insert(kvp);
  }
  if (iso_path.length() == 0) {
    PrintUsage(argv[0]);
    return 1;
  } else {
    iso_tools::RunISORead(iso_path, options);
  }
  return 0;
}