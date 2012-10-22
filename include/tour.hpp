#ifndef __TOUR_HPP__
#define __TOUR_HPP__

#include "piece.hpp"
#include "plateau.hpp"

class   tour : public piece
{
public:
  tour();
  ~tour();
  void		calc_moov(plateau &p);

private:
};

#endif  /*__TOUR_HPP__*/
