#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>
#include <levitics/arkhe/gcs/app/ScreensDimensions.hpp>
namespace
{

    using cucumber::ScenarioScope;

    struct Ctx
    {
        //std::shared_ptr<ScreensDimensions> obj;
    };

    GIVEN("^blabla$")
    {
        ScenarioScope<Ctx> context{};
       // context->obj = std::make_shared<ScreensDimensions>();
    }

    GIVEN("^initialised with \"([^\"]*)\" and \"([^\"]*)\"$")  {
        ScenarioScope<Ctx> context{};
        REGEX_PARAM(std::string, hello_string);
        REGEX_PARAM(std::string, world_string);
    }

    GIVEN("^I have entered (\\d+) into the calculator$") {
        REGEX_PARAM(double, n);
        ScenarioScope<Ctx> context;
    }

    WHEN("^I command the dummy (\\d+) to say hello$") {
        ScenarioScope<Ctx> context{};
        REGEX_PARAM(size_t, ntegerType);
    }

    THEN("^the value should be \"([^\"]*)\"$") {
        ScenarioScope<Ctx> context{};
        REGEX_PARAM(std::string, hello_world_string);
    }

    THEN("^should be (.*) on the screen$") {
        REGEX_PARAM(double, expected);
        ScenarioScope<Ctx> context;

    }

}
