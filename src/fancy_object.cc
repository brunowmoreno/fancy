#include "includes.h"

FancyObject::FancyObject(Class_p _class) :
  _class(_class)
{
  init_slots();
}

FancyObject::~FancyObject()
{
}

Class_p FancyObject::get_class() const
{
  return this->_class;
}

void FancyObject::set_class(Class_p klass)
{
  if(klass) {
    this->_class = klass;
    init_slots();
  }
}

FancyObject_p FancyObject::get_slot(const string &slotname) const
{
  map<string, FancyObject_p>::const_iterator it;
  it = this->slots.find(slotname);
  if(it != this->slots.end()) {
    return it->second;
  } else {
    return nil;
  }
}

FancyObject_p FancyObject::get_slot(const Identifier_p slotname) const
{
  assert(slotname);
  return this->get_slot(slotname->name());
}

void FancyObject::set_slot(const string &slotname, const FancyObject_p value)
{
  assert(value);
  this->slots[slotname] = value;
}

void FancyObject::set_slot(const Identifier_p slotname, const FancyObject_p value)
{
  assert(slotname);
  this->set_slot(slotname->name(), value);
}

void FancyObject::init_slots()
{
  if(this->_class) {
    vector<string>::iterator it;
    for(it = this->_class->instance_slotnames().begin(); 
        it != this->_class->instance_slotnames().end();
        it++){
      this->slots[*it] = nil;
    }
  }
}

FancyObject_p FancyObject::equal(const FancyObject_p other) const
{
  if(!IS_CLASSINSTANCE(other))
    return nil;
  
  FancyObject_p other_instance = dynamic_cast<FancyObject_p>(other);

  if(this->_class->equal(other_instance->_class) != nil) {
    // TODO: compare slotvalues for both instances
    return nil;
  } else {
    return nil;
  }
}

FancyObject_p FancyObject::eval(Scope *scope)
{
  return this;
}

OBJ_TYPE FancyObject::type() const
{
  return OBJ_CLASSINSTANCE;
}

string FancyObject::to_s() const
{
  return "<Unkown FancyObject>";
}

FancyObject_p FancyObject::call_method(const string &method_name, list<FancyObject_p> arguments, Scope *scope)
{
  Callable_p method = this->get_method(method_name);
  if(method) {
    return method->call(this, arguments, scope);
  } else {
    error("Method not defined: '") << method_name << "' for instance of: " << this->_class->name() << endl;
    return nil;
  }
}

void FancyObject::def_singleton_method(const string &name, Callable_p method)
{
  assert(method);
  this->_singleton_methods[name] = method;
}

bool FancyObject::responds_to(const string &method_name)
{
  if(this->get_method(method_name)) {
    return true;
  } else {
    return false;
  }
}

Callable_p FancyObject::get_method(const string &method_name)
{
  // first of all, check singleton methods
  if(this->_singleton_methods.find(method_name) != this->_singleton_methods.end()) {
    return this->_singleton_methods[method_name];
  }
  return this->_class->find_method(method_name);
}
