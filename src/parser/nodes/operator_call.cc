#include "includes.h"

namespace fancy {
  namespace parser {
    namespace nodes {

      OperatorCall::OperatorCall(Expression_p receiver,
                                 Identifier_p operator_name,
                                 Expression_p operand) :
        receiver(receiver),
        operator_name(operator_name),
        operand(operand)
      {
        assert(receiver);
        assert(operator_name);
        assert(operand);
      }

      OperatorCall::~OperatorCall()
      {
      }

      FancyObject_p OperatorCall::eval(Scope *scope)
      {
        // FancyObject_p self = scope->current_self();
        FancyObject_p args[1] = { this->operand->eval(scope) };
        FancyObject_p receiver_obj = receiver->eval(scope);
        return receiver_obj->call_method(this->operator_name->name(), args, 1, scope);
      }

      OBJ_TYPE OperatorCall::type() const
      {
        return OBJ_OPCALL;
      }

    }
  }
}
