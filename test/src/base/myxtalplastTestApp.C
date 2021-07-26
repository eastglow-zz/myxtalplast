//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "myxtalplastTestApp.h"
#include "myxtalplastApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
myxtalplastTestApp::validParams()
{
  InputParameters params = myxtalplastApp::validParams();
  return params;
}

myxtalplastTestApp::myxtalplastTestApp(InputParameters parameters) : MooseApp(parameters)
{
  myxtalplastTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

myxtalplastTestApp::~myxtalplastTestApp() {}

void
myxtalplastTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  myxtalplastApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"myxtalplastTestApp"});
    Registry::registerActionsTo(af, {"myxtalplastTestApp"});
  }
}

void
myxtalplastTestApp::registerApps()
{
  registerApp(myxtalplastApp);
  registerApp(myxtalplastTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
myxtalplastTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  myxtalplastTestApp::registerAll(f, af, s);
}
extern "C" void
myxtalplastTestApp__registerApps()
{
  myxtalplastTestApp::registerApps();
}
