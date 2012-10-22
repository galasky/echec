#include "pion.hpp"

pion::pion() : piece()
{
  _valeur = 100;
}

pion::~pion()
{

}

void	pion::calc_moov(plateau &p)
{
  int	x = _x, y = _y;

  if (_mine == 2)
    {
      if (y == 6)
	{
	  if (p._piece[y - 1][x]->_mine == 0 && p._piece[y - 2][x]->_mine == 0)
	    _zone[y - 2][x] = true;
	}
      if (y > 0)
	if (p._piece[y - 1][x]->_mine == 0)
	  _zone[y - 1][x] = true;
      if (y > 0 && x > 0)
	if (p._piece[y - 1][x - 1]->_mine == 1)
	  _zone[y - 1][x - 1] = true;
      if (y > 0 && x < 7)
	if (p._piece[y - 1][x + 1]->_mine == 1)
	  _zone[y - 1][x + 1] = true;
    }
  else if (_mine == 1)
    {
      if (y == 1)
        {
          if (p._piece[y + 1][x]->_mine == 0 && p._piece[y + 2][x]->_mine == 0)
            _zone[y + 2][x] = true;
        }
      if (y < 7)
	if (p._piece[y + 1][x]->_mine == 0)
	  _zone[y + 1][x] = true;
      if (y < 7 && x > 0)
	if (p._piece[y + 1][x - 1]->_mine == 2)
	  _zone[y + 1][x - 1] = true;
      if (y < 7 && x < 7)
	if (p._piece[y + 1][x + 1]->_mine == 2)
	  _zone[y + 1][x + 1] = true;
    }
}
