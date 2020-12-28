#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED
#define SET_BIT(Reg,Bitno) (Reg |= (1<<Bitno))
#define CLR_BIT(Reg,Bitno) (Reg &= ~(1<<Bitno))
#define TOG_bIT(Reg,Bitno) (Reg ^= (1<<Bitno))
#define GET_BIT(Reg,Bitno) ((Reg>>Bitno)&1)

#endif // UTILITIES_H_INCLUDED
