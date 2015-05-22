/**
  *    ERROR
  *   ./example: error while loading shared libraries: 
  *    libboost_regex.so.1.58.0: cannot open shared object file: 
  *    No such file or directory

 ** Possible solution:
http://stackoverflow.com/questions/10577728/how-to-make-sure-that-boost-is-successfully-installed

**/


// The following simple program that extracts the subject lines from emails
// Learn more at: http://stackoverflow.com/questions/10577728/how-to-make-sure-that-boost-is-successfully-installed

#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main()
{
    std::string line;
    boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );

    while (std::cin)
    {
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
            std::cout << matches[2] << std::endl;
    }
}

