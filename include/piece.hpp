#ifndef		__PIECE_HPP__
#define		__PIECE_HPP__

#include	<iostream>

class		plateau;

class		piece
{
public:

  piece();
  ~piece();
  void		set(int x, int y);
  void		info();
  virtual void		calc_moov(plateau &p) = 0;
  int		valeur(plateau *pl);
  int		valeurInitial() const;
  bool		mise_en_echec(plateau *pf);
  void		aff_zone() const;
  bool		jouable();
  void		clean();
  int		_mine;
  int		_x;
  int		_y;
  bool		_zone[8][8];
  int		_valeur;

private:

protected:

  int		_valeurTempo;
};

#endif		/*__PIECE_HPP__*/
