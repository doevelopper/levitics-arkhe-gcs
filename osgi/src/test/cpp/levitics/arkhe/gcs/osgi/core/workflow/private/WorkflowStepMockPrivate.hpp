
#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_PRIVATE_WORKFLOWSTEPMOCK_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_PRIVATE_WORKFLOWSTEPMOCK_HPP

#include <QObject>
#include <QString>
#include <QList>
#include <QMap>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/WorkflowStep.hpp>

class WorkflowStepMockPrivate
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
