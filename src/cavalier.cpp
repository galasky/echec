#include "cavalier.hpp"

cavalier::cavalier() : piece()
{
  _valeur = 320;
}

cavalier::~cavalier()
{

}

void	cavalier::calc_moov(plateau &p)
{
  int x = _x, y = _y;

  if (_mine == 2)
    {
      if (y > 1 && x < 7)
	if (p._piece[y - 2][x + 1]->_mine != 2)
	  _zone[y - 2][x + 1] = true;
      if (y > 1 && x > 0)
        if (p._piece[y - 2][x - 1]->_mine != 2)
	  _zone[y - 2][x - 1] = true;
      if (y < 6 && x < 7)
        if (p._piece[y + 2][x + 1]->_mine != 2)
          _zone[y + 2][x + 1] = true;
      if (y < 6 && x > 0)
        if (p._piece[y + 2][x - 1]->_mine != 2)
          _zone[y + 2][x - 1] = true;

      if (y > 0 && x < 6)
        if (p._piece[y - 1][x + 2]->_mine != 2)
          _zone[y - 1][x + 2] = true;
      if (y > 0 && x > 1)
        if (p._piece[y - 1][x - 2]->_mine != 2)
          _zone[y - 1][x - 2] = true;
      if (y < 7 && x < 6)
        if (p._piece[y + 1][x + 2]->_mine != 2)
          _zone[y + 1][x + 2] = true;
      if (y < 7 && x > 1)
        if (p._piece[y + 1][x - 2]->_mine != 2)
          _zone[y + 1][x - 2] = true;
    }
  else if (_mine == 1)
    {
      if (y > 1 && x < 7)
	if (p._piece[y - 2][x + 1]->_mine != 1)
	  _zone[y - 2][x + 1] = true;
      if (y > 1 && x > 0)
        if (p._piece[y - 2][x - 1]->_mine != 1)
	  _zone[y - 2][x - 1] = true;
      if (y < 6 && x < 7)
        if (p._piece[y + 2][x + 1]->_mine != 1)
          _zone[y + 2][x + 1] = true;
      if (y < 6 && x > 0)
        if (p._piece[y + 2][x - 1]->_mine != 1)
          _zone[y + 2][x - 1] = true;

      if (y > 0 && x < 6)
        if (p._piece[y - 1][x + 2]->_mine != 1)
          _zone[y - 1][x + 2] = true;
      if (y > 0 && x > 1)
        if (p._piece[y - 1][x - 2]->_mine != 1)
          _zone[y - 1][x - 2] = true;
      if (y < 7 && x < 6)
        if (p._piece[y + 1][x + 2]->_mine != 1)
          _zone[y + 1][x + 2] = true;
      if (y < 7 && x > 1)
        if (p._piece[y + 1][x - 2]->_mine != 1)
          _zone[y + 1][x - 2] = true;
    }
}
