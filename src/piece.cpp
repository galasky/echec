#include "piece.hpp"
#include "plateau.hpp"

piece::piece()
{
  int	x, y = 0;

  while (y < 8)
    {
      x = 0;
      while (x < 8)
	{
	  _zone[y][x] = false;
	  x++;
	}
      y++;
    }
}

piece::~piece()
{

}

void	piece::set(int x, int y)
{
  _x = x;
  _y = y;
}

void	piece::info()
{
  
}

void	piece::calc_moov(plateau &p)
{
  std::cout << "NOOOOO\n";
}


int	piece::valeur(plateau *p)
{
  int	x, y = 0;

  _valeurTempo = _valeur;
  while (y < 8)
    {
      x = 0;
      while (x < 8)
	{
	  if (_zone[y][x])
	    {
	      if (p->_piece[y][x]->_mine == 0)
		_valeurTempo += 1;
	      else if (p->_piece[y][x]->_mine == 1)
		_valeurTempo += p->_piece[y][x]->valeurInitial();
	    }	      
	  x++;
	}
      y++;
    }
  return (_valeurTempo);
}

int	piece::valeurInitial() const
{
  return (_valeur);
}

bool	piece::mise_en_echec(plateau *pf)
{
  int	x, y = 0;

  while (y < 8)
    {
      x = 0;
      while (x < 8)
	{
	  if (_zone[y][x] == true)
	    {
	      if (_mine == 2)
		{
		  if (pf->_roi1->_x == x && pf->_roi1->_y == y)
		    return (true);
		}
	      else if (_mine == 1)
		{
		  if (pf->_roi2->_x == x && pf->_roi2->_y == y)
		    return (true);
		}
	    }  
	  x++;
	}
      y++;
    }
  return (false);
}

  void	piece::aff_zone() const
  {
    int	x, y = 0;

    while (y < 8)
      {
	x = 0;
	while (x < 8)
	  {
	    if (_zone[y][x] == true)
	      std::cout << 1;
	    else
	      std::cout << 0;
	    x++;
	  }
	std::cout << std::endl;
	y++;
      }
  }

  bool	piece::jouable()
  {
    int	x, y = 0;

    while (y < 8)
      {
	x = 0;
	while (x < 8)
	  {
	    if (_zone[y][x] == true)
	      return (true);
	    x++;
	  }
	y++;
      }
    return (false);
  }

  void	piece::clean()
  {
    int	x, y = 0;

    while (y < 8)
      {
	x = 0;
	while (x < 8)
	  {
	    _zone[y][x] = false;
	    x++;
	  }
	y++;
      }
  }
