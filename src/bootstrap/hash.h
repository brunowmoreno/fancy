#ifndef _BOOTSTRAP_HASH_H
#define _BOOTSTRAP_HASH_H

namespace fancy {
  namespace bootstrap {

    void init_hash_class();

    /**
     * Hash class methods
     */
    FancyObject_p class_method_Hash_new(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope);

    /**
     * Hash instance methods
     */

    FancyObject_p method_Hash_size(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope);
    FancyObject_p method_Hash_at__put(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope);
    FancyObject_p method_Hash_at(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope);
    FancyObject_p method_Hash_keys(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope);
    FancyObject_p method_Hash_values(FancyObject_p self, FancyObject_p *args, int argc, Scope *scope);

  }
}

#endif /* _BOOTSTRAP_HASH_H */
