#include "CBasicMath.hpp"
#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

using namespace log4cxx;
using namespace log4cxx::xml;
using namespace log4cxx::helpers;

// Define static logger variable
LoggerPtr logger(Logger::getLogger("main"));

int CBasicMath::Addition(int x, int y)
{
   LOG4CXX_INFO(logger, "Executing Addition");
   return (x + y);
}

int CBasicMath::Multiply(int x, int y)
{
   LOG4CXX_INFO(logger, "Executing Multiply");
   return (x * y);
}

int CBasicMath::Max(int x,int y)
{
	LOG4CXX_INFO(logger, "Executing Max");
	return ( x > y ? x : y);
}

int CBasicMath::Min(int x, int y)
{
	LOG4CXX_INFO(logger, "Executing Min");
	return ( x < y ? x: y);
}
