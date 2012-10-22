#ifndef __ROI_HPP__
#define __ROI_HPP__

#include "piece.hpp"
#include "plateau.hpp"

class   roi : public piece
{
public:
  roi();
  ~roi();
  void		calc_moov(plateau &p);

private:
};

#endif  /*__ROI_HPP__*/
