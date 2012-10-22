#ifndef	__ARBRE_HPP__
#define	__ARBRE_HPP__

#include <iostream>
#include "plateau.hpp"

  typedef struct s_noeud
  {
    plateau		p;
    int			valeur;
    struct s_noeud	*chil;
    struct s_noeud	*prev;
    struct s_noeud	*next;
  }		t_noeud;

class	arbre
{
public:
  arbre();
  ~arbre();
  void	start(int profondeur, std::string plateau);
  void	choice(std::string &result);
private:
  t_noeud	*_n;
};

#endif	/*__ARBRE_HPP__*/
