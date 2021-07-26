#include "myxtalplastApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
myxtalplastApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

myxtalplastApp::myxtalplastApp(InputParameters parameters) : MooseApp(parameters)
{
  myxtalplastApp::registerAll(_factory, _action_factory, _syntax);
}

myxtalplastApp::~myxtalplastApp() {}

void
myxtalplastApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"myxtalplastApp"});
  Registry::registerActionsTo(af, {"myxtalplastApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
myxtalplastApp::registerApps()
{
  registerApp(myxtalplastApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
myxtalplastApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  myxtalplastApp::registerAll(f, af, s);
}
extern "C" void
myxtalplastApp__registerApps()
{
  myxtalplastApp::registerApps();
}
