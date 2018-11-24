#include <iostream>

#include <plf_colony/plf_colony.h>

int colony_test()
{
  plf::colony<int> i_colony;

  // Insert 100 ints:
  for (int i = 0; i != 100; ++i)
  {
    i_colony.insert(i);
  }

  // Erase half of them:
  for (plf::colony<int>::iterator it = i_colony.begin(); it != i_colony.end(); ++it)
  {
    it = i_colony.erase(it);
  }

  // Total the remaining ints:
  int total = 0;

  for (plf::colony<int>::iterator it = i_colony.begin(); it != i_colony.end(); ++it)
  {
    total += *it;
  }

  std::cout << "Total: " << total << std::endl;
  std::cin.get();
  return 0;
}

int main (int argc, char* argv[])
{
  using namespace std;

  if (argc < 2)
  {
    cerr << "error: missing name" << endl;
    return 1;
  }

  cout << "Hello, " << argv[1] << '!' << endl;

  return colony_test();
}
