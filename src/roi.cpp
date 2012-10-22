#include "roi.hpp"

roi::roi() : piece()
{
  _valeur = 400;
}

roi::~roi()
{

}

void	roi::calc_moov(plateau &p)
{
  int x = _x, y = _y;

  if (_mine == 2)
    {
      if (x < 7)
	if (p._piece[y][x + 1]->_mine != 2)
	  _zone[y][x + 1] = true;
      if (x > 0)
	if (p._piece[y][x - 1]->_mine != 2)
          _zone[y][x - 1] = true;
      if (y < 7)
	if (p._piece[y + 1][x]->_mine != 2)
          _zone[y + 1][x] = true;
      if (y > 0)
	if (p._piece[y - 1][x]->_mine != 2)
          _zone[y - 1][x] = true;

      if (x < 7 && y > 0)
	if (p._piece[y - 1][x + 1]->_mine != 2)
          _zone[y - 1][x + 1] = true;
      if (x < 7 && y < 7)
	if (p._piece[y + 1][x + 1]->_mine != 2)
          _zone[y + 1][x + 1] = true;
      if (x > 0 && y > 0)
	if (p._piece[y - 1][x - 1]->_mine != 2)
          _zone[y - 1][x - 1] = true;
      if (x > 0 && y < 7)
	if (p._piece[y + 1][x - 1]->_mine != 2)
          _zone[y + 1][x - 1] = true;
    }
  else if (_mine == 1)
    {
      if (x < 7)
	if (p._piece[y][x + 1]->_mine != 1)
          _zone[y][x + 1] = true;
      if (x > 0)
	if (p._piece[y][x - 1]->_mine != 1)
          _zone[y][x - 1] = true;
      if (y < 7)
	if (p._piece[y + 1][x]->_mine != 1)
          _zone[y + 1][x] = true;
      if (y > 0)
	if (p._piece[y - 1][x]->_mine != 1)
          _zone[y - 1][x] = true;

      if (x < 7&& y > 0)
	if (p._piece[y - 1][x + 1]->_mine != 1)
          _zone[y - 1][x + 1] = true;
      if (x < 7 && y < 7)
        if (p._piece[y + 1][x + 1]->_mine != 1)
          _zone[y + 1][x + 1] = true;
      if (x > 0 && y > 0)
        if (p._piece[y - 1][x - 1]->_mine != 1)
          _zone[y - 1][x - 1] = true;
      if (x > 0 && y < 7)
        if (p._piece[y + 1][x - 1]->_mine != 1)
          _zone[y + 1][x - 1] = true;
    }
}
