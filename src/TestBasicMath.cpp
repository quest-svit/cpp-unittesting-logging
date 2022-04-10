#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "CBasicMath.hpp"

#include <log4cxx/logger.h>
#include <log4cxx/xml/domconfigurator.h>

using namespace log4cxx;
using namespace log4cxx::xml;
using namespace log4cxx::helpers;

// Define static logger variable
LoggerPtr loggerMMain(Logger::getLogger("main"));

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class TestBasicMath : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestBasicMath);
    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST(testMultiply);
    CPPUNIT_TEST(testMax);
    CPPUNIT_TEST(testMin);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testAddition(void);
    void testMultiply(void);
    void testMax(void);
    void testMin(void);

private:

    CBasicMath *mTestObj;
};

//-----------------------------------------------------------------------------

void TestBasicMath::testAddition(void)
{
    LOG4CXX_INFO (loggerMMain, "Executing testAddition");
    CPPUNIT_ASSERT(5 == mTestObj->Addition(2,3));
}

void TestBasicMath::testMultiply(void)
{
    LOG4CXX_INFO (loggerMMain, "Executing testMul");
    CPPUNIT_ASSERT(6 == mTestObj->Multiply(2,3));
}

void TestBasicMath::setUp(void)
{
    LOG4CXX_INFO (loggerMMain, "Executing Setup");
    mTestObj = new CBasicMath();
}

void TestBasicMath::testMax(void)
{
	LOG4CXX_INFO (loggerMMain, "Executing testMax");
	CPPUNIT_ASSERT(3 == mTestObj->Max(2,3));
	CPPUNIT_ASSERT(5 == mTestObj->Max(5,3));
}
	
void TestBasicMath::testMin(void)
{
	LOG4CXX_INFO (loggerMMain, "Executing testMin");
        CPPUNIT_ASSERT(2 == mTestObj->Min(2,3));
        CPPUNIT_ASSERT(3 == mTestObj->Min(5,3));
}

	
void TestBasicMath::tearDown(void)
{
    LOG4CXX_INFO (loggerMMain, "Executing tearDown");
    delete mTestObj;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestBasicMath );

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("results/cppTestBasicMathResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}

