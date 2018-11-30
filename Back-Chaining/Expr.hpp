#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <cstdint>

#define EOL '\n';

typedef std::vector<std::string> FactV;
typedef std::vector<std::string> RuleV;

struct KnowledgeBase {

  FactV factBinV;
  RuleV ruleBinV;
  //unifier mappings

};

//-----------------------

void unify( std::string a, std::string b, KnowledgeBase &KB );

void inferencer( std::string decisionQ, KnowledgeBase &KB );

void readFile( std::string &fileName, KnowledgeBase &KB, bool verbose );

float Q_rsqrt( float number );
