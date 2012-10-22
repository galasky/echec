#include "reine.hpp"

reine::reine() : piece()
{
  _valeur = 880;
}

reine::~reine()
{

}

void	reine::calc_moov(plateau &p)
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


      x = _x;
      y = _y;
      while (x < 7 && p._piece[y][x + 1]->_mine == 0)
        {
          _zone[y][x + 1] = true;
          x++;
        }
      if (x < 7)
        if (p._piece[y][x + 1]->_mine == 1)
          _zone[y][x + 1] = true;
      x = _x;
      while (x > 0 && p._piece[y][x - 1]->_mine == 0)
        {
          _zone[y][x - 1] = true;
          x--;
        }
      if (x > 0)
        if (p._piece[y][x - 1]->_mine == 1)
          _zone[y][x - 1] = true;
      x = _x;

      while (y < 7 && p._piece[y + 1][x]->_mine == 0)
        {
          _zone[y + 1][x] = true;
          y++;
        }
      if (y < 7)
        if (p._piece[y + 1][x]->_mine == 1)
          _zone[y + 1][x] = true;
      y = _y;
      while (y > 0 && p._piece[y - 1][x]->_mine == 0)
        {
          _zone[y - 1][x] = true;
          y--;
        }
      if (y > 0)
        if (p._piece[y - 1][x]->_mine == 1)
          _zone[y - 1][x] = true;
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


      x = _x;
      y = _y;
      while (x < 7 && p._piece[y][x + 1]->_mine == 0)
        {
          _zone[y][x + 1] = true;
          x++;
        }
      if (x < 7)
        if (p._piece[y][x + 1]->_mine == 2)
          _zone[y][x + 1] = true;
      x = _x;
      while (x > 0 && p._piece[y][x - 1]->_mine == 0)
        {
          _zone[y][x - 1] = true;
          x--;
        }
      if (x > 0)
        if (p._piece[y][x - 1]->_mine == 2)
          _zone[y][x - 1] = true;
      x = _x;

      while (y < 7 && p._piece[y + 1][x]->_mine == 0)
        {
          _zone[y + 1][x] = true;
          y++;
        }
      if (y < 7)
        if (p._piece[y + 1][x]->_mine == 2)
	  _zone[y + 1][x] = true;
      y = _y;
      while (y > 0 && p._piece[y - 1][x]->_mine == 0)
        {
          _zone[y - 1][x] = true;
          y--;
        }
      if (y > 0)
        if (p._piece[y - 1][x]->_mine == 2)
          _zone[y - 1][x] = true;
    }
}
