
#ifndef TEST_LEVITICS_OSGI_CORE_WORKFLOW_PRIVATE_WORKFLOWSTEPMOCK_HPP
#define TEST_LEVITICS_OSGI_CORE_WORKFLOW_PRIVATE_WORKFLOWSTEPMOCK_HPP
#include <QObject>
#include <QString>
#include <QList>
#include <QMap>

#include <levitics/osgi/core/logger/Logger.hpp>
#include <core/workflow/WorkflowStep.hpp>

class WorkflowStepMockPrivate
    : public WorkflowStep
{
    public:

        WorkflowStepMockPrivate();


        WorkflowStepMockPrivate(const WorkflowStepMockPrivate &) = default;               // Copy constructor
        WorkflowStepMockPrivate(WorkflowStepMockPrivate &&) = default;                    // Move constructor
        WorkflowStepMockPrivate & operator=(const WorkflowStepMockPrivate &) & = default;  // Copy assignment operator
        WorkflowStepMockPrivate & operator=(WorkflowStepMockPrivate &&) & = default;       // Move assignment operator
        virtual ~WorkflowStepMockPrivate();

        virtual int numberOfTimesRanOnEntry() const;
        void numberOfTimesRanOnEntry(int numberOfTimesRanOnEntry);

        virtual int numberOfTimesRanOnExit() const;
        void numberOfTimesRanOnExit(int numberOfTimesRanOnExit);

    private:

        int m_numberOfTimesRanOnEntry;
        int m_numberOfTimesRanOnExit;
        static log4cxx::LoggerPtr logger;
};

#endif
