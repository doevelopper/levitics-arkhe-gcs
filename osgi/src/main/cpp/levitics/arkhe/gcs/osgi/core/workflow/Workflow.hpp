
#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOW_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOW_HPP

#include <QObject>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>

class WorkflowStep;
class WorkflowPrivate;
class QAbstractState;


class Workflow : public QObject
{
        Q_OBJECT
        Q_ENUMS(TransitionDirectionality)
        Q_PROPERTY(bool isRunning READ isRunning DESIGNABLE false)
        Q_PROPERTY(bool goBackToOriginStepUponSuccess READ goBackToOriginStepUponSuccess WRITE setGoBackToOriginStepUponSuccess)
        Q_PROPERTY(bool verbose READ verbose WRITE setVerbose)
    public:
    using Superclass = QObject ;
    enum TransitionDirectionality
    {
        Bidirectional = 0,
        Forward,
        Backward
    };
        explicit Workflow(QObject* parent = 0);
//        Workflow(const Workflow &) Q_DECL_EQ_DEFAULT;
//        Workflow(Workflow &&) Q_DECL_EQ_DEFAULT;
//        Workflow & operator=(const Workflow &) & = default;
//        Workflow & operator=(Workflow &&) & = default;
        virtual ~Workflow();

        Q_INVOKABLE virtual void start();
        bool isRunning()const;
        Q_INVOKABLE virtual void stop();

        Q_INVOKABLE virtual bool addTransition(WorkflowStep* origin, WorkflowStep* destination,
                                               const QString& branchId = QString(),
                                               const Workflow::TransitionDirectionality directionality
                                               = Workflow::Bidirectional);
        Q_INVOKABLE bool hasTransition(WorkflowStep* origin, WorkflowStep* destination,
                                       const QString& branchId = QString(),
                                       const Workflow::TransitionDirectionality directionality
                                       = Workflow::Bidirectional);
        Q_INVOKABLE WorkflowStep* initialStep()const;
        Q_INVOKABLE virtual void setInitialStep(WorkflowStep* step);
        Q_INVOKABLE WorkflowStep* currentStep()const;
        Q_INVOKABLE bool hasStep(const QString& id)const;
        Q_INVOKABLE WorkflowStep* step(const QString& id)const;
        Q_INVOKABLE bool canGoForward(WorkflowStep* step=0)const;
        Q_INVOKABLE bool canGoBackward(WorkflowStep* step=0)const;
        Q_INVOKABLE bool canGoToStep(const QString& targetId, WorkflowStep* step=0)const;
        Q_INVOKABLE QList<WorkflowStep*> forwardSteps(WorkflowStep* step=0)const;
        Q_INVOKABLE QList<WorkflowStep*> backwardSteps(WorkflowStep* step=0)const;
        Q_INVOKABLE QList<WorkflowStep*> finishSteps()const;
        Q_INVOKABLE QList<WorkflowStep*> steps()const;
        Q_INVOKABLE int backwardDistanceToStep(WorkflowStep* fromStep = 0, WorkflowStep* origin = 0)const;

        bool goBackToOriginStepUponSuccess()const;
        void setGoBackToOriginStepUponSuccess(bool flag);

        bool verbose()const;
        void setVerbose(bool value);

    public Q_SLOTS:

        virtual void goForward(const QString& desiredBranchId = QString());
        virtual void goBackward(const QString& desiredBranchId = QString());
        virtual void goToStep(const QString& targetId);
        virtual void evaluateValidationResults(bool validationSucceeded, const QString& branchId);

    protected:

        void goToNextStepAfterSuccessfulValidation(const QString& branchId);
        void goToProcessingStateAfterValidationFailed();
        virtual void goToStepSucceeded();
        virtual void goToStepFailed();
        void goFromGoToStepToStartingStep();

        QScopedPointer<WorkflowPrivate> d_ptr;

    protected Q_SLOTS:

        void attemptToGoToNextStep();
        void performTransitionBetweenSteps();

    private:
        Q_DECLARE_PRIVATE(Workflow);
        Q_DISABLE_COPY(Workflow);
        static log4cxx::LoggerPtr logger;
};

#endif
