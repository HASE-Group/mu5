int pow(int base, int exp)
{
  int res = 1;
  for (int i = 0; i<exp; i++)
    res *= base;
  return res;
}

char i_to_ch(int i)
{
  if( isprint( i ) == 0 )
    {return ' ';}
  else
    {return (char)i;}
}

int is_an_instrn(t_fn_reg Inst)
{
 if ( 
     (
      ((Inst.t == Org)
       && (
          Inst.f == XNB_LD
       || Inst.f == SN_LD
       || Inst.f == XNB_PL
       || Inst.f == XNB_ST
       || Inst.f == SF_LD
       || Inst.f == SF_PL
       || Inst.f == SFNB_PL
       || Inst.f == SF_ST
       || Inst.f == NB_LD
       || Inst.f == NBSF_PL
       || Inst.f == NB_PL
       || Inst.f == NB_ST
       || Inst.f == BR
       || Inst.f == BReq
       || Inst.f == BRne
       || Inst.f == BRge
       || Inst.f == BRlt
       || Inst.f == BRle
       || Inst.f == BRgr
       || Inst.f == BRBn
       || Inst.f == JUMP
       || Inst.f == Bneq
       || Inst.f == Bnne
       || Inst.f == Bnge
       || Inst.f == Bnlt
       || Inst.f == Bngr
       || Inst.f == BnBn
    ))
      || ((Inst.t == B || Inst.t == ACC)
	  && (
	      Inst.f == LD
	   || (Inst.f == LDD && Inst.t != ACC)
	   || Inst.f == SLD
	   || Inst.f == ST
	   || Inst.f == ADD
	   || Inst.f == SUB
	   || Inst.f == MUL
	   || Inst.f == DIV
	   || Inst.f == XOR
	   || Inst.f == OR
	   || Inst.f == SHL
	   || Inst.f == AND
	   || Inst.f == RSUB
	   || Inst.f == COMP
	      || (Inst.f == CINC && Inst.t != ACC)
	   || Inst.f == RDIV
	   ))
      || ((Inst.t == STS)
	  && (
	      Inst.f == XDO_LD
	  ||  Inst.f == XD_LD
	  ||  Inst.f == STACK
	  ||  Inst.f == XD_ST
	  ||  Inst.f == XDB_LD
	  ||  Inst.f == XMOD
	  ||  Inst.f == DO_LD
	  ||  Inst.f == D_LD
	  ||  Inst.f == D_SLD
	  ||  Inst.f == D_ST
	  ||  Inst.f == DB_LD
	  ||  Inst.f == MOD
	  ||  Inst.f == BMVB
	  ||  Inst.f == BMVE
	  ||  Inst.f == BSCN
	  ||  Inst.f == BCMP
	  ||  Inst.f == SMVB
	  ||  Inst.f == SMVE
	  ||  Inst.f == SMVF
	  ||  Inst.f == SCMP
	      ))
      || ((Inst.t == Org || Inst.t == ACC ) && Inst.f == STOP)
      ) && !( (Inst.k == lit) &&
	      ((Inst.f == ST) || (Inst.f == NB_ST)|| (Inst.f == SF_ST)
	     || (Inst.f == XNB_ST) || (Inst.f == D_ST)
	       || (Inst.f == XD_ST)))
      )
  return 1;
  return 0;
}

int Control_Transfer(t_fn_reg Inst)
{
  if (   Inst.f == BR
      || Inst.f == BReq
      || Inst.f == BRne
      || Inst.f == BRge
      || Inst.f == BRlt
      || Inst.f == BRle
      || Inst.f == BRgr
      || Inst.f == BRBn
	 )
    return 1;
  return 0;
}

int Set_Bn(t_fn_reg Inst)
{
  if (   Inst.f == Bneq
      || Inst.f == Bnne
      || Inst.f == Bnge
      || Inst.f == Bnlt
      || Inst.f == Bnle
      || Inst.f == Bngr
      || Inst.f == BnBn
	 )
    return 1;
  return 0;
}

