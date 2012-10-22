#include "serveur.hpp"
#include "client.hpp"
#include "my_ia.hpp"

void		inverse(std::string &plateau)
{
  std::string	save;
  char		c;
  int	i = 70;

  while (i >= 0)
    {
      c = plateau[i];
      if (c >= '1' && c <= '9')
	save += c + 'a' - '1';
      else if (c >= 'a' && c <= 'f')
	save += c - ('a' - '1');
      else
	save += c;
      i--;
    }
  save += '\n';
  plateau = save;
}

void		is_serveur()
{
  serveur	serveur;
  std::string	plateau;

  plateau += "bcdf dcb\n";
  plateau += "aaaaaaaa\n";
  plateau += "        \n";
  plateau += "      e \n";
  plateau += "      6 \n";
  plateau += "        \n";
  plateau += "11111111\n";
  plateau += "234 5432\n";

  if (serveur.input() == "ready?")
    std::cout << "client connected" << std::endl;
  serveur.output("ready!");
  if (serveur.input() == "plateau")
    serveur.output(plateau);
  plateau = serveur.input();

  while (1)
    {
      my_ia(plateau);
      inverse(plateau);
      serveur.output(plateau);
      plateau = serveur.input();
    }
}

void		is_client(const char *ip)
{
  client        client(ip);
  std::string	plateau;

  client.output("ready?");
  if (client.input() == "ready!")
    std::cout << "connected to : " << ip << std::endl;
  client.output("plateau");
  plateau = client.input();
  client.output(plateau);

  while (1)
    {
      plateau = client.input();
      my_ia(plateau);
      inverse(plateau);
      client.output(plateau);
    }
}

int		main(int ac, char **av)
{
  if (ac <= 1)
    { 
      std::cout << "serveur lunched" << std::endl;
      is_serveur();
    } 
  else if (ac == 2)
    {
      is_client(av[1]);
    }
  return (0);
}
