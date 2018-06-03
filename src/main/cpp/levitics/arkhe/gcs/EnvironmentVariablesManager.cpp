
#include <levitics/arkhe/gcs/EnvironmentVariablesManager.hpp>

EnvironmentVariablesManager::EnvironmentVariablesManager()
{
}

EnvironmentVariablesManager::~EnvironmentVariablesManager()
{
}

void EnvironmentVariablesManager::put (const std::string & name ,
                                       const std::string & value)
{
    VariableContainer pair;
    // this->pairToContainer(name, value, &pair);
    const std::pair<Variables::iterator , bool> inserted = this->m_variables.insert(std::make_pair(name , pair));

    //    if (!inserted.second)
    //    {
    //        inserted.first->second = pair;
    //    }
    if (!inserted.second)
    {
        inserted.first->second.assign(pair.begin() , pair.end());
    }

    putenv(&inserted.first->second[0]);
}

void EnvironmentVariablesManager::PairToContainer (const std::string & name ,
                                                   const std::string & value ,
                                                   VariableContainer * pair) const
{
    pair->clear();
    std::copy(name.begin() , name.end() , std::back_inserter(*pair));
    pair->push_back('=');
    std::copy(value.begin() , value.end() , std::back_inserter(*pair));
    pair->push_back('\0');
}
