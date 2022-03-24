#include <cstring>
#include <iostream>


int lgreylist(int argc, const char* argv[]) {
  std::cout << "XXX" << std::endl;

  return 0;
}

// int lgreyclean(int argc, const char* argv[]) {
//   return 0;
// }

int main(int argc, const char* argv[]) {
  if (!argc)
    return -1;

  const char* progname = strrchr(argv[0], '/');

  if (!progname)
    progname = argv[0];
  else
    progname++;

  if (!strcmp(progname, "lgreylist"))
    return lgreylist(argc, argv);
  // else if (!strcmp(argv[0], "lgreyclean"))
  //   return tgreyclean(argc, argv);

  return 0;
}
