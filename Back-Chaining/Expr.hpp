#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

#define EOL '\n';

// an Expr is either a symbol (string) or a list of sub-expressions

class Expr 
{
  enum Etype { SYM,LIST };
  Etype typ; 
  string sym;
  vector<Expr*> exprs; // list of sub-exprs
  int next_tok; // used for parsing

 public:

  Expr(string); 
  Expr(vector<Expr*>); 
  bool isSym();
  bool isList();
  bool isVar(); // checks if is sym and starts with '?'
  string toString();
  string getSym();
  vector<Expr*> getList();

  // the following are used for parsing...
  Expr(string,int);
  Expr(vector<Expr*>,int); 
  int next(); // next index in token list (for parsing)
};

//-----------------------

vector<string>* tokenize(string);

Expr* parse(vector<string>*);

Expr* standardize(Expr*); // replace all vars with unique new vars
