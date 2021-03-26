#include <assert.h>

#include <cstring>
#include <iostream>

#include "Error.hpp"
#include "TestCase.hpp"
#include "TestSuite.hpp"

void runTests() {
    Error errNone = Error::newNone();
    assert(errNone.getType() == ErrorType::None);
    assert(errNone.hasMessage() == false);

    Error errBuild = Error::newBuildFailed("Failed to build Homework5");
    assert(errBuild.getType() == ErrorType::BuildFailed);
    assert(errBuild.hasMessage() == true);
    assert(strcmp(errBuild.getMessage(), "Failed to build Homework5") == 0);

    TestCase testCaseNone("Passing test", errNone);
    assert(testCaseNone.getErrorType() == ErrorType::None);
    assert(testCaseNone.hasError() == false);

    TestCase testCaseFailed("Failing test", Error::newFailedAssertion("Failed on Error::getType"));
    assert(testCaseFailed.getErrorMessage() == std::string("Failed on Error::getType"));

    TestSuite suite("Suite 1");
    suite.add(testCaseNone);
    suite.add(testCaseNone);
    suite.add(testCaseFailed);
    assert(suite.filterPassing().size() == 2);
}

void runTests2() { //trqbva da napravq errorNone da moje da e s nullptr!
    Error errNone = Error::newNone();
    std::cout<<((errNone.getType() == ErrorType::None)?"da,type e none\n":"ne,type ne e none !\n");
    std::cout<<((errNone.hasMessage() == false)?"da,false,nqma msg\n" : "ne e false !\n"); //PROBLEMA E TUK

    Error errBuild = Error::newBuildFailed("Failed to build Homework5");
    std::cout<<((errBuild.getType() == ErrorType::BuildFailed)?"da,type e build failed\n":"ne,type ne e bf !\n");
    std::cout<<((errBuild.hasMessage() == true)?"da,ima msg\n":"ne,false nqma msg!\n");
    std::cout<<((strcmp(errBuild.getMessage(), "Failed to build Homework5") == 0)?"da,msgto e sushtoto\n":"ne e sushtoto msg\n");

    TestCase testCaseNone("Passing test", errNone);
    std::cout<<((testCaseNone.getErrorType() == ErrorType::None)?"da,errtype na case-a e none\n":"ne,errtype na case-a ne e none!\n");
    std::cout<<((testCaseNone.hasError() == false)?"da,dava false i nqma error\n":"ne,ne vrushta false a trqbva\n");

    TestCase testCaseFailed("Failing test", Error::newFailedAssertion("Failed on Error::getType"));
    std::cout<<((testCaseFailed.getErrorMessage() == std::string("Failed on Error::getType"))?"da,suvpadat\n":"ne suvpadat!!\n");

    TestSuite suite("Suite 1");
    suite.add(testCaseNone);
    suite.add(testCaseNone);
    suite.add(testCaseFailed);
    std::cout<<((suite.filterPassing().size() == 2)?"da, passvashtite sa 2\n":"ne,passvashtite ne gi izkarva 2-grshno!!\n");
}

int main() {
    //Error one = Error::newBuildFailed("build has failed");
    //Error one("msg", ErrorType::BuildFailed);
    //TestCase t1("test1", one);

    //std::cout << "Error one message: " << one.getMessage() << "\n ";
    //std::cout << "T1 name: " << t1.getName() << " T1 msg: " << t1.getErrorMessage() << std::endl;
    //std::cout << "T1 is passing? " << (t1.isPassing() ? "yes" : "no") << std::endl;
    //std::cout << "T1 has error? : " << (t1.hasError() ? "yes " : "no ") <<std::endl;
    runTests();
}