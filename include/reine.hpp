#ifndef __REINE_HPP__
#define __REINE_HPP__

#include "piece.hpp"
#include "plateau.hpp"

class   reine : public piece
{
public:
  reine();
  ~reine();
  void		calc_moov(plateau &p);

private:
};

#endif  /*__REINE_HPP__*/
