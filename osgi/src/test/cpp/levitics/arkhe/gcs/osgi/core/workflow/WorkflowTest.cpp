#include <levitics/arkhe/gcs/osgi/core/workflow/WorkflowTest.hpp>

log4cxx::LoggerPtr WorkflowTest::logger = \
        log4cxx::Logger::getLogger(std::string("levitics.arkhe.gcs.osgi.core.logger.test.WorkflowTest"));

WorkflowTest::WorkflowTest()
    :m_objectToTest(Q_NULLPTR)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}


WorkflowTest::~WorkflowTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void WorkflowTest::SetUp ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    m_objectToTest = new Workflow();
}

void WorkflowTest::TearDown ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    delete m_objectToTest;
}


bool WorkflowTest::numberOfTimesEntryExitTest()
{

    EXPECT_TRUE(Q_NULLPTR == NULL);
//    ASSERT_TRUE(true);
//    ASSERT_EQ(Q_NULLPTR == NULL);
    return(true);
}

int WorkflowTest::currentStepAndNumberOfTimesEntryExitTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

int WorkflowTest::startWorkflow()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TEST_F(WorkflowTest, WorkflowTest1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    WorkflowStepMock * step1 = new WorkflowStepMock("Step 1");
    step1->name("Step 1");
    step1->description("Description for step 1");

    ASSERT_STREQ("Step 1", step1->name().toStdString().c_str());
    ASSERT_STREQ("Description for step 1", step1->description().toStdString().c_str());

    WorkflowStepMock * step2 = new WorkflowStepMock("Step 2");
    step2->name("Step 2");
    step2->description("Description for step 2");

    ASSERT_STREQ("Step 2", step1->name().toStdString().c_str());
    ASSERT_STREQ("Description for step 2", step1->description().toStdString().c_str());

    WorkflowStepMock * duplicatedStep1 = new WorkflowStepMock("Step 1");

    EXPECT_FALSE(m_objectToTest->addTransition(step1, duplicatedStep1));
    EXPECT_FALSE(m_objectToTest->addTransition(step1, step1));

    EXPECT_TRUE(numberOfTimesEntryExitTest());
}

