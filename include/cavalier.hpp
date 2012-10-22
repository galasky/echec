#ifndef __CAVALIER_HPP__
#define __CAVALIER_HPP__

#include "piece.hpp"
#include "plateau.hpp"

class   cavalier : public piece
{
public:
  cavalier();
  ~cavalier();
  void		calc_moov(plateau &p);

private:
};

#endif  /*__CAVALIER_HPP__*/
