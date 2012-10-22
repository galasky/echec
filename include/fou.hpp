#ifndef __FOU_HPP__
#define __FOU_HPP__

#include "piece.hpp"
#include "plateau.hpp"

class   fou : public piece
{
public:
  fou();
  ~fou();
  void		calc_moov(plateau &p);

private:
};

#endif  /*__FOU_HPP__*/
