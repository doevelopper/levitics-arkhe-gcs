#ifndef LEVITICS_ARKHE_GCS_APP_GCSAPPLICATIONTEST_HPP
#define LEVITICS_ARKHE_GCS_APP_GCSAPPLICATIONTEST_HPP

#include <gtest/gtest.h>
#include <levitics/arkhe/gcs/app/GCSApplication.hpp>

class GCSApplicationTest : public ::testing::Test
{
public:
    GCSApplicationTest();
    virtual ~GCSApplicationTest();

protected:
  /*!
   *  @brief Sets up the test fixture.
   */ 
  void SetUp() override;

  /*!
   *  @brief Tears down the test fixture.
   */ 
  void TearDown() override;
  
private:

};

#endif
