// Project:	MU5
// Entity	Global Functions
// File		global_fns.h
// Date:	Mar 2013

// Units are declared here to allow forward references between
// them. HASE automatically declares them from the .edl file, but in
// sequence, only allowing backward references.

class ibu_sr;
class ibu_df;
class prop;
class decode;
class add;
class assoc;
class ns_read;
class assemble;
class execute;
class b_arith;
class dr;
class obs;
class obs_ip;
class obs_queue;
class obs_op;
class dop;
class acc;
class sac;
class cprs;
class l_store;
class d_store;

int pow(int, int);  // forms exponential without using doubles
char i_to_ch(int);
int is_an_instrn(t_fn_reg Inst);
int Control_Transfer(t_fn_reg Inst);
int Set_Bn(t_fn_reg Inst);
int Base_Load(t_fn_reg Inst);
int Base_Store(t_fn_reg Inst);
int Double_Instrn(t_fn_reg Inst);
int B_Store(t_fn_reg Inst);
int PROP_Store(t_fn_reg Inst);
int D_XD_Instrn(t_seop_fn_reg Inst);
int STS_Instrn(t_seop_fn_reg Inst);
int Line(int Reg);
int NS_access(t_fn_reg Inst);
int UpdateSF(t_fn_reg Inst);
int UpdateS6(t_fn_reg Inst);
int DecSF(t_fn_reg Inst);
int SEOP_wait(t_fn_reg Inst);
