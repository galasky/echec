#ifndef		__PLATEAU_HPP__
#define		__PLATEAU_HPP__

#include	<iostream>
#include	"piece.hpp"

class		plateau
{
public:

  plateau();
  ~plateau();
  void		refresh(std::string &plateau);
  std::string	modifie();
  void		aff_info();
  int		valeur(plateau *p);
  bool		joue(int x, int y);
  piece		*_piece[8][8];
  piece		*_roi1;
  piece		*_roi2;
private:

};

#endif		/*__PLATEAU_HPP__*/
