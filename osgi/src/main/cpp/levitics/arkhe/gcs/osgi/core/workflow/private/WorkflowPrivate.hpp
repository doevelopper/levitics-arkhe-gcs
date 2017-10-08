
#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_PRIVATE_WORKFLOWPRIVATE_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_PRIVATE_WORKFLOWPRIVATE_HPP
#include <QObject>
#include <QString>
#include <QList>
#include <QMap>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/Workflow.hpp>
#include <levitics/arkhe/gcs/osgi/core/workflow/WorkflowStep.hpp>


class ForwardAndBackwardSteps;

class WorkflowPrivate
    : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(Workflow);

    public:

        WorkflowPrivate();
        WorkflowPrivate(Workflow & object);
        WorkflowPrivate(const WorkflowPrivate &) = default;               // Copy constructor
        WorkflowPrivate(WorkflowPrivate &&) = default;                    // Move constructor
        WorkflowPrivate & operator=(const WorkflowPrivate &) & = default;  // Copy assignment operator
        WorkflowPrivate & operator=(WorkflowPrivate &&) & = default;       // Move assignment operator
        virtual ~WorkflowPrivate();

        bool addStep(WorkflowStep * step);
        bool hasDuplicateTransition(WorkflowStep * origin, WorkflowStep * destination,
                                    const Workflow::TransitionDirectionality directionality);

        bool hasTransitionWithSameBranchId(WorkflowStep * origin, WorkflowStep * destination,
                                           const QString & branchId,
                                           const Workflow::TransitionDirectionality directionality);
        void createTransitionToNextStep(WorkflowStep *  origin,
                                        WorkflowStep *  destination,
                                        const QString & branchId = "");
        void createTransitionToPreviousStep(WorkflowStep *  origin,
                                            WorkflowStep *  destination,
                                            const QString & branchId = "");
        void createTransitionToPreviousStartingStep(WorkflowStep * startingStep,
                                                    WorkflowStep * currentStep);
        void validateInternal(WorkflowStep * step);
        void onEntryInternal(WorkflowStep * step, WorkflowStep * comingFrom,
                             const WorkflowInterstepTransition::InterstepTransitionType & transitionType);
        void onExitInternal(WorkflowStep * step, WorkflowStep * goingTo,
                            const WorkflowInterstepTransition::InterstepTransitionType & transitionType);
        WorkflowStep * stepFromId(const QString & id) const;
        WorkflowStep * stepFromState(const QAbstractState * state);
        int numberOfForwardSteps(WorkflowStep * step);
        int numberOfBackwardSteps(WorkflowStep * step);
        QList<QString> forwardBranchIds(WorkflowStep * step) const;
        QList<QString> backwardBranchIds(WorkflowStep * step) const;
        bool pathExists(const QString & goalId, WorkflowStep * origin = 0) const;
        bool pathExistsFromNextStep(const QString & goalId, const QString & branchId) const;

        QStateMachine * stateMachine() const;
        void setStateMachine(QStateMachine * stateMachine);

        QMap<WorkflowStep *, ForwardAndBackwardSteps *> stepToForwardAndBackwardStepMap() const;
        void setStepToForwardAndBackwardStepMap(const QMap<WorkflowStep *,
                                                           ForwardAndBackwardSteps *> & stepToForwardAndBackwardStepMap);
        using StepToForwardAndBackwardStepMapType = QMap<WorkflowStep *, ForwardAndBackwardSteps *>;
        using StepListType = QList<WorkflowStep *>;
        using StateToStepMapType = QMap<const QAbstractState *, WorkflowStep *>;
        using StateToStepMapIterator = QMap<const QAbstractState *, WorkflowStep *>::iterator;

        WorkflowStep * initialStep() const;
        void setInitialStep(WorkflowStep * initialStep);

        WorkflowStep * currentStep() const;
        void setCurrentStep(WorkflowStep * currentStep);

        WorkflowStep * originStep() const;
        void setOriginStep(WorkflowStep * originStep);

        WorkflowStep * destinationStep() const;
        void setDestinationStep(WorkflowStep * destinationStep);

        WorkflowStep * goToStep() const;
        void setGoToStep(WorkflowStep * goToStep);

        WorkflowStep * startingStep() const;
        void setStartingStep(WorkflowStep * startingStep);

        bool getVerbose() const;
        void setVerbose(bool value);

        bool getGoBackToOriginStepUponSuccess() const;
        void setGoBackToOriginStepUponSuccess(bool goBackToOriginStepUponSuccess);

        WorkflowInterstepTransition::InterstepTransitionType getTransitionType() const;
        void setTransitionType(const WorkflowInterstepTransition::InterstepTransitionType & transitionType);

        QMap<WorkflowStep *, WorkflowStep *> getStepToPreviousStepMap() const;
        void setStepToPreviousStepMap(const QMap<WorkflowStep *, WorkflowStep *> & stepToPreviousStepMap);

        StateToStepMapType getStateToStepMap() const;
        void setStateToStepMap(const StateToStepMapType & stateToStepMap);

        StepListType getRegisteredSteps() const;
        void setRegisteredSteps(const StepListType & registeredSteps);

    public Q_SLOTS:

        void processingAfterOnEntry();
        void processingAfterOnExit();

    protected:

        Workflow * const q_ptr;

    private:

        bool verbose;
        bool m_goBackToOriginStepUponSuccess;

        QStateMachine * m_stateMachine;

        WorkflowStep * m_initialStep;
        WorkflowStep * m_currentStep;
        WorkflowStep * m_originStep;
        WorkflowStep * m_destinationStep;
        WorkflowStep * m_goToStep;
        WorkflowStep * m_startingStep;

        QString DesiredBranchId;

        WorkflowInterstepTransition * m_transitionToPreviousStartingStep;
        WorkflowInterstepTransition::InterstepTransitionType m_transitionType;

        QMap<WorkflowStep *, ForwardAndBackwardSteps *> m_stepToForwardAndBackwardStepMap;
        QMap<WorkflowStep *, WorkflowStep *> m_stepToPreviousStepMap;

        StateToStepMapType m_stateToStepMap;
        StepListType m_registeredSteps;

        static log4cxx::LoggerPtr logger;
};

#endif
