
#ifndef GCSTEST_HPP
#define GCSTEST_HPP

#include <QtCore/qglobal.h>
#include <QtWidgets/QApplication>
#include <vector>
#include <gmock/gmock.h>
#include <levitics/arkhe/gcs/app/logger/Logger.hpp>

class GcsTest
{
public:

    GcsTest(std::string suite , unsigned int iteration = 1);
    GcsTest(const GcsTest &) = default;
    GcsTest(GcsTest &&) = default;
    GcsTest & operator = (const GcsTest &) = default;
    GcsTest & operator = (GcsTest &&) = default;
    virtual ~GcsTest() = default;

    int run (int argc = 0 , char * argv[] = Q_NULLPTR);

protected:

private:

    std::string m_testSuites;
    unsigned int m_numberOfTestIteration;
};

#endif
