#include <stdlib.h>
#include "plateau.hpp"
#include "pion.hpp"
#include "tour.hpp"
#include "cavalier.hpp"
#include "fou.hpp"
#include "roi.hpp"
#include "reine.hpp"
#include "rien.hpp"

plateau::plateau()
{

}

plateau::~plateau()
{

}

void	add(std::string p, piece *_piece[8][8], int x, int y, piece *&_roi1, piece *&_roi2)
{
  if (p == "b")
    {
      _piece[y][x] = new tour();
      _piece[y][x]->_mine = 1;
      _piece[y][x]->_x = x;
      _piece[y][x]->_y = y;
    }
  else if (p == "c")
    {
      _piece[y][x] = new cavalier();
      _piece[y][x]->_mine = 1;
      _piece[y][x]->_x = x;
      _piece[y][x]->_y = y;
    }
  else if (p == "d")
    {
      _piece[y][x] = new fou();
      _piece[y][x]->_mine = 1;
      _piece[y][x]->_x = x;
      _piece[y][x]->_y = y;
    }
  else if (p == "f")
    {
      _piece[y][x] = new roi();
      _roi1 = _piece[y][x];
      _piece[y][x]->_mine = 1;
      _piece[y][x]->_x = x;
      _piece[y][x]->_y = y;
    }
  else if (p == "e")
    {
      _piece[y][x] = new reine();
      _piece[y][x]->_mine = 1;
      _piece[y][x]->_x = x;
      _piece[y][x]->_y = y;
    }
  else if (p == "a")
    {
      _piece[y][x] = new pion();
      _piece[y][x]->_mine = 1;
      _piece[y][x]->_x = x;
      _piece[y][x]->_y = y;
    }
  else if (p == "1")
    {
      _piece[y][x] = new pion();
      _piece[y][x]->_mine = 2;
      _piece[y][x]->_x = x;
      _piece[y][x]->_y = y;
    }
  else if (p == "2")
    {
      _piece[y][x] = new tour();
      _piece[y][x]->_mine = 2;
      _piece[y][x]->_x = x;
      _piece[y][x]->_y = y;
    }
  else if (p == "3")
    {
      _piece[y][x] = new cavalier();
      _piece[y][x]->_mine = 2;
      _piece[y][x]->_x = x;
      _piece[y][x]->_y = y;
    }
  else if (p == "4")
    {
      _piece[y][x] = new fou();
      _piece[y][x]->_mine = 2;
      _piece[y][x]->_x = x;
      _piece[y][x]->_y = y;
    }
  else if (p == "5")
    {
      _piece[y][x] = new reine();
      _piece[y][x]->_mine = 2;
      _piece[y][x]->_x = x;
      _piece[y][x]->_y = y;
    }
  else if (p == "6")
    {
      _piece[y][x] = new roi();
      _roi2 = _piece[y][x];
      _piece[y][x]->_mine = 2;
      _piece[y][x]->_x = x;
      _piece[y][x]->_y = y;
    }
  else
    {
      _piece[y][x] = new rien;
      _piece[y][x]->_mine = 0;
      _piece[y][x]->_x = x;
      _piece[y][x]->_y = y;
    }
}

void	plateau::refresh(std::string &plateau)
{
  int	w = 0, b = 0, x = 0, y = 0, i = 0;
  std::string fuck;

  while (plateau[i])
    {
      fuck = plateau[i];
      if (fuck == "\n")
	{
	  x = 0;
	  y++;
	  i++;
	}
      else
	{
	  if (plateau[i])
	    {
	      add(fuck, _piece, x, y, _roi1, _roi2);
	      x++;
	      i++;
	    }
	}
    }
}

