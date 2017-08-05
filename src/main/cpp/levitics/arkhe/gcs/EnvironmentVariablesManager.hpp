
#ifndef LEVITICS_ARKHE_GCS_ENVIRONMENTVARIABLESMANAGER_HPP
#define LEVITICS_ARKHE_GCS_ENVIRONMENTVARIABLESMANAGER_HPP

#include <vector>
#include <map>
#include <string>

class EnvironmentVariablesManager
{
public:

    using VariableContainer = std::vector<char>;
    using Variables = std::map<std::string , VariableContainer>;

    EnvironmentVariablesManager();
    EnvironmentVariablesManager(const EnvironmentVariablesManager & orig);
    virtual ~EnvironmentVariablesManager();

    void put (const std::string & name , const std::string & value);

private:

    void PairToContainer (const std::string & name , const std::string & value , VariableContainer * pair) const;
    Variables m_variables;
};

#endif
