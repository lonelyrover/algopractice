#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

void stringTokenizer(const std::string& source, std::vector<std::string>& result)
{
  std::string token, s = source, delimiter(" ");
  unsigned int pos;

  while ((pos = s.find(delimiter)) != std::string::npos)
  {
    token = s.substr(0, pos);
    result.push_back(token);
    s.erase(0, pos + delimiter.length());
  }
}

int main(int argc, char* argv[])
{
  if (argc < 1)
  {
    std::cout << "" << std::endl;
    return -1;
  }

  int cases = atoi(argv[0]);
  unsigned int argc_pointer = 1;
  
  while (cases--)
  {
    atoi(argv[argc_pointer++]);
    atoi(argv[argc_pointer++]);
  }
}