std::string	plateau::modifie()
{
  std::string	str;
  int		x, y = 0;

  while (y < 8)
    {
      x = 0;
      while (x < 8)
	{
	  if (_piece[y][x]->_mine == 1)
	    {
	      if (_piece[y][x]->_valeur == 100)
		str += "a";
	      else if (_piece[y][x]->_valeur == 510)
		str += "b";
	      else if (_piece[y][x]->_valeur == 320)
		str += "c";
	      else if (_piece[y][x]->_valeur == 333)
		str += "d";
	      else if (_piece[y][x]->_valeur == 880)
		str += "e";
	      else if (_piece[y][x]->_valeur == 400)
		str += "f";
	    }
	  else if (_piece[y][x]->_mine == 2)
	    {
	      if (_piece[y][x]->_valeur == 100)
		str += "1";
	      else if (_piece[y][x]->_valeur == 510)
		str += "2";
	      else if (_piece[y][x]->_valeur == 320)
		str += "3";
	      else if (_piece[y][x]->_valeur == 333)
		str += "4";
	      else if (_piece[y][x]->_valeur == 880)
		str += "5";
	      else if (_piece[y][x]->_valeur == 400)
		str += "6";
	    }
	  else
	    str += " ";
	  x++;
	}
      str += "\n";
      y++;
    }
  return (str);
}

void	plateau::aff_info()
{
  int	x, y = 0;

  while (y < 8)
    {
      x = 0;
      while (x < 8)
	{
	  std::cout << _piece[y][x]->_mine;
	  x++;
	}
      std::cout << std::endl;
      y++;
    }
}

int	plateau::valeur(plateau *p)
{
  int	total = 0;
  int	x, y = 0;

  while (y < 8)
    {
      x = 0;
      while (x < 8)
	{
	  if (_piece[y][x]->_mine == 2)
	    total += _piece[y][x]->valeur(p);
	  else if (_piece[y][x]->_mine == 1)
	    total -= _piece[y][x]->valeur(p);
	  x++;
	}
      y++;
    }
  return (total);
}

bool	teste_echec(piece *_piece[8][8], int X, int Y, piece *_roi)
{
  int	x, y = 0;

  while (y < 8)
    {
      x = 0;
      while (x < 8)
	{
	  if (_piece[Y][X]->_zone[y][x] == true)
	    if (_roi->_x == x && _roi->_y == y)
	      return (true);
	  x++;
	}
      y++;
    }
  return (false);
}

void	cp_piece(plateau &ptm, piece *_piece[8][8])
{
  int   x, y = 0;

  while (y < 8)
    {
      x = 0;
      while (x < 8)
	{
	  ptm._piece[y][x] = _piece[y][x];
	  x++;
	}
      y++;
    }
}

bool	coup_permi(piece *_piece[8][8], int mine, piece *_roi1, piece *_roi2)
{
  int   x, y = 0;
  plateau	ptm;

  while (y < 8)
    {
      x = 0;
      while (x < 8)
        {
          if (_piece[y][x]->_mine == (mine == 1 ? 2 : 1))
            {
	      cp_piece(ptm, _piece);
	      ptm._roi1 = _roi1;
	      ptm._roi2 = _roi2;
	      _piece[y][x]->calc_moov(ptm);
	      if (_piece[y][x]->mise_en_echec(&ptm))
		return (false);
	    }
          x++;
        }
      y++;
    }
  return (true);
}

bool	plateau::joue(int X, int Y)
{
  int	x, y = 0;
  piece	*tmp;
  plateau p;

  cp_piece(p, _piece);
  p._roi1 = _roi1;
  p._roi2 = _roi2;

  while (y < 8)
    {
      x = 0;
      while (x < 8)
	{
	  if (_piece[Y][X]->_zone[y][x])
	    {
	      tmp = _piece[y][x];
	      _piece[y][x] = _piece[Y][X];
	      _piece[y][x]->_x = x;
	      _piece[y][x]->_y = y;
	      _piece[Y][X] = new rien();
	      
	      _piece[Y][X]->_mine = 0;
	      //	      if (coup_permi(_piece, _piece[y][x]->_mine, _roi1, _roi2))
	      delete tmp;
	      /*else
		{
		delete _piece[Y][X];
		_piece[Y][X] = _piece[y][x];
		_piece[Y][X]->_zone[y][x] = false;
		_piece[y][x] = tmp;
		return (false);
		}*/
	      return (true);
	    }
	  x++;
	}
      y++;
    }
}
