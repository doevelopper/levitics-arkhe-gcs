
#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWINTRASTEPTRANSITION_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_WORKFLOW_WORKFLOWINTRASTEPTRANSITION_HPP

#include <QAbstractTransition>
#include <QString>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>

class WorkflowIntrastepTransition
    : public QAbstractTransition
{
    Q_OBJECT

    public:

        enum IntrastepTransitionType
        {
            ValidationTransition = 0,
            ValidationFailedTransition
        };

        WorkflowIntrastepTransition();
        WorkflowIntrastepTransition(IntrastepTransitionType newTransitionType);
        WorkflowIntrastepTransition(const WorkflowIntrastepTransition &) Q_DECL_EQ_DEFAULT;
        WorkflowIntrastepTransition(WorkflowIntrastepTransition &&) Q_DECL_EQ_DEFAULT;
        WorkflowIntrastepTransition & operator=(const WorkflowIntrastepTransition &) & = default;
        WorkflowIntrastepTransition & operator=(WorkflowIntrastepTransition &&) & = default;
        virtual ~WorkflowIntrastepTransition();

        IntrastepTransitionType getTransitionType() const;
        void setTransitionType(const IntrastepTransitionType & value);

    protected:

        virtual bool eventTest(QEvent * e);
        void onTransition (QEvent *);

    private:

        IntrastepTransitionType m_transitionType;

        static log4cxx::LoggerPtr logger;
};

#endif
