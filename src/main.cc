#include <cstring>
#include <iostream>
#include <sstream>
#include <argfu.hh>

unsigned int convert_timespan(const std::string& value) {
  std::istringstream iss(value);
  unsigned int ret = 0;
  while(iss) {
    unsigned int num = 0;
    char mod = 's';
    iss >> num >> mod;
    switch(tolower(mod)) {
      case 'y':  ret += num * 31536000;  break;
      case 'w':  ret += num * 604800;    break;
      case 'd':  ret += num * 86400;     break;
      case 'h':  ret += num * 3600;      break;
      case 'm':  ret += num * 60;        break;
      case 's':  ret += num;             break;
    }
  }
  return ret;
}


int lgreylist(const std::string& progname, const argfu::arglist& args) {
  std::string   database   = "CONFIG_TGREY_DB";
  unsigned int  delay      = 0; // tgrey::convert_timespan("5m");
  unsigned int  timeout    = 0; // tgrey::convert_timespan("7d");

  try {
    argfu::parse(progname, args)
      .option("database", 'D', database)
          // .help("Path to use as the database for storing greylisting "
          //       "triplets. The user this process is run under needs "
          //       "read and write permissions and if it not already "
          //       "exists needs to be allowed to create it.")

      .option("delay", 'd', delay)
          // .converter(convert_timespan)
          // .help("Delta between the time a triplet is first recorded "
          //       "and mail for it rejected and the time the first retry "
          //       "message for it is allowed through.")

      .option("timeout", 't', timeout)
          // .converter(convert_timespan)
          // .help("Any delivery made for triplets, which are older than "
          //       "this value but at the same time not cleared for "
          //       "delivery yet is rejected and the triplet reset.")

      ;
  }
  catch (...) {

  }

  return 0;
}

int main(int argc, const char* argv[]) {
  return argfu::dispatch
    ("lgreylist",  lgreylist)
    ("lgreyclean", lgreylist)
    (argc, argv)
  ;
}
