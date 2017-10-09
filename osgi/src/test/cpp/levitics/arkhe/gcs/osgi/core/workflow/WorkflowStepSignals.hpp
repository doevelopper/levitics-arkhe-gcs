#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWSTEPSIGNALS_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWSTEPSIGNALS_HPP
#include <QObject>
#include <QString>
#include <QList>
#include <QMap>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/WorkflowStep.hpp>

class WorkflowStepSignalsPrivate;

class WorkflowStepSignals : public QObject
{
    Q_OBJECT

    public:

        WorkflowStepSignals();
        WorkflowStepSignals(WorkflowStep * newStep,QObject* parent = Q_NULLPTR);

//        WorkflowStepSignals(const WorkflowStepSignals &) = default;               // Copy constructor
//        WorkflowStepSignals(WorkflowStepSignals &&) = default;                    // Move constructor
//        WorkflowStepSignals & operator=(const WorkflowStepSignals &) & = default;  // Copy assignment operator
//        WorkflowStepSignals & operator=(WorkflowStepSignals &&) & = default;       // Move assignment operator
        virtual ~WorkflowStepSignals();

        virtual int numberOfTimesRanOnEntry()const;
        virtual int numberOfTimesRanOnExit()const;

Q_SIGNALS:
        void validationComplete(bool validationSucceeded, const QString& branchId = "")const;
        void onEntryComplete()const;
        void onExitComplete()const;

protected:
  QScopedPointer<WorkflowStepSignalsPrivate> d_ptr;

protected Q_SLOTS:
        virtual void validate(const QString& desiredBranchId = QString())const;
        virtual void validateFails()const;
        virtual void onEntry(const WorkflowStep* comingFrom, const WorkflowInterstepTransition::InterstepTransitionType transitionType);
        virtual void onExit(const WorkflowStep* goingTo, const WorkflowInterstepTransition::InterstepTransitionType transitionType);

    private:

    Q_DECLARE_PRIVATE(WorkflowStepSignals);
    Q_DISABLE_COPY(WorkflowStepSignals);

    static log4cxx::LoggerPtr logger;
};

#endif
