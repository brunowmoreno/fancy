#ifndef _CLASS_OPERATOR_DEFINITION_H_
#define _CLASS_OPERATOR_DEFINITION_H_

#include "../../expression.h"
#include "../../method.h"
#include "identifier.h"

namespace fancy {
  namespace parser {
    namespace nodes {

      class ClassOperatorDefExpr : public Expression
      {
      public:
        ClassOperatorDefExpr(Identifier* class_name, Identifier* op_name, Method* method);

        virtual EXP_TYPE type() const;
        virtual FancyObject* eval(Scope *scope);
 
      private:
        Identifier* _class_name;
        Identifier* _op_name;
        Method* _method;
      };

    }
  }
}

#endif /* _CLASS_OPERATOR_DEFINITION_H_ */
