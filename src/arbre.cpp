#include "arbre.hpp"
#include <stdlib.h>
#include <unistd.h>

arbre::arbre()
{

}

void	delete_arbre(t_noeud *n)
{
  t_noeud	*tmp;

  while (n != NULL)
    {
      if (n->chil != NULL)
	{
	  delete_arbre(n->chil);
	  n->chil = NULL;
	}
      tmp = n;
      n = n->next;
      if (tmp != NULL)
	delete tmp;
    }
}

arbre::~arbre()
{
  delete_arbre(_n);
}

void    calc_moov(plateau &p, int gen)
{
  int   x, y = 0;

  while (y < 8)
    {
      x = 0;
      while (x < 8)
        {
	  if (p._piece[y][x]->_mine == (gen == 1 ? 2 : 1))
	    p._piece[y][x]->calc_moov(p);
	  x++;
        }
      y++;
    }
}

void    calc_moov(plateau &p)
{
  int   x, y = 0;

  while (y < 8)
    {
      x = 0;
      while (x < 8)
        {
	  p._piece[y][x]->calc_moov(p);
          x++;
        }
      y++;
    }
}

void	copy_zone(t_noeud *nev, t_noeud *n, int X, int Y)
{
  int  	x, y = 0;

  while (y < 8)
    {
      x = 0;
      while (x < 8)
	{
	  nev->p._piece[Y][X]->_zone[y][x] = n->p._piece[Y][X]->_zone[y][x];
	  x++;
	}
      y++;
    }
}

t_noeud		*add(t_noeud *n, std::string plateau)
{
  t_noeud	*nev;
  int		x, y = 0;

  nev = new t_noeud;
  nev->next = n;
  n->prev = nev;
  nev->p.refresh(plateau);
  while (y < 8)
    {
      x = 0;
      while (x < 8)
	{
	  copy_zone(nev, n, x, y);
	  x++;
	}
      y++;
    }
  return (nev);
}

void	play(t_noeud *n, int x, int y, int gen)
{
  n->p.joue(x, y);
}

void	coup_suivant(t_noeud *n, int X, int Y)
{
  int		x, y = 0;

  while (y < 8)
    {
      x = 0;
      while (x < 8)
	{
	  if (n->p._piece[Y][X]->_zone[y][x])
	    {
	      n->p._piece[Y][X]->_zone[y][x] = false;
	      return ;
	    }
	  x++;
	}
      y++;
    }
}

t_noeud		*generation(int profondeur, int gen, std::string pl)
{
  int		x, y = 0;
  t_noeud	*n;
  plateau	p;
  bool		start = true;
  std::string	tmp;

  n = new t_noeud;
  n->p.refresh(pl);
  n->next = NULL;
  calc_moov(n->p, gen);
  while (y < 8)
    {
      x = 0;
      while (x < 8)
	{
	  if (n->p._piece[y][x]->_mine == (gen == 1 ? 2 : 1) && n->p._piece[y][x]->jouable())
	    {
	      if (start == false)
		n = add(n, pl);
	      play(n, x, y, gen);
	      if (profondeur == 0)
		{
		  n->valeur = n->p.valeur(&n->p);
		}
	      if (profondeur > 0)
		n->chil = generation(profondeur - 1, gen * - 1, n->p.modifie());
	      else
		n->chil = NULL;
	      tmp = n->p.modifie();
	      n->p.refresh(pl);
	      if (n->p._piece[y][x]->jouable())
		{
		  coup_suivant(n, x, y);
		  x -= 1;
		}
	      else
		n->p.refresh(tmp);
	      start = false;
	    }
	  x++;
	}
      y++;
    }
  n->prev = NULL;
  return (n);
}

void	arbre::start(int profondeur, std::string plateau)
{
  _n = new t_noeud;
  _n->p.refresh(plateau);
  calc_moov(_n->p, 1);
  _n->next = NULL;
  _n->prev = NULL;
  _n->chil = generation(profondeur, 1, _n->p.modifie());
}

int	minimax(t_noeud *n, int gen, int profondeur)
{
  int	val;

  val = n->valeur;
  while (n)
    {
      if (n->chil)
	{
	  val = minimax(n->chil, gen * -1, profondeur + 1);
	  n->valeur = val;
	}
      n->chil = NULL;
      if (gen == 1)
	{
	  if (val < n->valeur)
	    val = n->valeur;
	}
      else
	{
	  if (val > n->valeur)
	    val = n->valeur;
	}
      n = n->next;
    }
  return (val);
}

void	arbre::choice(std::string &result)
{
  int val;

  val = minimax(_n->chil, 1, 0);
  _n = _n->chil;
  while (val != _n->valeur)
    _n = _n->next;
  result = _n->p.modifie();
}
