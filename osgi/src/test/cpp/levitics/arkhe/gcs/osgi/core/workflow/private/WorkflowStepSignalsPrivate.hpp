#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_PRIVATE_WORKFLOWSTEPSIGNALSPRIVATE_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_PRIVATE_WORKFLOWSTEPSIGNALSPRIVATE_HPP

#include <QObject>
#include <QString>
#include <QList>
#include <QMap>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/WorkflowStep.hpp>

class WorkflowStepSignalsPrivate
{
    public:

        WorkflowStepSignalsPrivate();
        WorkflowStepSignalsPrivate(const WorkflowStepSignalsPrivate &) = default;               // Copy constructor
        WorkflowStepSignalsPrivate(WorkflowStepSignalsPrivate &&) = default;                    // Move constructor
        WorkflowStepSignalsPrivate & operator=(const WorkflowStepSignalsPrivate &) & = default;  // Copy assignment operator
        WorkflowStepSignalsPrivate & operator=(WorkflowStepSignalsPrivate &&) & = default;       // Move assignment operator
        virtual ~WorkflowStepSignalsPrivate();

        int numberOfTimesRanOnEntry() const;
        void setNumberOfTimesRanOnEntry(int numberOfTimesRanOnEntry);

        int numberOfTimesRanOnExit() const;
        void setNumberOfTimesRanOnExit(int numberOfTimesRanOnExit);

        WorkflowStep *step() const;
        void setStep(WorkflowStep *step);

private:
        int m_numberOfTimesRanOnEntry;
        int m_numberOfTimesRanOnExit;
        WorkflowStep * m_Step;

    static log4cxx::LoggerPtr logger;
};

#endif
