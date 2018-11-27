#include "Expr.hpp"

//------------------------------------

Expr::Expr(string s) { sym = s; typ = SYM; }

Expr::Expr(vector<Expr*> s) { exprs = s; typ = LIST; }

Expr::Expr(string s,int i) { sym = s; typ = SYM; next_tok = i; } // for parsing

Expr::Expr(vector<Expr*> s,int i) { exprs = s; typ = LIST; next_tok = i; } // for parsing

bool Expr::isSym() { return (typ==SYM); }

bool Expr::isList() { return (typ==LIST); }

bool Expr::isVar() { return (isSym()==true && sym[0]=='?'); }

int Expr::next() { return next_tok; } // for parsing

string Expr::getSym() { return sym; }

vector<Expr*> Expr::getList() { return exprs; }

string Expr::toString() 
{ 
  if (isList()==false) return sym;
  int n=exprs.size();
  string s="(";
  for (int i=0 ; i<n ; i++) {
    s += exprs[i]->toString();
    if (i<n-1) s += " "; }
  s += ")";
  return s; 
}

//---------------------------------------------

vector<string>* tokenize(string s)
{
  int i=0,n=s.size(),j;
  for (j=0 ; j<n ; j++) if (s[j]=='#') break; 
  n = j; // truncate comments

  vector<string>* toks=new vector<string>();
  while (i<n) 
  {
    while (i<n && s[i]==' ') i++; // skip whitespace;
    if (s[i]=='(' || s[i]==')') { toks->push_back(string(s,i,1)); i++; continue; }
    j = i;
    //while (j<n && !strchr("( )",s[j])) j++;
    while (j<n && string("( )").find(s[j])==string::npos) j++;
    toks->push_back(string(s,i,j-i));
    i = j; 
  }
  return toks;
}

// check for improper pairs of parens, e.g start with close, or fail to close
// at top level, rules and even facts must be enclosed in outer parens
// facts are distinguished by first element being a symbol, not a list

Expr* parse1(vector<string>* toks,int i)
{
  int n=toks->size();
  if (toks->at(i)==")") { cout << "error: close paren without open\n"; exit(0); }
  if (toks->at(i)=="(")
  {
    vector<Expr*> exprs;
    i++;
    while (i<n && toks->at(i)!=")") {
      Expr* expr=parse1(toks,i);
      exprs.push_back(expr);
      i = expr->next(); }
    if (i==n) { cout << "error: open paren without close\n"; exit(0); }
    return new Expr(exprs,i+1);
  }
  else return new Expr(toks->at(i),i+1);
}

Expr* parse(vector<string>* toks) { return parse1(toks,0); }

//---------------------------------------------

// helper functions for standardize()

int cnt=0;

string gensym() { return string("?v")+to_string(cnt++); }

void collect_vars(Expr* e,set<string>& vars)
{
  if (e->isVar()==true) vars.insert(e->getSym());
  if (e->isList()==true)
  {
    vector<Expr*> exprs=e->getList();
    for (int i=0 ; i<exprs.size() ; i++)
      collect_vars(exprs[i],vars);
  }
}

Expr* replace_vars(Expr* e,unordered_map<string,string>& map)
{
  if (e->isSym()==true)
  {
    unordered_map<string,string>::iterator newvar=map.find(e->getSym());
    if (newvar!=map.end()) return new Expr(newvar->second);
    return e;
  }
  if (e->isList()==true)
  {
    vector<Expr*> exprs=e->getList();
    vector<Expr*> replaced;
    for (int i=0 ; i<exprs.size() ; i++)
      replaced.push_back(replace_vars(exprs[i],map));
    return new Expr(replaced);
  }
}

// replace all vars with unique new vars

Expr* standardize(Expr* e) 
{
  set<string> vars;
  collect_vars(e,vars); 
  unordered_map<string,string> newvars;
  for (set<string>::iterator iter=vars.begin() ; iter!=vars.end() ; iter++)
    newvars[*iter] = gensym();
  return replace_vars(e,newvars);
}