int Base_Load(t_fn_reg Inst)
 {
   if ( Inst.f == XNB_LD || Inst.f == XNB_PL
       || Inst.f == SF_LD  || Inst.f == SF_PL || Inst.f == SFNB_PL
       || Inst.f == NB_LD  || Inst.f == NBSF_PL || Inst.f == NB_PL
      || Inst.f == STOP
	)
    return 1;
  return 0;
 }

int Base_Store(t_fn_reg Inst)
 {
  if (Inst.f == XNB_ST || Inst.f == SF_ST || Inst.f == NB_ST)
    return 1;
  return 0;
 }

int Double_Instrn(t_fn_reg Inst)
{
  if ( ((Inst.t == B) && (Inst.f == SLD))
       || ((Inst.t == STS) && (Inst.f == STACK))
     )
    return 1;
  return 0;
}

int B_Store(t_fn_reg Inst)
{
  if ( (Inst.t == B) && ( (Inst.f == ST) || ((Inst.f == SLD) && (Inst.Type == 'D'))))
  return 1;
  return 0;
}

int PROP_Store(t_fn_reg Inst)
{
  if ( ((Inst.t != ACC) && (Inst.f == ST)) || ((Inst.f == SLD) && (Inst.Type == 'D'))
       || (Inst.f == XNB_ST) || (Inst.f == SF_ST) || (Inst.f == NB_ST)
       || (Inst.f ==  D_ST) || (Inst.f ==  XD_ST)
	|| ((Inst.f == STACK) && (Inst.Type == 'D'))
       )
  return 1;
  return 0;
}

int D_XD_Instrn(t_seop_fn_reg Inst)
{
  if  (  Inst.f == XDO_LD || Inst.f == DO_LD || Inst.f == XD_LD
      || Inst.f == D_LD || Inst.f == D_SLD || Inst.f == XD_ST || Inst.f == D_ST
      || Inst.f == XDB_LD || Inst.f == DB_LD || Inst.f == XMOD
      || Inst.f == MOD)
    return 1;
  return 0;
}

int STS_Instrn(t_seop_fn_reg Inst)
{
  if (Inst.f == BMVB || Inst.f == BMVE || Inst.f == BLGC
      || Inst.f == SMVB || Inst.f == SMVE || Inst.f == SMVF
      || Inst.f == BSCN || Inst.f == BCMP || Inst.f == SCMP
)
    return 1;
  return 0;
}

int Line(int Reg)
{
  int j = 1;
  int line = 0;
  for (int i=0;i<8;i++)
    {
      if ((Reg & j) == j)
	{line = i;}
      j = j * 10;
    }
  return line;
}

int NS_access(t_fn_reg Inst)
{
  if ( (Inst.k == V32) || (Inst.k == V64)
        ||((Inst.f == ST) && Inst.Type == D)
       || (((Inst.k == SB) || (Inst.k == S0)) && (Inst.b != D))
       || ((Inst.k == stack) && (Inst.Type == 'V'))
     )
    return 1;
  return 0;
}

int UpdateSF(t_fn_reg Inst)
{
  if ( ((Inst.Type == 'V') && (Inst.f == STACK))
       || ((Inst.Type == 'D') && (Inst.k == stack || Inst.f == ST
       || Inst.f == D_ST)  ))
    return 1;
  return 0;
}

int UpdateS6(t_fn_reg Inst)
{
  if ( ((Inst.Type == 'V') || (Inst.Type == 'A')) 
       && ((Inst.f == STACK) || (Inst.f == SLD) || (Inst.k == stack))
       )
    return 1;
  return 0;
}

int SEOP_wait(t_fn_reg Inst)
{
  if ( ((Inst.t == Org) && ((Inst.k == SB) || (Inst.k == S0)))
       || ((Inst.t == STS) && ((Inst.f == D_ST) || (Inst.f == XD_ST)))
       || (Inst.f == BSCN) || (Inst.f == BCMP) || (Inst.f == SCMP)
       || ((Inst.t == ACC) && ((Inst.f == COMP) || (Inst.f == STOP)))
	)
    return 1;
  return 0;
}
