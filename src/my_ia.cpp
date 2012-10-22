#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "arbre.hpp"

void	my_ia(std::string &result)
{
  static int	n;
  arbre		arbre;
  plateau	p;

  system("clear");
  std::cout << result;
  arbre.start(2, result);
  arbre.choice(result);
  sleep(1);
  system("clear");
  std::cout << result;
  n++;
}
