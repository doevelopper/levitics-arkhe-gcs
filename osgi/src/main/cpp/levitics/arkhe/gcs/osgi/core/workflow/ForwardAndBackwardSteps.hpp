
#ifndef LEVITICS_OSGI_CORE_WORKFLOW_FORWARDANDBACKWARDSTEPS_HPP
#define LEVITICS_OSGI_CORE_WORKFLOW_FORWARDANDBACKWARDSTEPS_HPP

#include <QObject>

#include <levitics/osgi/core/logger/Logger.hpp>

class WorkflowStep;

class ForwardAndBackwardSteps
{
    public:
        explicit ForwardAndBackwardSteps();
        ForwardAndBackwardSteps(const ForwardAndBackwardSteps &) Q_DECL_EQ_DEFAULT;
        ForwardAndBackwardSteps(ForwardAndBackwardSteps &&) Q_DECL_EQ_DEFAULT;
        ForwardAndBackwardSteps & operator=(const ForwardAndBackwardSteps &) & = default;
        ForwardAndBackwardSteps & operator=(ForwardAndBackwardSteps &&) & = default;
        virtual ~ForwardAndBackwardSteps();

        QList<WorkflowStep *> forwardSteps() const;
        void setForwardSteps(const QList<WorkflowStep *> &forwardSteps);

        QList<WorkflowStep *> backwardSteps() const;
        void setBackwardSteps(const QList<WorkflowStep *> &backwardSteps);

        QList<QString> forwardBranchIds() const;
        void setForwardBranchIds(const QList<QString> &forwardBranchIds);

        QList<QString> backwardBranchIds() const;
        void setBackwardBranchIds(const QList<QString> &backwardBranchIds);

        QString forwardBranchId(WorkflowStep* step);
        QString backwardBranchId(WorkflowStep* step);
//        QList<QString> backwardBranchIds();
//        QList<QString> forwardBranchIds();

        WorkflowStep* forwardStep(QString branchId);
        QString firstForwardBranchId();

        void appendBackwardStep(WorkflowStep* step, QString id);
        void appendForwardStep(WorkflowStep* step, QString id);
protected:

private:
        QList<WorkflowStep*> m_forwardSteps;
        QList<WorkflowStep*> m_backwardSteps;

        QList<QString> m_forwardBranchIds;
        QList<QString> m_backwardBranchIds;
        static log4cxx::LoggerPtr logger;
};

#endif
