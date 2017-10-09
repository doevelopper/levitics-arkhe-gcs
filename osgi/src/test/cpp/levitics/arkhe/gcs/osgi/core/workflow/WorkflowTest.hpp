#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWTEST_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWTEST_HPP

#include <QCoreApplication>
#include <QTimer>

#include <cstdlib>
#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/Workflow.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/WorkflowStepMock.hpp>

class WorkflowTest : public ::testing::Test
{
public:
    WorkflowTest();
    ~WorkflowTest();

    virtual void SetUp ();
    virtual void TearDown ();

    bool numberOfTimesEntryExitTest();
    int startWorkflow();
    int currentStepAndNumberOfTimesEntryExitTest();

protected:

    static log4cxx::LoggerPtr logger;
    Workflow *m_objectToTest;
private:

//    WorkflowStepMock * m_objectToTest;
//    Workflow *m_objectToTest;
};

#endif
