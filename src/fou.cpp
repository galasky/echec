#include "fou.hpp"

fou::fou() : piece()
{
  _valeur = 333;
}

fou::~fou()
{

}

void	fou::calc_moov(plateau &p)
{
  int x = _x, y = _y;

  if (_mine == 2)
    {
      while (x < 7 && y > 0 && p._piece[y - 1][x + 1]->_mine == 0)
	{
	  _zone[y - 1][x + 1] = true;
	  x++;
	  y--;
	}
      if (x < 7 && y > 0)
	if (p._piece[y - 1][x + 1]->_mine == 1)
	_zone[y - 1][x + 1] = true;
      x = _x;
      y = _y;
      while (x > 0 && y > 0 && p._piece[y - 1][x - 1]->_mine == 0)
	{
          _zone[y - 1][x - 1] = true;
          x--;
          y--;
        }
      if (x > 0 && y > 0)
	if (p._piece[y - 1][x - 1]->_mine == 1)
	  _zone[y - 1][x - 1] = true;
      x = _x;
      y = _y;
      while (x > 0 && y < 7 && p._piece[y + 1][x - 1]->_mine == 0)
        {
          _zone[y + 1][x - 1] = true;
          x--;
          y++;
        }
      if (x > 0 && y < 7)
	if (p._piece[y + 1][x - 1]->_mine == 1)
	  _zone[y + 1][x - 1] = true;
      x = _x;
      y = _y;
      while (x < 7 && y < 7 && p._piece[y + 1][x + 1]->_mine == 0)
	{
          _zone[y + 1][x + 1] = true;
          x++;
          y++;
	}
      if (x < 7 && y < 7)
	if (p._piece[y + 1][x + 1]->_mine == 1)
	  _zone[y + 1][x + 1] = true;
    }
  else if (_mine == 1)
    {
      while (x < 7 && y > 0 && p._piece[y - 1][x + 1]->_mine == 0)
	{
	  _zone[y - 1][x + 1] = true;
	  x++;
	  y--;
	}
      if (x < 7 && y > 0)
	if (p._piece[y - 1][x + 1]->_mine == 2)
	  _zone[y - 1][x + 1] = true;
      x = _x;
      y = _y;
      while (x > 0 && y > 0 && p._piece[y - 1][x - 1]->_mine == 0)
	{
          _zone[y - 1][x - 1] = true;
          x--;
          y--;
        }
      if (x > 0 && y > 0)
	if (p._piece[y - 1][x - 1]->_mine == 2)
	  _zone[y - 1][x - 1] = true;
      x = _x;
      y = _y;
      while (x > 0 && y < 7 && p._piece[y + 1][x - 1]->_mine == 0)
        {
          _zone[y + 1][x - 1] = true;
          x--;
          y++;
        }
      if (x > 0 && y < 7)
	if (p._piece[y + 1][x - 1]->_mine == 2)
	  _zone[y + 1][x - 1] = true;
      x = _x;
      y = _y;
      while (x < 7 && y < 7 && p._piece[y + 1][x + 1]->_mine == 0)
	{
          _zone[y + 1][x + 1] = true;
          x++;
          y++;
	}
      if (x < 7 && y  < 7)
	if (p._piece[y + 1][x + 1]->_mine == 2)
	  _zone[y + 1][x + 1] = true;
    }
}
