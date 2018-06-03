
#include <iostream>
#include <GcsTest.hpp>

GcsTest::GcsTest(std::string suite ,
                 unsigned int iteration)
    : m_testSuites(std::move(suite))
    , m_numberOfTestIteration(iteration)
{

}

int GcsTest::run (int argc ,  char * argv[])
{
    const std::string name = !m_testSuites.empty() ? m_testSuites : "AllTests";

    if ( m_numberOfTestIteration > 0)
    {
        ::testing::GTEST_FLAG(repeat) = m_numberOfTestIteration;
    }

    // ::testing::GTEST_FLAG(filter) = suite;
    // GTEST_FLAG(output) = "xml:" + testOuputPath;
    ::testing::GTEST_FLAG(output) = "xml:Report.xml";
    ::testing::FLAGS_gmock_verbose = "verbose";
    //    ::testing::GTEST_FLAG(print_time) = false;

    try
    {
        // ::testing::InitGoogleTest(&argc , argv);
        ::testing::InitGoogleMock(&argc , argv);
    }
    catch (std::exception & e)
    {
        // LOG_ERROR(logger , "Issues while innitializing test environment" << typeid (e).name () << ": " << e.what () );
        std::cerr << "Issues while innitializing test environment" << typeid (e).name () << ": " << e.what () <<
            std::endl;
    }
    catch (...)
    {
        std::cerr << "Unhandled exception" <<std::endl;
    }

    return RUN_ALL_TESTS();
}
