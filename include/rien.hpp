#ifndef	__RIEN_HPP__
#define	__RIEN_HPP__

#include "piece.hpp"
#include "plateau.hpp"

class	rien : public piece
{
public:
  rien();
  ~rien();
  void	calc_moov(plateau &p);
};

#endif
