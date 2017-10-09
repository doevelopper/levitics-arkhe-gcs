
#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWSTEPMOCK_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWSTEPMOCK_HPP

#include <QEvent>
#include <QAbstractTransition>
#include <QString>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/WorkflowStep.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/WorkflowInterstepTransition.hpp>

class WorkflowStepMockPrivate;

class WorkflowStepMock
    : public WorkflowStep
{
    public:

        WorkflowStepMock();
        explicit WorkflowStepMock(const QString & newId);
        virtual ~WorkflowStepMock();

        virtual int numberOfTimesRanOnEntry() const;
        virtual int numberOfTimesRanOnExit() const;
        virtual void validate(const QString & desiredBranchId = QString());

        virtual void onEntry(const WorkflowStep * comingFrom,
                             const WorkflowInterstepTransition::InterstepTransitionType transitionType);
        virtual void onExit(const WorkflowStep * goingTo,
                            const WorkflowInterstepTransition::InterstepTransitionType transitionType);

    protected:

        QScopedPointer<WorkflowStepMockPrivate> d_ptr;

    private:

        Q_DECLARE_PRIVATE(WorkflowStepMock);
        Q_DISABLE_COPY(WorkflowStepMock);

        static log4cxx::LoggerPtr logger;
};

#endif
