#ifndef		__PION_HPP__
#define		__PION_HPP__

#include	"piece.hpp"
#include	"plateau.hpp"

class		pion : public piece
{
public:
  pion();
  ~pion();
  void		calc_moov(plateau &p);

private:
};

#endif		/*__PION_HPP__*/
