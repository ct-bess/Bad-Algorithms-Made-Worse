#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>

#define EOL '\n';

typedef std::vector<std::string> FactV;
typedef std::vector<std::string> RuleV;

struct KnowledgeBase {

  FactV factBinV;
  RuleV ruleBinV;

};

//-----------------------

void readFile( std::string &fileName, KnowledgeBase &KB, bool verbose );
